dofile( './dat/Script/Library/Talker/Library.lua' )
--3面中ボスの会話

function TalkScene()

AYANO = 0
HIME = 1
ID_MAX = HIME

Scene(0)
SummonInterBoss(N03_EREMIRA, 1)
Chara.create_ID(ID_MAX)
Massage.setBoxL()
Chara.spawn(HIME, 3, 200, 1000, 0.4)--キャラの立ち絵を追加
Chara.eye(HIME, 1)
Chara.mouth(HIME, 1)
Chara.spawnFacial(HIME, ACCENT, 80, 670)
SimpleMassage(
name_("媛"),
"まだ何か用ですか？",
"",
""
)
Scene(1)
Chara.spawnFacial(HIME, STOP, 0, 0)
Chara.brow(HIME, 1)
Chara.eye(HIME, 1)
Chara.mouth(HIME, 0)
SimpleMassage(
name_("媛"),
"・・・？",
"",
""
)
Scene(2)
Chara.isBack(HIME, true)
Chara.spawn(AYANO, 0, 400, 1000, 0.4)--キャラの立ち絵を追加
Chara.brow(AYANO, 1)
Chara.eye(AYANO, 3)
Chara.mouth(AYANO, 1)
Chara.spawnFacial(AYANO, SWEAT, -100, 600)
SimpleMassage(
name_("綾乃"),
"アレ？聞こえてないのかな？",
"",
""
)

end

--@EndScript