dofile( './dat/Script/Library/Talker/Library.lua' )
--5面弾幕前の会話

function Ioriko()

IORIKO = 0
AYANO = 1
FEATORIA=2
MATUMI=3
ID_MAX = MATUMI

Scene(0)
Chara.create_ID(ID_MAX)
Massage.setBoxR()
SimpleMassage(
name_("少女"),
"おいついた!",
"",
""
)

Scene(1)
SummonInterBoss(N05_FEATORIA, 3)--ボス召喚
WaitAndSkip(60)

Scene(2)
Chara.spawn(IORIKO, 4, 250, 1000, 0.4)--キャラの立ち絵を追加
Chara.spawn(FEATORIA, 9, 1100, 600, 0.4)--キャラの立ち絵を追加
Chara.isBack(FEATORIA,true)
Chara.mouth(IORIKO, 1)
Massage.setBoxL()
SimpleMassage(
name_("庵狐"),
"すっげ！頭にキノコがぶっ刺さってる！",
"",
""
)

Scene(3)
Chara.isBack(IORIKO,true)
Chara.isBack(FEATORIA,false)
Chara.mouth(IORIKO, 0)
Chara.mouth(FEATORIA, 1)
Massage.setBoxR()
SimpleMassage(
name_("少女"),
"あ、はい。キノコです。",
"",
""
)

Scene(4)
Chara.isBack(IORIKO,false)
Chara.isBack(FEATORIA,true)
Chara.mouth(IORIKO, 1)
Chara.mouth(FEATORIA, 0)
Massage.setBoxL()
SimpleMassage(
name_("庵狐"),
"どうなってんのそれ？",
"",
""
)

Scene(5)
Chara.isBack(IORIKO,true)
Chara.isBack(FEATORIA,false)
Chara.mouth(IORIKO, 0)
Chara.mouth(FEATORIA, 1)
Massage.setBoxR()
SimpleMassage(
name_("少女"),
"えっと・・・。",
"",
""
)

Scene(6)
Chara.eye(FEATORIA, 4)
Chara.brow(FEATORIA, 1)
Chara.mouth(FEATORIA, 2)
SimpleMassage(
name_("頭のキノコ"),
"あまりしゃべっている余裕は無いぞ",
"",
""
)

Scene(7)
Chara.eye(FEATORIA, 0)
SimpleMassage(
name_("頭のキノコ"),
"あの子との計画もあるが、我々は別で",
"狂気ウィルスを集めなくてはならない。",
""
)

Scene(8)
Chara.brow(FEATORIA, 2)
SimpleMassage(
name_("頭のキノコ"),
"おいそこのお前！",
"",
""
)

Scene(9)
Chara.isBack(IORIKO,false)
Chara.isBack(FEATORIA,true)
Chara.mouth(IORIKO, 1)
Massage.setBoxL()
SimpleMassage(
name_("庵狐"),
"あ？何？",
"",
""
)

Scene(10)
Chara.isBack(IORIKO,true)
Chara.isBack(FEATORIA,false)
Chara.mouth(IORIKO, 0)
Massage.setBoxR()
SimpleMassage(
name_("頭のキノコ"),
"こ、この狂限化ウィルスを撒かれたく",
"なければ、私達を倒して奪ってみろ！",
""
)

Scene(11)
Chara.isBack(IORIKO,true)
Chara.isBack(FEATORIA,true)
Chara.spawn(AYANO, 0, 470, 1000, 0.4)--キャラの立ち絵を追加
Chara.mouth(AYANO, 1)
Massage.setBoxL()
SimpleMassage(
name_("綾乃"),
"やばっ、さすがにアレを喰らったら、",
"耐えられるか分からなよ",
""
)

Scene(12)
Chara.isBack(IORIKO,false)
Chara.isBack(AYANO,true)
Chara.brow(IORIKO, 2)
Chara.mouth(IORIKO, 1)
Chara.mouth(AYANO, 0)
SimpleMassage(
name_("庵狐"),
"それはまずいね・・・。",
"じゃぁやるしか無いっか♪",
""
)

Scene(13)
Chara.isBack(IORIKO,true)
Chara.isBack(FEATORIA,false)
Chara.mouth(IORIKO, 0)
Massage.setBoxR()
SimpleMassage(
name_("頭のキノコ"),
"間違っても",
"俺をもぎ採られるんじゃないぞ？",
""
)

Scene(14)
Chara.mouth(FEATORIA, 1)
Massage.setBoxR()
SimpleMassage(
name_("少女"),
"うん・・・。がんばる！",
"",
""
)

Scene(15)
SimpleMassage(
name_("少女"),
"行くよ！マツミ",
"",
""
)

Scene(16)
Chara.isBack(FEATORIA,true)
Chara.mouth(FEATORIA, 0)
Chara.spawn(MATUMI, 5, 1200, 600, 0.31)--キャラの立ち絵を追加
Chara.mouth(MATUMI, 1)
SimpleMassage(
name_("マツミ"),
"はいは～い♪",
"",
""
)

Scene(17)
PlayBGM(9)
WaitAndSkip(1)

end

--@EndScript