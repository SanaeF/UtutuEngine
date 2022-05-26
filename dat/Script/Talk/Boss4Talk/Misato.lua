dofile( './dat/Script/Library/Talker/Library.lua' )

function Misato()--4面弾幕前の会話

MISATO = 0
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
Chara.spawn(MISATO, 1, 170, 1040, 0.46)--キャラの立ち絵を追加
Chara.brow(MISATO, 0)
Chara.eye(MISATO, 0)
Chara.mouth(MISATO, 0)
Chara.isBack(MISATO,true)
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
Chara.isBack(MISATO,false)
Chara.brow(MISATO, 2)
Chara.mouth(MISATO, 1)
Chara.isBack(NARUSIRU,true)
Chara.mouth(NARUSIRU, 0)
Massage.setBoxL()
SimpleMassage(
name_("みさと"),
"悪いわね、その要望には応えられないわ",
"だって、ココには狂気ウィルスの",
"情報であふれているもの"
)

Scene(4)
Chara.isBack(MISATO,true)
Chara.mouth(MISATO, 0)
SimpleMassage(
name_("まにわ"),
"そうなんです！",
"",
""
)

Scene(4)
Chara.isBack(MISATO,true)
SimpleMassage(
name_("まにわ"),
"そうなんです！",
"諸悪の根源を徹底的に調べ上げて、",
""
)

Scene(5)
Chara.isBack(MISATO,true)
SimpleMassage(
name_("まにわ"),
"この不毛な戦いを",
"根絶やしにしてやりますから!",
""
)

Scene(6)
Chara.isBack(MISATO,true)
Chara.brow(MISATO, 0)
Chara.eye(MISATO, 0)
Chara.mouth(MISATO, 0)
SimpleMassage(
name_("まにわ"),
"帰ってください！このウィルス信者!",
"",
""
)

Scene(7)
Chara.isBack(MISATO,true)
SimpleMassage(
name_("まにわ"),
"帰ってください！このウィルス信者!",
"狂気を怯えろ!",
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
Chara.isBack(MISATO,false)
Chara.mouth(MISATO, 1)
Chara.isBack(NARUSIRU,true)
Chara.mouth(NARUSIRU, 0)
Massage.setBoxL()
SimpleMassage(
name_("みさと"),
"では、",
"なぜ今ここに立ち塞がってるわけ？",
""
)

Scene(14)
Chara.isBack(MISATO,true)
Chara.mouth(MISATO, 0)
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
Chara.isBack(MISATO,true)
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
Chara.isBack(MISATO,false)
Chara.brow(MISATO, 2)
Chara.mouth(MISATO, 1)
Chara.isBack(NARUSIRU,true)
Chara.mouth(NARUSIRU, 0)
Massage.setBoxL()
SimpleMassage(
name_("綾乃"),
"そんなの、言うまでも無いわ!",
"",
""
)

Scene(20)
Chara.isBack(MISATO,true)
Chara.mouth(MISATO, 0)
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
"残念だけど、ここで斬らせてもらうわ!",
""
)
Scene(22)
PlayBGM(8)
WaitAndSkip(1)

end

--@EndScript