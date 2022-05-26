dofile( './dat/Script/Library/Talker/Library.lua' )
--5面弾幕前の会話

function Hime()

HIME = 0
AKAGI = 1
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
Chara.spawn(HIME, 3, 250, 1070, 0.47)--キャラの立ち絵を追加
Chara.spawn(FEATORIA, 9, 1100, 600, 0.4)--キャラの立ち絵を追加
Chara.isBack(FEATORIA,true)
Chara.mouth(HIME, 1)
Massage.setBoxL()
SimpleMassage(
name_("媛"),
"ぅえ!?、頭にキノコが・・・。",
"",
""
)

Scene(3)
Chara.isBack(HIME,true)
Chara.isBack(FEATORIA,false)
Chara.mouth(HIME, 0)
Chara.mouth(FEATORIA, 1)
Massage.setBoxR()
SimpleMassage(
name_("少女"),
"はい。キノコです。",
"",
""
)

Scene(4)
Chara.isBack(HIME,false)
Chara.isBack(FEATORIA,true)
Chara.mouth(HIME, 1)
Chara.mouth(FEATORIA, 0)
Massage.setBoxL()
SimpleMassage(
name_("媛"),
"頭、大丈夫なんですか？",
"",
""
)

Scene(5)
Chara.isBack(HIME,true)
Chara.isBack(FEATORIA,false)
Chara.mouth(HIME, 0)
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
Chara.isBack(HIME,false)
Chara.isBack(FEATORIA,true)
Chara.mouth(HIME, 1)
Massage.setBoxL()
SimpleMassage(
name_("媛"),
"ふぇあ？",
"",
""
)

Scene(10)
Chara.isBack(HIME,true)
Chara.isBack(FEATORIA,false)
Chara.mouth(HIME, 0)
Massage.setBoxR()
SimpleMassage(
name_("頭のキノコ"),
"この狂限化ウィルスをばら撒かれたく",
"なければ、私達を倒して奪ってみろ！",
""
)

Scene(11)
Chara.isBack(HIME,true)
Chara.isBack(FEATORIA,true)
Chara.spawn(AKAGI, 2, 470, 1000, 0.4)--キャラの立ち絵を追加
Chara.mouth(AKAGI, 1)
Massage.setBoxL()
SimpleMassage(
name_("赤城"),
"さすがにアレを喰らったら、",
"耐えられるか分からないね",
""
)

Scene(12)
Chara.isBack(HIME,false)
Chara.isBack(AKAGI,true)
Chara.brow(HIME, 2)
Chara.mouth(HIME, 1)
Chara.mouth(AKAGI, 0)
SimpleMassage(
name_("媛"),
"ひえぇ、それはまずいよぉ～。",
"やるしかないんだよね・・・。",
""
)

Scene(13)
Chara.isBack(HIME,true)
Chara.isBack(FEATORIA,false)
Chara.mouth(HIME, 0)
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