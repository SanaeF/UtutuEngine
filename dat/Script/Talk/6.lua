dofile( './dat/Script/Library/Talker/Library.lua' )
--3面弾幕終了後の会話

function TalkScene()

AYANO = 0
HIME = 1
ALICE = 2
ID_MAX = ALICE

Scene(0)
Chara.create_ID(ID_MAX)
Chara.spawn(id_(AYANO), 0, 250, 1000, 0.4)--キャラの立ち絵を追加
Chara.isBack(AYANO,true)
Chara.eye(AYANO, 1)
Chara.mouth(AYANO, 0)
Chara.spawn(ALICE, 7, 1100, 1000, 0.4)--キャラの立ち絵を追加
Chara.eye(ALICE, 1)
Chara.mouth(ALICE, 1)
Chara.body(ALICE,1)
Massage.setBoxR()
SimpleMassage(
name_("アリス・ショット(略)"),
"なかなかやるねぇ",
"",
""
)
Scene(1)
SimpleMassage(
name_("アリス・ショット(略)"),
"なかなかやるねぇ",
"でも君たちが来るべき場所は",
"まだココじゃないよ。"
)
Scene(2)
SimpleMassage(
name_("アリス・ショット(略)"),
"じゃぁね",
"",
""
)

end

--@EndScript