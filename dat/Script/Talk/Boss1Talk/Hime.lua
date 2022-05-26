--1面弾幕前の会話

function Hime()

HIME = 0
MATUMI = 1
ID_MAX = MATUMI

Scene(0)
Chara.create_ID(ID_MAX)
Massage.setBoxL()
Chara.spawn(HIME, 3, 250, 1070, 0.47)--キャラの立ち絵を追加
Chara.eye(HIME, 3)
Chara.mouth(HIME, 1)
SimpleMassage(
name_("媛"),
"夜の桜は虚界って",
"自然にライトアップされるんだ～",
""
)
Scene(1)
Chara.eye(HIME, 1)
Chara.mouth(HIME, 0)
Chara.spawnFacial(HIME, ACCENT, 100, 780)
Chara.isBack(HIME,true)
SimpleMassage(
name_("「まにわ」"),
"違いますよ！",
"",
""
)
Scene(2)
Chara.spawnFacial(HIME, STOP, 0, 0)
SimpleMassage(
name_("「まにわ」"),
"違いますよ！",
"そいつは狂気ウィルスです！",
""
)
Scene(3)
SimpleMassage(
name_("「まにわ」"),
"この異常事態の",
"諸悪の根源みたいなものです！",
""
)
Scene(4)
SummonBoss(N01_MATUMI, 5)--ボス召喚
Chara.spawn(MATUMI, 5, 1100, 600, 0.27)--キャラの立ち絵を追加
Chara.eye(MATUMI, 1)
Chara.mouth(MATUMI, 1)
Massage.setBoxR()
SimpleMassage(
name_("マツミ"),
"君たち君たち",
"",
""
)
Scene(5)
SimpleMassage(
name_("マツミ"),
"君たち君たち",
"こんな夜中に何してるんです？",
""
)
Scene(6)
Chara.eye(MATUMI, 3)
SimpleMassage(
name_("マツミ"),
"君たち君たち",
"こんな夜中に何してるんです？",
"不審者ですか♪"
)
Scene(7)
Chara.mouth(MATUMI, 0)
Chara.isBack(HIME,false)
Chara.isBack(MATUMI,true)
Chara.brow(HIME, 1)
Chara.mouth(HIME, 1)
Chara.spawnFacial(HIME, SWEAT, 60, 680)
Massage.setBoxL()
SimpleMassage(
name_("媛"),
"え!?あの・・・。",
"明らかにヤバイ狂気を感じる人が、",
""
)
Scene(8)
Chara.mouth(HIME, 0)
Chara.eye(MATUMI, 1)
Chara.mouth(MATUMI, 2)
Chara.brow(MATUMI, 1)
Chara.isBack(MATUMI,false)
Chara.isBack(HIME,true)
Chara.spawnFacial(MATUMI, SWEAT, -80, -280)
Massage.setBoxR()
SimpleMassage(
name_("マツミ"),
"私って、そんなにヤバいですぅ？",
"",
""
)
Scene(9)
Chara.mouth(MATUMI, 1)
Chara.brow(MATUMI, 0)
Chara.spawnFacial(MATUMI, STOP, 0, 0)
SimpleMassage(
name_("マツミ"),
"私って、そんなにヤバいですぅ？",
"狂限化のオーラですかね♪",
""
)
Scene(10)
Chara.mouth(MATUMI, 0)
Chara.isBack(MATUMI,true)
Massage.setBoxL()
SimpleMassage(
name_("「まにわ」"),
"狂限化・・・なるほど。",
"",
""
)
Scene(11)
SimpleMassage(
name_("「まにわ」"),
"狂限化・・・なるほど。",
"狂気ウィルスの感染者を狂限化",
"って言ってるのね。"
)
Scene(12)
Chara.mouth(MATUMI, 1)
Chara.isBack(MATUMI,false)
PlayBGM(2)
Chara.eye(MATUMI, 3)
Massage.setBoxR()
SimpleMassage(
name_("マツミ"),
"はい♪",
"",
""
)
Scene(13)
SimpleMassage(
name_("マツミ"),
"はい♪",
"それじゃぁさっそく・・・",
""
	)
Scene(14)
Chara.eye(MATUMI, 0)
Chara.brow(MATUMI, 2)
SimpleMassage(
name_("マツミ"),
"始めちゃいますね☆",
"",
""
)

end

--@EndScript