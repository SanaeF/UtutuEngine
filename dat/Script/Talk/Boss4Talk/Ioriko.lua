dofile( './dat/Script/Library/Talker/Library.lua' )

function Ioriko()--4面弾幕前の会話

IORIKO = 0
NARUSIRU=1
ID_MAX = NARUSIRU

Scene(0)
Chara.create_ID(ID_MAX)
Massage.setBoxR()
SimpleMassage(
name_("???"),
"そこ！止まりなさい！",
"",
""
)

Scene(1)
SummonBoss(N04_NARSIRU, 7)--ボス召喚
WaitAndSkip(60)

Scene(2)
Chara.spawn(IORIKO, 4, 250, 1000, 0.4)--キャラの立ち絵を追加
Chara.brow(IORIKO, 0)
Chara.eye(IORIKO, 0)
Chara.mouth(IORIKO, 0)
Chara.isBack(IORIKO,true)
Chara.spawn(NARUSIRU, 8, 1100, 980, 0.45)--キャラの立ち絵を追加
Chara.brow(NARUSIRU, 2)
Chara.eye(NARUSIRU, 0)
Chara.mouth(NARUSIRU, 1)
SimpleMassage(
name_("ナルシル"),
"おとなしくこの道を引き返して",
"もらえないかしら!",
""
)

Scene(3)
Chara.isBack(IORIKO,false)
Chara.brow(IORIKO, 2)
Chara.mouth(IORIKO, 1)
Chara.isBack(NARUSIRU,true)
Chara.mouth(NARUSIRU, 0)
Massage.setBoxL()
SimpleMassage(
name_("庵狐"),
"それはできななぁ。",
"ココには狂気ウィルスの情報で",
"あふれているらしいし"
)

Scene(4)
Chara.isBack(IORIKO,true)
Chara.mouth(IORIKO, 0)
SimpleMassage(
name_("まにわ"),
"そうです！",
"",
""
)

Scene(4)
Chara.isBack(IORIKO,true)
SimpleMassage(
name_("まにわ"),
"そうです！",
"諸悪の根源を徹底的に調べ上げて、",
""
)

Scene(5)
Chara.isBack(IORIKO,true)
SimpleMassage(
name_("まにわ"),
"この不毛な戦いを",
"根絶やしにしてやりますから!",
""
)

Scene(6)
Chara.isBack(IORIKO,true)
Chara.brow(IORIKO, 0)
Chara.eye(IORIKO, 0)
Chara.mouth(IORIKO, 0)
SimpleMassage(
name_("まにわ"),
"邪魔だ！くそウィルス信者!",
"",
""
)

Scene(7)
Chara.isBack(IORIKO,true)
SimpleMassage(
name_("まにわ"),
"邪魔だ！くそウィルス信者!",
"しばらく黙って自粛しろ!",
""
)

Scene(8)
Chara.isBack(NARUSIRU,false)
Chara.brow(NARUSIRU, 1)
Chara.eye(NARUSIRU, 0)
Chara.mouth(NARUSIRU, 1)
Massage.setBoxR()
SimpleMassage(
name_("ナルシル"),
"あら、口が悪い。",
"いったいどこの御方かしら?",
""
)

Scene(9)
Chara.isBack(NARUSIRU,true)
Chara.brow(NARUSIRU, 0)
Chara.mouth(NARUSIRU, 0)
Massage.setBoxL()
SimpleMassage(
name_("まにわ"),
"・・・・・。",
"",
""
)

Scene(10)
Chara.isBack(NARUSIRU,false)
Chara.eye(NARUSIRU, 1)
Chara.mouth(NARUSIRU, 1)
Massage.setBoxR()
SimpleMassage(
name_("ナルシル"),
"でも同意だわ。",
"",
""
)

Scene(11)
Chara.eye(NARUSIRU, 0)
Chara.brow(NARUSIRU, 2)
SimpleMassage(
name_("ナルシル"),
"あいにく、私は非狂気勢。",
"",
""
)

Scene(12)
SimpleMassage(
name_("ナルシル"),
"おぼれてもいないし、",
"そんな力、使っても無いわ。",
""
)

Scene(13)
Chara.isBack(IORIKO,false)
Chara.mouth(IORIKO, 1)
Chara.isBack(NARUSIRU,true)
Chara.mouth(NARUSIRU, 0)
Massage.setBoxL()
SimpleMassage(
name_("庵狐"),
"あん？",
"じゃぁ、なして今ここに",
"立ち塞がってるの？"
)

Scene(14)
Chara.isBack(IORIKO,true)
Chara.mouth(IORIKO, 0)
Chara.isBack(NARUSIRU,false)
Chara.brow(NARUSIRU, 1)
Chara.eye(NARUSIRU, 1)
Chara.mouth(NARUSIRU, 1)
Massage.setBoxR()
SimpleMassage(
name_("ナルシル"),
"仕事だから仕方ないわ",
"",
""
)

Scene(15)
Chara.isBack(IORIKO,true)
Chara.isBack(NARUSIRU,false)
Massage.setBoxR()
Chara.eye(NARUSIRU, 0)
SimpleMassage(
name_("ナルシル"),
"仕事だから仕方ないわ",
"フットワークが資本の騎士だもの・・・。",
""
)

Scene(16)
Chara.brow(NARUSIRU, 2)
SimpleMassage(
name_("ナルシル"),
"さて、選びなさい！",
"",
""
)

Scene(17)
SimpleMassage(
name_("ナルシル"),
"さて、選びなさい！",
"この場を去るか、",
""
)

Scene(18)
SimpleMassage(
name_("ナルシル"),
"さて、選びなさい！",
"この場を去るか、ここで強制退場するか",
""
)

Scene(19)
Chara.isBack(IORIKO,false)
Chara.brow(IORIKO, 2)
Chara.mouth(IORIKO, 1)
Chara.isBack(NARUSIRU,true)
Chara.mouth(NARUSIRU, 0)
Massage.setBoxL()
SimpleMassage(
name_("庵狐"),
"決めた！あなたが退場する。",
"",
""
)

Scene(20)
Chara.isBack(IORIKO,true)
Chara.mouth(IORIKO, 0)
Chara.isBack(NARUSIRU,false)
Chara.brow(NARUSIRU, 0)
Chara.eye(NARUSIRU, 1)
Chara.mouth(NARUSIRU, 1)
Massage.setBoxR()
SimpleMassage(
name_("ナルシル"),
"そう・・・。",
"",
""
)
Scene(21)
Massage.setBoxR()
Chara.brow(NARUSIRU, 2)
Chara.eye(NARUSIRU, 0)
SimpleMassage(
name_("ナルシル"),
"そう・・・。",
"そこまで言うなら、ここで斬っちゃうわ!",
""
)
Scene(22)
PlayBGM(8)
WaitAndSkip(1)

end

--@EndScript