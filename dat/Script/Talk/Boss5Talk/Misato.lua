dofile( './dat/Script/Library/Talker/Library.lua' )
--5面弾幕前の会話

function Misato()

MISATO = 0
IORIKO = 1
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
Chara.spawn(MISATO, 1, 250, 1040, 0.46)--キャラの立ち絵を追加
Chara.spawn(FEATORIA, 9, 1100, 600, 0.4)--キャラの立ち絵を追加
Chara.isBack(FEATORIA,true)
Chara.mouth(MISATO, 1)
Massage.setBoxL()
SimpleMassage(
name_("みさと"),
"うわ、頭にキノコ・・・。",
"",
""
)

Scene(3)
Chara.isBack(MISATO,true)
Chara.isBack(FEATORIA,false)
Chara.mouth(MISATO, 0)
Chara.mouth(FEATORIA, 1)
Massage.setBoxR()
SimpleMassage(
name_("少女"),
"はい。キノコです。",
"",
""
)

Scene(4)
Chara.isBack(MISATO,false)
Chara.isBack(FEATORIA,true)
Chara.mouth(MISATO, 1)
Chara.mouth(FEATORIA, 0)
Massage.setBoxL()
SimpleMassage(
name_("みさと"),
"どうしたのよそれ？",
"",
""
)

Scene(5)
Chara.isBack(MISATO,true)
Chara.isBack(FEATORIA,false)
Chara.mouth(MISATO, 0)
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
Chara.isBack(MISATO,false)
Chara.isBack(FEATORIA,true)
Chara.mouth(MISATO, 1)
Massage.setBoxL()
SimpleMassage(
name_("みさと"),
"うぇ、なんでしょう？",
"",
""
)

Scene(10)
Chara.isBack(MISATO,true)
Chara.isBack(FEATORIA,false)
Chara.mouth(MISATO, 0)
Massage.setBoxR()
SimpleMassage(
name_("頭のキノコ"),
"この狂限化ウィルスをばら撒かれたく",
"なければ、私達を倒して奪ってみろ！",
""
)

Scene(11)
Chara.isBack(MISATO,true)
Chara.isBack(FEATORIA,true)
Chara.spawn(IORIKO, 4, 470, 1000, 0.4)--キャラの立ち絵を追加
Chara.mouth(IORIKO, 1)
Massage.setBoxL()
SimpleMassage(
name_("菴狐"),
"さすがにアレを喰らったら、",
"耐えられるか分からないねねぇ〜",
""
)

Scene(12)
Chara.isBack(MISATO,false)
Chara.isBack(IORIKO,true)
Chara.brow(MISATO, 2)
Chara.mouth(MISATO, 1)
Chara.mouth(IORIKO, 0)
SimpleMassage(
name_("みさと"),
"それはまずいねぇ・・・。",
"やるしかないか。",
""
)

Scene(13)
Chara.isBack(MISATO,true)
Chara.isBack(FEATORIA,false)
Chara.mouth(MISATO, 0)
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
"はいは〜い♪",
"",
""
)

Scene(17)
PlayBGM(9)
WaitAndSkip(1)

end

--@EndScript