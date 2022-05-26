--1面弾幕前の会話

function Misato()

MISATO = 0
MATUMI = 1
ID_MAX = MATUMI

Scene(0)
Chara.create_ID(ID_MAX)
Massage.setBoxL()
Chara.spawn(MISATO, 1, 250, 1040, 0.46)--キャラの立ち絵を追加
Chara.eye(MISATO, 0)
Chara.mouth(MISATO, 1)
SimpleMassage(
name_("みさと"),
"虚界の夜桜はきれいだね。",
"今度、みんなでお花見しよっ",
""
)
Scene(1)
Chara.eye(MISATO, 1)
Chara.mouth(MISATO, 0)
Chara.spawnFacial(MISATO, ACCENT, 150, 720)
Chara.isBack(MISATO,true)
SimpleMassage(
name_("「まにわ」"),
"やめといたほうが良いですよ・・・。",
"",
""
)
Scene(2)
Chara.spawnFacial(MISATO, STOP, 0, 0)
SimpleMassage(
name_("「まにわ」"),
"やめといたほうが良いですよ・・・。",
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
Chara.isBack(MISATO,false)
Chara.isBack(MATUMI,true)
Chara.mouth(MISATO, 1)
Massage.setBoxL()
SimpleMassage(
name_("みさと"),
"わたしって、そんなに怪しいのかなぁ。",
"あなた程の怪しいオーラは無いと",
"思うけど・・・。"
)
Scene(8)
Chara.mouth(MISATO, 0)
Chara.eye(MATUMI, 1)
Chara.mouth(MATUMI, 2)
Chara.brow(MATUMI, 1)
Chara.isBack(MATUMI,false)
Chara.isBack(MISATO,true)
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

end

--@EndScript