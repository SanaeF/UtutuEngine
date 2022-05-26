dofile( './dat/Script/Library/Talker/Library.lua' )
--2面弾幕前の会話

function TalkScene()

AYANO = 0
AKAGI = 1
HIME = 2
EREMIRA = 3
ID_MAX = EREMIRA

Scene(0)
Chara.create_ID(ID_MAX)
Massage.setBoxL()
Chara.spawn(AYANO, 0, 250, 1000, 0.4)--キャラの立ち絵を追加
Chara.eye(AYANO, 1)
Chara.mouth(AYANO, 0)
Chara.isBack(AYANO,true)
Chara.spawn(AKAGI, 2, 400, 1000, 0.4)--キャラの立ち絵を追加
Chara.brow(AYANO, 0)
Chara.eye(AKAGI, 1)
Chara.mouth(AKAGI, 1)
SimpleMassage(
name_("赤城"),
"そろそろ日付が変わりそう。",
"",
""
)
Scene(1)
Chara.brow(AYANO, 1)
SimpleMassage(
name_("赤城"),
"そろそろ日付が変わりそう。",
"急がなきゃ！",
""
)
Scene(2)
Chara.mouth(AKAGI, 0)
Chara.isBack(AKAGI,true)
Massage.setBoxR()
SimpleMassage(
name_("???"),
"ちょっと待った！",
"",
""
)
Scene(3)
SummonBoss(N02_EREMIRA, 6)--ボス召喚
WaitAndSkip(60)
Scene(4)
Chara.spawn(EREMIRA, 6, 1100, 800, 0.4)--キャラの立ち絵を追加
Chara.eye(EREMIRA, 1)
Chara.brow(EREMIRA, 2)
Chara.mouth(EREMIRA, 1)
Chara.spawnFacial(EREMIRA, ANGRY, 250, 480)
Massage.setBoxR()
SimpleMassage(
name_("???"),
"ちょっと待った！",
"あなた達、非狂気勢ね？",
""
)
Scene(5)
Chara.isBack(AYANO,false)
Chara.isBack(EREMIRA,true)
Chara.brow(AYANO, 1)
Chara.mouth(AYANO, 1)
Chara.mouth(EREMIRA, 0)
Massage.setBoxL()
SimpleMassage(
name_("綾乃"),
"何それ知らない。どう言う事？",
"",
""
)
Scene(6)
Chara.isBack(AYANO,true)
Chara.mouth(AYANO, 0)
SimpleMassage(
name_("「まにわ」"),
"虚界の中には、現世に戻りたい",
"っていう意見も聞きますねぇ。",
"狂気的な団体の事だと思う"
)
Scene(7)
Chara.brow(EREMIRA, 0)
SimpleMassage(
name_("「まにわ」"),
"てか多分それ☆",
"",
""
)
Scene(8)
Chara.isBack(EREMIRA,false)
Chara.mouth(EREMIRA, 1)
Chara.brow(EREMIRA, 1)
Chara.spawnFacial(EREMIRA, ACCENT, 220, 550)
Massage.setBoxR()
SimpleMassage(
name_("???"),
"あれ？そもそも",
"この子達、虚界の民じゃない？",
""
)
Scene(9)
Chara.spawnFacial(EREMIRA, SWEAT, 200, 480)
SimpleMassage(
name_("???"),
"あれ？そもそも",
"この子達、虚界の民じゃない？",
"なんか悪いなぁ・・・。"
)
Scene(10)
Chara.brow(EREMIRA, 0)
Chara.eye(EREMIRA, 3)
Chara.spawnFacial(EREMIRA, HAPPY, 150, 380)
SimpleMassage(
name_("???"),
"じゃぁイイや！(適当)",
"私のライブに招待してあげる！",
""
)
Scene(11)
Chara.isBack(AKAGI,false)
Chara.mouth(AKAGI, 1)
Chara.isBack(EREMIRA,true)
Chara.eye(EREMIRA, 0)
Chara.mouth(EREMIRA, 0)
Massage.setBoxL()
SimpleMassage(
name_("赤城"),
"え、もしかしてアイドル？",
"",
""
)
Scene(12)
Chara.hide(AKAGI)
Chara.spawn(HIME, 3, 400, 1070, 0.47)
Chara.eye(HIME, 1)
Chara.brow(HIME, 1)
Chara.mouth(HIME, 1)
SimpleMassage(
name_("媛"),
"覚えてないと思うんだけど、",
"なぜか見たことある気が...",
""
)
Scene(13)
Chara.isBack(EREMIRA,false)
Chara.isBack(HIME,true)
Chara.eye(EREMIRA, 1)
Chara.brow(EREMIRA, 1)
Chara.mouth(EREMIRA, 1)
Chara.mouth(HIME, 0)
Chara.spawnFacial(EREMIRA, STOP, 0, 0)
Massage.setBoxR()
SimpleMassage(
name_("???"),
"そっか、切ないね・・・。",
"",
""
)
Scene(14)
Chara.brow(EREMIRA, 0)
SimpleMassage(
name_("???"),
"私の名前はエレミラ！",
"",
""
)
Scene(15)
SimpleMassage(
name_("エレミラ"),
"私の名前はエレミラ！",
"よろしくね！",
""
)
Scene(16)
Chara.body(EREMIRA,2)
SimpleMassage(
name_("エレミラ"),
"それでは行きます。",
"",
""
)
Scene(17)
SimpleMassage(
name_("エレミラ"),
"グラスの灰被りアイドル！",
"",
""
)
Scene(18)
PlayBGM(4)
WaitAndSkip(1)

end

--@EndScript