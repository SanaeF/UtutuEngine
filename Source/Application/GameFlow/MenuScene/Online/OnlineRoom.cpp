#include "OnlineRoom.h"
#include <iostream>

#include"../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include"../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/GUI/MenuUIImage/MenuUIImage.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/SystemProp/SceneProp.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/Application/Sound/Sound.h"

namespace app {
    void Online::draw() {
        lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.title.back, true);
        lib::Graphics2D::draw(0, 0, res::MenuUIImage::menu_ui.gray_box[2], true);
        drawNone();
        drawIP();
        drawPort();
    }
    void Online::drawNone() {
        if (!isState(oSTATE::NONE))return;
        MenuText m_Title_gui[2] = {//二次創作
            { 600, 600, "接続されちゃう!" },
            { 600, 750, "接続しちゃうんだから！" },
        };
        for (int i = 0; i < 2; i++) { // メニュー項目を描画
            if (i == getHorizontal()) {
                lib::StringDX::draw(
                    m_Title_gui[i].x - 20 * 2,
                    m_Title_gui[i].y,
                    m_Title_gui[i].name,
                    lib::StringDX::color(233, 233, 233),
                    res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
                );
            }
            else {
                lib::StringDX::draw(
                    m_Title_gui[i].x,
                    m_Title_gui[i].y, 
                    m_Title_gui[i].name,
                    lib::StringDX::color(100, 100, 100),
                    res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
                );
            }
        }
    }
    void Online::drawIP() {
        if (!isState(oSTATE::IP_CONNECTER))return;
        lib::Graphics2D::draw(0, 0, res::MenuUIImage::menu_ui.gray_box[3], true);
        const int PosX = 750;
        const int PosX2 = 1020;
        const int TextPosX = 550;
        const int TextPosY = 650;
        lib::StringDX::draw(
            TextPosX,
            TextPosY,
            "接続するIPアドレスを設定",
            lib::StringDX::color(233, 233, 233),
            res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
        );
        int num = m_Info.ip[0];
        for (int ii = 0; ii < 3; ii++) {//ポイント
            int addY = 0;
            if (ii == 2 - getVertical())addY = 5;
            lib::Graphics2D::drawRota(PosX + 100 - (14 * ii) * 2, 460 * 2 - addY, 0.8f, 0.0f, res::TextUIImage::text_ui.number[0][num % 10], true);
            num /= 10;
        }
        num = m_Info.ip[1];
        for (int ii = 0; ii < 3; ii++) {//ポイント表示
            int addY = 0;
            if (ii == 2 - getVertical() + 3)addY = 5;
            lib::Graphics2D::drawRota(PosX + 200 - (14 * ii) * 2, 460 * 2 - addY, 0.8f, 0.0f, res::TextUIImage::text_ui.number[0][num % 10], true);
            num /= 10;
        }
        num = m_Info.ip[2];
        for (int ii = 0; ii < 3; ii++) {//ポイント表示
            int addY = 0;
            if (ii == 2 - getVertical() + 6)addY = 5;
            lib::Graphics2D::drawRota(PosX + 300 - (14 * ii) * 2, 460 * 2 - addY, 0.8f, 0.0f, res::TextUIImage::text_ui.number[0][num % 10], true);
            num /= 10;
        }
        num = m_Info.ip[3];
        for (int ii = 0; ii < 3; ii++) {//ポイント表示
            int addY = 0;
            if (ii == 2 - getVertical() + 9)addY = 5;
            lib::Graphics2D::drawRota(PosX + 400 - (14 * ii) * 2, 460 * 2 - addY, 0.8f, 0.0f, res::TextUIImage::text_ui.number[0][num % 10], true);
            num /= 10;
        }
    }
    void Online::drawPort() {
        if (!isState(oSTATE::PORT_HOST) && !isState(oSTATE::PORT_CONNECTER))return;
        lib::Graphics2D::draw(0, 0, res::MenuUIImage::menu_ui.gray_box[3], true);
        const int PosX = 750;
        const int PosX2 = 1020;
        const int TextPosX = 550;
        const int TextPosY = 650;
        if (isState(oSTATE::PORT_HOST)) {
            lib::StringDX::draw(
                TextPosX - 20,
                TextPosY,
                "ポート番号を決めてください",
                lib::StringDX::color(233, 233, 233),
                res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
            );
        }
        if (isState(oSTATE::PORT_CONNECTER)) {
            lib::StringDX::draw(
                TextPosX - 20,
                TextPosY,
                "接続するポート番号を設定",
                lib::StringDX::color(233, 233, 233),
                res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
            );
        }
        int num = m_Info.port;
        for (int ii = 0; ii < 5; ii++) {//ポイント表示
            int addY = 0;
            if (ii == 4 - getVertical())addY = 5;
            lib::Graphics2D::drawRota(PosX2 - (14 * ii) * 2, 460 * 2 - addY, 0.8f, 0.0f, res::TextUIImage::text_ui.number[0][num % 10], true);
            num /= 10;
        }
    }
    int Online::update() {
        if (sceneCoolDown(10)) {
            if (isState(oSTATE::NONE)) {
                up(2);
                down(2);
            }
            if (isState(oSTATE::IP_CONNECTER)) {
                up_num();
                down_num();
                right(12);
                left(12);

                m_IP_num[getVertical()] += getHorizontal();
                m_IP_num[getVertical()] = m_IP_num[getVertical()] % 10;
                setHorizontal(0);
                m_Info.ip[0] = (m_IP_num[0] * 100)
                    + (m_IP_num[1] * 10)
                    + (m_IP_num[2] * 1);
                for (int i = 0; i < 4; i++) {
                    m_Info.ip[i] = (m_IP_num[0 + 3 * i] * 100)
                        + (m_IP_num[1 + 3 * i] * 10)
                        + (m_IP_num[2 + 3 * i] * 1);
                }
            }
            if (isState(oSTATE::PORT_HOST) || isState(oSTATE::PORT_CONNECTER)) {
                up_num();
                down_num();
                right(5);
                left(5);

                m_Port_num[getVertical()] += getHorizontal();
                m_Port_num[getVertical()] = m_Port_num[getVertical()] % 10;
                setHorizontal(0);

                m_Info.port = (m_Port_num[0] * 10000)
                    + (m_Port_num[1] * 1000)
                    + (m_Port_num[2] * 100)
                    + (m_Port_num[3] * 10)
                    + (m_Port_num[4] * 1);
            }
            select();
            cancel();
            //if(mServer.getConnecting())setSceneState(SCENE::CharaSelect);
        }
        else {
            m_State = 0;
            m_Server.clearValue();
            setSceneState(SCENE_TYPE::SERVER_ROOM);
        }
        return getSceneState();
    }
    void Online::serverProp() {
        if (isState(oSTATE::HOST_INIT)) {
            m_Server.initHost(m_Info.port);
            m_Server.setState(DuelServer::Host);
            m_State = oSTATE::ON_HOST;
        }
        if (isState(oSTATE::CONNECTER_INIT)) {
            m_Server.initConnect(m_Info.ip[0], m_Info.ip[1], m_Info.ip[2], m_Info.ip[3], m_Info.port);
            m_Server.setState(DuelServer::Connecter);
            m_State = oSTATE::ON_CONNECTER;
        }
    }
    void Online::select() {
        if (Key::Pad.checkInput(Key::KEY_TYPE::SHOT) == 1) {
            Sound::sound.playSE(res::SE::SELECT_OK);
            if (isState(oSTATE::NONE)) {
                if (getHorizontal() == 0)m_State = oSTATE::PORT_HOST;
                if (getHorizontal() == 1)m_State = oSTATE::IP_CONNECTER;
                return;
            }
            if (isState(oSTATE::PORT_HOST)) {
                m_State = oSTATE::HOST_INIT;
                return;
            }
            if (isState(oSTATE::IP_CONNECTER)) {
                m_State = oSTATE::PORT_CONNECTER;
                return;
            }
            if (isState(oSTATE::PORT_CONNECTER)) {
                m_State = oSTATE::CONNECTER_INIT;
                return;
            }
        }
    }
    void Online::cancel() {
        if (Key::Pad.checkInput(Key::KEY_TYPE::BOM) == 1||
            Key::Pad.checkInput(Key::KEY_TYPE::MENU) == 1) {
            Sound::sound.playSE(res::SE::SELECT_CANCEL);
            if (isState(oSTATE::NONE)) {
                setSceneState(SCENE_TYPE::TITLE);
                resetCoolDown();
                return;
            }
            if (isState(oSTATE::PORT_HOST)) {
                m_State = oSTATE::NONE;
                return;
            }
            if (isState(oSTATE::IP_CONNECTER)) {
                m_State = oSTATE::NONE;
                return;
            }
            if (isState(oSTATE::PORT_CONNECTER)) {
                m_State = oSTATE::IP_CONNECTER;
                return;
            }
        }
    }
    void Online::up_num() {
        if (Key::Pad.checkInput(Key::KEY_TYPE::UP) == 1) {
            Sound::sound.playSE(res::SE::SELECT);
            setHorizontal(1);
        }
    }
    void Online::down_num() {
        if (Key::Pad.checkInput(Key::KEY_TYPE::DOWN) == 1) {
            Sound::sound.playSE(res::SE::SELECT);
            setHorizontal(9);
        }
    }
    bool Online::isHost() {
        bool flag = false;
        if (m_State == oSTATE::ON_HOST)flag = true;
        return flag;
    }
    bool Online::isState(int state) {
        if (m_State == state)return true;
        return false;
    }
    DuelServer& Online::getServer() {
        return m_Server;
    }
    Online::Info_t 
        Online::m_Input_info() {
        return m_Info;
    }
}