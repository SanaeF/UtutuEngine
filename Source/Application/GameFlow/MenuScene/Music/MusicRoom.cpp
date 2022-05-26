#pragma once
#include "MusicRoom.h"
#include <iostream>
#include"../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include"../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/MenuUIImage/MenuUIImage.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/EnemyImage/EnemyImage.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/SystemProp/SceneProp.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Application/GameFlow/EndingScene/EndingScene.h"
#include "../../Source/Helper/Helper.h"
#include "../../Source/Object/Object/Object.h"
#include "../../Source/Resource/SaveData/SaveData.h"

namespace app {
	void MusicRoom::draw() {
		if (m_State == STATE::BGM) {
			lib::Graphics2D::drawRota(1920 / 2, 1440 / 2, 1.0, 0.0, res::MenuUIImage::menu_ui.title.back, true);
			lib::Graphics2D::drawRota(1920 / 2, 1440 / 2, 1.0, 0.0, res::MenuUIImage::menu_ui.musicRoom, true);
			//lib::Graphics.drawRota(1920 / 2, 1440 / 2, 1.0, 0.0, diffback[3], true);
			//lib::Graphics.drawRota(1920 / 2, 1440 / 2, 1.0, 0.0, musicroom_imf[getHorizontal()], true);
			lib::Graphics2D::drawMode(lib::DRAW_MODE::NEAREST);//線形補完描画
			int img_state = 0;
			switch (getHorizontal()) {
			case 0://title
				musicText
				(
					"タイトルのテーマです",
					"いよいよラストランです。",
					"",
					"",
					"",
					"",
					"",
					"",
					"",
					"",
					""
				);
				break;
			case 1://1rood
				musicText
				(
					"1面道中のテーマです。",
					"",
					"春に残った雪と桜の木を",
					"イメージした曲です。",
					"桜って良いよね。",
					"",
					"春なのに寒い感じがするのは、",
					"そこにいる誰かの感情とか",
					"伝わったらいいなぁ。",
					"あと、",
					"ちょっとかわいい曲だよね。"
				);
				break;
			case 2://1boss
				if (res::SaveData::save_data.clear.clear_story_num >= 1) {
					img_state = (int(m_Count / 24)) % 2;
					lib::Graphics2D::drawRota(900, 1070, 1.5f, 0 + cos(PI / 25 * m_Count) / 60, res::EnemyImage::enemy.boss[res::BOSS_TYPE::N01_MATUMI][img_state], true);
					musicText
					(
						"命あるものに魂を込められ、",
						"彼女は多重人格で苦しんだ。",
						"死後、新たに快楽を感じるのは、",
						"狂気に委ねた事にしかない。",
						"",
						"1面ボス、松御のテーマです。",
						"「日常」→「布教」→「洗脳」",
						"のような感覚で作りました。",
						"作っている間も、完成した後も",
						"ナニコレみたいな気分です。",
						"理解するのは難しいですね～。"
					);
				}
				else {
					musicText("まだクリアしていません。", "※1面をクリアしよう！",
						"", "", "", "", "", "", "", "", ""
					);
				}
				break;
			case 3://2rood
				musicText
				(
					"2面道中のテーマです。",
					"",
					"時計塔の鐘が響くような",
					"お花畑を想像していたので、",
					"このような曲になりました。",
					"",
					"ちなみに、弾いてるときは、",
					"時計の針が動く音で",
					"ノリノリでした。",
					"メトロノームすら音源に",
					"なるかもね（笑）"
				);
				break;
			case 4://2boss
				if (res::SaveData::save_data.clear.clear_story_num >= 2) {
					img_state = (int(m_Count / 60)) % 2;
					lib::Graphics2D::drawRota(900, 1070, 1.5f, 0 + cos(PI / 25 * m_Count) / 60, res::EnemyImage::enemy.boss[res::BOSS_TYPE::N02_EREMIRA][img_state * 2], true);
					musicText
					(
						"シンデレラといえばアイドル。",
						"リズム感は、ないんですよ?",
						"あ、今の無しで...。",
						"2面ボス、エレミラのテーマ。",
						"悲しい曲ってどこかカッコイイ!",
						"私、憧れます！",
						"だから、アイドルっぽい可愛",
						"らしさと邪悪なカッコ良さの",
						"化学反応を試した曲に",
						"なりました。似合うでしょ？",
						"割とお気に入りです。"
					);
				}
				else {
					musicText("まだクリアしていません。", "※2面をクリアしよう！",
						"", "", "", "", "", "", "", "", ""
					);
				}
				break;
			case 5://3rood
				musicText
				(
					"3面道中のテーマです。",
					"今回は・・・あれ？",
					"いつもの感じの曲ですねぇ。",
					"そんな気がします。",
					"道中ではアリスの事を",
					"イメージしないようにしました。",
					"1面、2面の不思議な気分から",
					"ここに来て落ち着く感じなのは",
					"あるいみ不気味ですかね？",
					"僕なりのファンタジーです。",
					"好きな方のファンタジーです。"
				);
				break;
			case 6://3boss
				if (res::SaveData::save_data.clear.clear_story_num >= 3) {
					img_state = (int(m_Count / 60)) % 2;
					lib::Graphics2D::drawRota(900, 1070, 1.5f, 0 + cos(PI / 25 * m_Count) / 60, res::EnemyImage::enemy.boss[res::BOSS_TYPE::N03_ALICE][img_state * 2], true);
					musicText
					(
						"アリス・ショット",
						"のテーマでは無いです。",
						"",
						"カードで使い魔や",
						"お友達を複製しちゃいます。",
						"この時点ではあまり語れないん",
						"だよなぁ・・・。",
						"裏表が激しそうな、気が狂った",
						"様な曲になりました。",
						"多分一番悩んだ。",
						"いかにも敵的だよね。"
					);
				}
				else {
					musicText("まだクリアしていません。", "※3面をクリアしよう！",
						"", "", "", "", "", "", "", "", ""
					);
				}
				break;
			case 7://4rood
				musicText
				(
					"4面道中です。",
					"狂気に染まった空は",
					"赤暗く",
					"下を見れば比較的新しい廃城",
					"ここは一番狂気濃度が高い",
					"実験施設の跡、危険地帯です。",
					"",
					"今回は、珍しい曲やら",
					"いつもの曲やら",
					"になりました。",
					"本当は西洋風にしたかった。"
				);

				break;
			case 8://4boss
				if (res::SaveData::save_data.clear.clear_story_num >= 4) {
					img_state = (int(m_Count / 60)) % 3;
					lib::Graphics2D::drawRota(900, 1070, 1.5f, 0 + cos(PI / 25 * m_Count) / 60, res::EnemyImage::enemy.boss[res::BOSS_TYPE::N04_NARSIRU][img_state * 2], true);
					musicText
					(
						"ナルシルのテーマです。",
						"守りたい者が居るだけで、",
						"強くなれ、戦う理由も生まれます。",
						"どんな苦難も、その人の為に",
						"戦ってきたんだと思います。",
						"",
						"ちなみに、僕は女の子じゃないので",
						"恋する乙女の気持ちなんて、",
						"少女漫画程度の理解です。",
						"今回は、そんな恋心な気分と",
						"舞台劇のような仕上がりでした。"
					);
				}
				else {
					musicText("まだクリアしていません。", "※4面をクリアしよう！",
						"", "", "", "", "", "", "", "", ""
					);
				}
				break;
			case 9://5boss
				if (res::SaveData::save_data.clear.clear_story_num >= 5) {
					img_state = (int(m_Count / 60)) % 2;
					lib::Graphics2D::drawRota(900, 1070, 1.5f, 0 + cos(PI / 25 * m_Count) / 60, res::EnemyImage::enemy.boss[res::BOSS_TYPE::N05_FEATORIA][img_state * 2], true);
					musicText
					(
						"フェアトリアのテーマです。",
						"ええ、ボス曲です。",
						"",
						"この娘にキノコを植え付けたアイツ",
						"ゼッテー許さねーからな！！",
						"とまぁ、狂限化実験に失敗した",
						"一人の被害者をイメージした",
						"曲です。",
						"マツミのメロディーが使われている",
						"と思ったそこのあなた、",
						"曲も生まれも姉が先ですからね。"
					);
				}
				else {
					musicText("まだクリアしていません。", "※5面をクリアしよう！",
						"", "", "", "", "", "", "", "", ""
					);
				}
				break;
			case 10://5rood
				musicText
				(
					"6面道中のテーマですが、",
					"霊影夜の1面道中のアレンジです。",
					"当時の感覚で作りましたよ。",
					"初心って大事らしいじゃん？",
					"(初代ラスボスの曲が4分超えてて驚愕)",
					"この後出てくる子がどっしりと",
					"待ち構えられるように、",
					"また、捜索感を強めにイメージ",
					"しました。",
					"失踪がテーマです。",
					""
				);
				break;
			case 11://6boss
				if (res::SaveData::save_data.clear.clear_story_num >= 6) {
					img_state = (int(m_Count / 60)) % 2;
					lib::Graphics2D::drawRota(900, 1070, 1.5f, 0 + cos(PI / 25 * m_Count) / 60, res::EnemyImage::enemy.boss[res::BOSS_TYPE::N06_SHIENA][img_state * 2], true);
					musicText
					(
						"シエナのテーマです。",
						"強引な再会とメンヘラな赤ずきん",
						"をイメージしたような曲です。",
						"",
						"どこか物悲しさが入っているのは",
						"やっぱり寂しかったんだろうなと",
						"思わせますね。",
						"メルヘンチックで明るい赤ずきん",
						"もいいけど、欲むき出しでドス黒い",
						"メンヘラ赤ずきんも良いなぁって、",
						"今作はそんなテーマでした。"
					);
				}
				else {
					musicText("ストーリーをクリアしよう！", "※ガンバレ",
						"", "", "", "", "", "", "", "", ""
					);
				}
				break;
			case 12://7boss
				if (res::SaveData::save_data.clear.clear_story_num >= 7) {
					lib::Graphics2D::drawRota(900, 1070, 1.5f, 0 + cos(PI / 25 * m_Count) / 60, res::EnemyImage::enemy.boss[res::BOSS_TYPE::N07_ALICE][0], true);
					musicText
					(
						"アリスモード7面のテーマです。",
						"アリス向けに作りました。",
						"順番的にこれが一番最後に作った",
						"曲なんですよねぇ。",
						"ぶっちゃけ、どんな曲にしようか",
						"まったく思い付か無くて、",
						"終始疑心暗鬼になりながら音を",
						"鳴らしていました。",
						"そう、いつの間にかこんな曲が",
						"出来ていたのです！",
						"コビトさんが作ってくれたのかな。"
					);
				}
				else {
					musicText("アリスモードLv.10以上で出現する", "7面をクリアしよう",
						"", "", "", "", "", "", "", "", ""
					);
				}
				break;
			case 13://Ex rood
				musicText
				(
					"エキストラ道中のテーマです。",
					"曲案を3パターン考えていたので",
					"ドレで行こうか悩みましたし、",
					"エキストラって本編じゃないから",
					"気分で作って良いんじゃね？って",
					"ことで、色々迷いました。",
					"憑媒虚界でこの曲だしたら",
					"激アツじゃね？って思ってた奴です。",
					"",
					"戦わないという運命からハズされた",
					"二人の少女みたいな感じがする。"
				);
				break;
			case 14://Ex boss
				if (res::SaveData::save_data.clear.difficulty[3]) {
					img_state = (int(m_Count / 60)) % 2;
					lib::Graphics2D::drawRota(900, 1070, 1.5f, 0 + cos(PI / 25 * m_Count) / 60, res::EnemyImage::enemy.boss[res::BOSS_TYPE::N08_KURO][img_state * 2], true);
					musicText
					(
						"エキストラボスのテーマです。",
						"ちょっと怖いかなぁ？",
						"怪獣のような雰囲気をイメージ",
						"しました。",
						"事実上、ここで戦うのは",
						"諸悪の根源なので、",
						"ラストに相応しく威厳を感じる",
						"曲に仕上げています。",
						"後半でいつも通りな曲調に",
						"なるから、暗い雰囲気を緩和",
						"できると思いますよ。"
					);
				}
				else {
					musicText("エキストラをクリアしよう！", "※ガンバレ",
						"", "", "", "", "", "", "", "", ""
					);
				}
				break;
			case 15://ED
				if (res::SaveData::save_data.clear.clear_story_num >= 6) {
					musicText
					(
						"エンディングです。",
						"それ用のアニメを作って",
						"いたんですが、初期版では",
						"未完成で出す事になって",
						"しまいました。トホホ",
						"",
						"",
						"",
						"++★☆<<  またね。>>☆★++",
						"",
						""
					);
				}
				else {
					musicText("ストーリーをクリアしよう！", "※ガンバレ",
						"", "", "", "", "", "", "", "", ""
					);
				}
				break;
			case 16://AL
				musicText
				(
					"初めまして、ALと申します。",
					"このゲームの製作者に頼まれ、",
					"別のゲームに使われる予定",
					"だった曲です。",
					"このゲームはこれで最終作の",
					"予定ですが、作品が本当に",
					"終わりを迎えるのは、",
					"誰も作品を創らなくなった",
					"時です。ですから皆さん",
					"作品を創りましょう。",
					"レッツクリエイト！"
				);
				break;
			default:
				break;
			}
			for (int i = 0; i < m_BGM_max; i++) {
				if (i == getHorizontal()) {
					lib::StringDX::draw(
						460 * 4 - m_Music_name[0].x - 60,
						m_Music_name[0].y,
						Sound::sound.m_Title[i].name,
						lib::StringDX::color(255, 255, 255),
						res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
					);
				}
				else {
					lib::StringDX::draw(
						460 * 4 - m_Music_name[1 + ((m_BGM_max - 1) - getHorizontal() + i) % m_BGM_max].x,
						m_Music_name[1 + ((m_BGM_max - 1) - getHorizontal() + i) % m_BGM_max].y,
						Sound::sound.m_Title[i].name,
						lib::StringDX::color(133, 133, 133),
						res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
					);
				}
			}
		}
		if (m_State == STATE::MOVIE) {
			m_Ending->draw();
		}
	}

	int MusicRoom::update() {
		setSceneState(SCENE_TYPE::MUSIC);
		if (sceneCoolDown(10)) {
			if (m_State == STATE::BGM) {
				up(m_BGM_max);
				down(m_BGM_max);
				select();
				cancel();
			}
			if (m_State == STATE::MOVIE) {
				m_Ending->update();
				if (m_Ending->isEnded()) {
					m_State = STATE::BGM;
					Sound::sound.unFreez();
				}
			}
			m_Count++;
		}
		else {
			m_State = STATE::BGM;
		}
		return getSceneState();
	}

	void MusicRoom::select() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::SHOT) == 1) {
			Sound::sound.playSE(res::SE::SELECT_OK);
			if (getHorizontal() == 15) {
				Sound::sound.freez();
				m_Ending->setEnding();
				m_State = STATE::MOVIE;
			}
			else {
				Sound::sound.playBGM(getHorizontal());
			}
			m_Count = 0;
		}
	}

	void MusicRoom::cancel() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::BOM) == 1 || Key::Pad.checkInput(Key::KEY_TYPE::MENU) == 1) {
			Sound::sound.playSE(res::SE::SELECT_CANCEL);
			Sound::sound.playBGM(0);
			resetCoolDown();
			setSceneState(SCENE_TYPE::TITLE);
		}

	}

	void MusicRoom::musicText(
		const char* msg0,
		const char* msg1,
		const char* msg2,
		const char* msg3,
		const char* msg4,
		const char* msg5,
		const char* msg6,
		const char* msg7,
		const char* msg8,
		const char* msg9,
		const char* msg10
	) {
		lib::StringDX::draw(30, 725, msg0, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(30, 775, msg1, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(30, 825, msg2, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(30, 875, msg3, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(30, 925, msg4, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(30, 975, msg5, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(30, 1025, msg6, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(30, 1075, msg7, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(30, 1125, msg8, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(30, 1175, msg9, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(30, 1225, msg10, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
	}
	MusicRoom::MusicRoom() {
		m_Count = 0;
		m_Ending.reset(new EndingScene());
	}
}