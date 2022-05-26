#include "Player.h"
#include <iostream>
#include <cassert>
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/Resource/PlayerImage/PlayerImage.h"
#include "../../Source/SystemProp/GameStatsProp.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/Application/Replayer/Replayer.h"
#include "../../Source/Object/Player/Bom/Bom_Info.h"
#include "../../Source/Object/Player/Shot/OptionManager.h"
#include "../../Source/Object/Boss/Boss.h"
#include "../../Source/Object/Minion/Minion.h"
#include "../../Source/Object/Effect/Effect.h"
#include "../../Source/Helper/Helper.h"
#include "../../Source/SystemProp/AliceProp/AliceProp.h"
#include "../../Source/SystemProp/GameSceneProp/GameSceneProp.h"
#include "../../Source/Resource/SaveData/SaveData.h"

namespace obj {
	Player Player::PlayerObj;
	Player Player::PlayersObj[2];
	Player::Player()
	{
		m_Bom.reset(new Bom_Info());
		m_Effect.reset(new Effect());
	}
	void Player::initialize(int type, int max_x, int min_x, bool m_Is_vs_mode) {
		//一番最初にする初期化
		m_Item.initialize();
		loadState(type);
		this->m_Is_vs_mode = m_Is_vs_mode;
		m_Mover.initialize(max_x, min_x);
		m_Field.m_Max_x = max_x;
		m_Field.m_Min_x = min_x;
		m_Is_hide = false;
	}
	void Player::initOption() {
		OptionManager::Shot.initialize(m_Field.m_Max_x, m_Field.m_Min_x);
	}
	void Player::loadState(int type) {
		//ステージ移行で絶対に初期化するもの
		m_Item.chapterInit();
		setState(STATE::NONE);
		setStateSub(STATE::NONE);
		setX(DEF_PLAYER_X);
		setY(DEF_PLAYER_Y);
		setType(type);
		if (app::Replayer::GameRecorder.isReplayMode()) {
			setType(app::Replayer::GameRecorder.getPlayerData(0));
		}
		else app::Replayer::GameRecorder.setPlayerData(type, 0);
		m_Draw_bright = 255;
		m_Is_damage = false;
		if(!m_Is_vs_mode)m_Is_bom = false;
		if (m_Is_vs_mode) {
			m_Item.initDuel();
		}
		m_Invincible_count = 0;
		m_Graze_count = 0;
		m_Is_no_shoot = false;
	}

	void Player::draw(double crush_x, double crush_y) {
		if (m_Is_hide)return;
		lib::Graphics2D::setBright(m_Draw_bright, m_Draw_bright, m_Draw_bright);
		OptionManager::Shot.draw(crush_x, crush_y);
		if (m_Invincible_count % 2 == 0) {
			lib::Graphics2D::drawRota(
				getX() + m_Field.m_Min_x + crush_x,
				getY() + FMIN_Y + crush_y + 30,
				1.0f,
				0.0f,
				res::PlayerImage::Player.type[getType()][m_Image_state],
				true
			);
		}
		lib::Graphics2D::setBright(255, 255, 255);
		if (m_Effect->isFlag())m_Effect->draw(m_Field);
	}
	void Player::update() {
		if (m_Is_damage == true) {
			damageUpdate();
			invincibleUpdate();
		}
		bomUpdate();
		setCount(getCount() + 1);
		if (!m_Is_bom)m_Image_state = (getCount() / 6) % 4 + m_Mover.getImageState();
		if (m_Is_bom)m_Image_state = (getCount() / 2) % 4 + m_Mover.getImageState();
		moveUpdate();
		if (m_Is_vs_mode)keyInputUpdate();
		if (m_Is_hide)return;
		shootUpdate();
		m_Item.update(getRayer());
		if (m_Graze_count > 10) {
			m_Graze_count = 0;
			m_Is_graze = false;
		}
		else m_Graze_count++;
		app::Replayer::GameRecorder.setScore(m_Item.score);
	}
	void Player::drawHitbox() {
		//あたり判定の描画
		if (m_Is_hide)return;
		if (m_Mover.isSlow()) {
			lib::Graphics2D::drawRota(
				getX() + m_Field.m_Min_x,
				getY() + FMIN_Y,
				2.0f,
				2.0 * PI * (getCount() % 120) / 120,
				res::PlayerImage::Player.hitbox,
				true
			);
		}
	}
	void Player::damage() {
		//ダメージ処理(残機やその他のパラメーターにペナルティ)
		if ((getState() == STATE::NONE &&
			getStateSub() == STATE::NONE) &&
			m_Is_damage == false
			) {
			m_Effect->setX(getX());
			m_Effect->setY(getY());
			m_Effect->setType(Effect::PLAYER_DEATH);
			m_Effect->setFlag(true);
			m_After_life = m_Item.life - 1;
			m_After_power = m_Item.power - 25;
			if (GameSceneProp::under_wear == 4 && (m_Item.power >= 350 && m_After_power < 350)) {
				m_After_power = m_Item.power;
			}
			this->m_Is_damage = true;
			m_Draw_bright = 150;//暗く
			setCount(0);
		}
	}
	void Player::damageUpdate() {
		//喰らいボムの判定処理
		if (getCount() < 20)return;
		if ((getState() == STATE::NONE && getStateSub() == STATE::NONE)) {
			if (m_Item.bom < PLAYER_STATES::BOM)m_Item.bom = PLAYER_STATES::BOM;
			m_Item.life = m_After_life;
			m_Item.power = m_After_power;
			setX(DEF_PLAYER_X);
			setY(FMAX_Y - FMIN_Y - 60);
			setCount(0);
			m_Draw_bright = 255;
			setState(STATE::DAMAGE);
			setStateSub(STATE::INVINCIBLE);
			OptionManager::Shot.clear();
		}
	}
	void Player::moveUpdate() {
		//移動
		m_Mover.setBomFlag(m_Is_bom);
		auto Pos = m_Mover.inputPos(getType(), getX(), getY());
		setX(Pos.x);
		setY(Pos.y);
		if (getState() == STATE::DAMAGE && !m_Mover.isDamageMove())setState(STATE::NONE);
	}
	void Player::invincibleUpdate() {
		//ダメージ時の点滅処理
		if (getStateSub() == STATE::INVINCIBLE)m_Invincible_count++;
		if (m_Invincible_count > INVINCIBLE_COUNT) {
			m_Invincible_count = 0;//戻す
			m_Is_damage = false;
			setStateSub(STATE::NONE);
		}
	}
	void Player::bomUpdate() {
		if (m_Is_no_shoot)return;
		//ボムを発動したら
		if (m_Is_bom == true) {
			int type = getType();
			m_Bom->update(getX(), getY(), type, m_Is_damage);
			if (!m_Bom->isNoDamage())setState(STATE::NONE);
			//ボムが終わったかどうかを判定
			if (m_Bom->isEndTime()) {
				m_Is_bom = false;
				m_Invincible_count = 0;//戻す
				setState(STATE::NONE);
			}
			//if (getType() == resource::PlayerType::IORIKO) {
			//	setState(STATE::NONE);
			//	if (mBom->isEndTime()) {
			//		bom_flag = false;
			//		invincible_cnt = 0;//戻す
			//		setState(STATE::NONE);
			//	}
			//}
		}
		else {
			if (getState() == STATE::NONE && getStateSub() == STATE::NONE) {
				//ボムを発動する
				if (m_Item.bom > 0 && getKey(app::Key::KEY_TYPE::BOM) == 1) {
					m_Is_bom = true;
					m_Item.bom--;
					if (AliceProp::flag) {
						if (res::SaveData::save_data.weapon[AliceProp::weapon_type].ex_type == 2) {
							if(GET_RANDOM(100)%100<25)m_Item.bom++;
						}
					}
					if (GameSceneProp::under_wear == 5) {
						m_Item.apple = 3;
						m_Is_bom = false;
						return;
					}
					m_Bom->initialize();
					this->m_Is_damage = false;
					m_Draw_bright = 255;
					setState(STATE::INVINCIBLE);
				}
			}
		}

	}
	void Player::shootUpdate() {
		if (m_Is_no_shoot) {
			OptionManager::Shot.clear(false);
			return;
		}
		//ショットを打つ
		int type = getType();
		bool shoot = isKeyIn(app::Key::KEY_TYPE::SHOT);
		bool shift = isSlow();
		//if (m_Is_connecting)if (m_Key_input_data[0] > 0)shoot = true;
		//if (m_Is_vs_mode)type = -1;
		OptionManager::Shot.update(getX(), getY(), shoot);
		OptionManager::Shot.pattern(type, shift, isBom());
	}
	void Player::keyInputUpdate() {
		//プレイヤーの操作をデータで送信する時用
		if (PAD_TYPE == PAD_TYPE::NONEP)return;
		for (int i = 0; i < 3; i++) {
			if (m_Key_input_data[i] > 0 &&
				m_Key_input_data[i] < 30) {
				m_Key_input_data[i]++;
			}
			if (m_Key_input_data[i] >= 30) {
				m_Key_input_data[i] = 0;
			}
		}
		if (isKeyIn(app::Key::KEY_TYPE::SHOT) && m_Key_input_data[0] == 0)m_Key_input_data[0] = 1;
		if (isKeyIn(app::Key::KEY_TYPE::BOM) && m_Key_input_data[1] == 0)m_Key_input_data[1] = 1;
		if (isKeyIn(app::Key::KEY_TYPE::CHANGE) && m_Key_input_data[2] == 0)m_Key_input_data[2] = 1;
	}
	void Player::setKeyPad(int type) {
		m_Mover.setKeyPad(type);
		PAD_TYPE = type;
	}
	void Player::setBomFlag(bool flag) {
		this->m_Is_bom = flag;
	}
	void Player::setHide() {
		m_Is_hide = true;
	}
	void Player::setRoulette(bool flag) {
		m_Is_roulette = flag;
	}
	void Player::setIsGraze(bool flag) {
		m_Is_graze = flag;
	}
	void Player::setServerInputData(
		int state,int m_Is_bom,
		int life_num,int bom_num,
		int img,int m_Slow,int knd,
		int shot_bullet[3],
		float x, float y
	) {
		m_Is_connecting = true;
		setState(state);
		setBomFlag(m_Is_bom);
		m_Item.life = life_num;
		m_Item.bom = bom_num;
		m_Mover.setImageState(img);
		m_Mover.setSlow(m_Slow);
		setType(knd);
		m_Key_input_data[0] = shot_bullet[0];
		m_Key_input_data[1] = shot_bullet[1];
		m_Key_input_data[2] = shot_bullet[2];
		setX(x);
		setY(y);
	}
	void Player::setNoShoot(bool flag) {
		m_Is_no_shoot = flag;
	}
	int Player::getKeyInputData(int num) {
		return m_Key_input_data[num];
	}
	int Player::getKey(int num) {
		if (app::Replayer::GameRecorder.isReplayMode()) {
			return app::Replayer::GameRecorder.getKeyData(num);
		}
		else {
			if (PAD_TYPE == 0) {
				if (app::Key::Pad.checkInput(num) > 0) {
					int a = 0;
				}
				app::Replayer::GameRecorder.pushBackKeyInputs(num, app::Key::Pad.checkInput(num));
				return app::Key::Pad.checkInput(num);
			}
			if (PAD_TYPE == 1)return app::Key::MultPad[0].checkInput(num);
			if (PAD_TYPE == 2)return app::Key::MultPad[1].checkInput(num);
		}
		return 0;
	}
	int Player::getImgState() {
		return m_Mover.getImageState();
	}
	int Player::getHitRange() {
		int size = 4;
		if (GameSceneProp::under_wear == 3)size = 2;
		return size;
	}
	bool Player::isBom() {
		return this->m_Is_bom;
	}
	bool Player::isHideMode() {
		return m_Is_hide;
	}
	bool Player::isKeyIn(int num) {
		if (PAD_TYPE == 0) {
			if (app::Replayer::GameRecorder.isReplayMode()) {
				if(app::Replayer::GameRecorder.getKeyData(num) != 0)return true;
			}
			else {
				app::Replayer::GameRecorder.pushBackKeyInputs(num, app::Key::Pad.checkInput(num));
				if (app::Key::Pad.checkInput(num) != 0) {
					return true;
				}
			}
		}
		if ((PAD_TYPE == 1 && app::Key::MultPad[0].checkInput(num) != 0) ||
			(PAD_TYPE == 2 && app::Key::MultPad[1].checkInput(num) != 0)
			)return true;
		return false;
	}
	bool Player::isSlow() {
		return m_Mover.isSlow();
	}
	bool Player::isDamageNow() {
		return m_Is_damage;
	}
	bool Player::isRoulette() {
		return m_Is_roulette;
	}
	bool Player::isGraze() {
		return m_Is_graze;
	}
	PlayerShot& 
	Player::getShot(int num) {
		return OptionManager::Shot.getShot()[num];
	}
	ItemStack&
	Player::getItemStack() {
		return m_Item;
	}
	Player::~Player() {
	}
}