--1面弾幕前の会話

function Akagi()

AKAGI = 0
MATUMI = 1
ID_MAX = MATUMI

Scene(0)
Chara.create_ID(ID_MAX)
Massage.setBoxL()
Chara.spawn(AKAGI, 2, 250, 1000, 0.4)--キャラの立ち絵を追加
Chara.eye(AKAGI, 3)
Chara.mouth(AKAGI, 1)
Chara.spawnFacial(AKAGI, HAPPY, 0, 480)
SimpleMassage(
name_("赤城"),
"はぇ～、虚界の夜桜も良いなぁ。",
"一枚一枚が発光するんだね",
""
)
Scene(1)
Chara.eye(AKAGI, 1)
Chara.mouth(AKAGI, 0)
Chara.spawnFacial(AKAGI, ACCENT, 100, 600)
Chara.isBack(AKAGI,true)
SimpleMassage(
name_("「まにわ」"),
"違いますよ！",
"",
""
)
Scene(2)
Chara.spawnFacial(AKAGI, STOP, 0, 0)
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
SummonBoss(N01_MATUMI)--ボス召喚
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
Chara.isBack(AKAGI,false)
Chara.isBack(MATUMI,true)
Chara.mouth(AKAGI, 1)
Massage.setBoxL()
SimpleMassage(
name_("赤城"),
"まぁそんな所かな・・・。",
"それより、君から変なオーラを",
"感知してるんだけども。"
)
Scene(8)
Chara.mouth(AKAGI, 0)
Chara.eye(MATUMI, 1)
Chara.mouth(MATUMI, 2)
Chara.brow(MATUMI, 1)
Chara.isBack(MATUMI,false)
Chara.isBack(AKAGI,true)
Chara.spawnFacial(MATUMI, SWEAT, -80, -280)
Massage.setBoxR()
SimpleMassage(
name_("マツミ"),
"それって、どんなオーラですぅ？",
"",
""
)
Scene(9)
Chara.mouth(MATUMI, 1)
Chara.brow(MATUMI, 0)
Chara.spawnFacial(MATUMI, STOP, 0, 0)
SimpleMassage(
name_("マツミ"),
"それって、どんなオーラですぅ？",
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
Scene(16)
JoinBullet(0,5)
end

--@EndScript