dofile( './dat/Script/Library/Talker/Library.lua' )
--4面弾幕終了後の会話

function Ioriko()

IORIKO = 0
MISATO = 1
NARUSIRU=2
FEATORIA=3
ID_MAX = FEATORIA

Scene(0)
Chara.create_ID(ID_MAX)
Chara.spawn(IORIKO, 4, 500, 1000, 0.4)--キャラの立ち絵を追加
Chara.brow(IORIKO, 0)
Chara.eye(IORIKO, 0)
Chara.mouth(IORIKO, 0)
Chara.isBack(IORIKO,true)
Chara.spawn(NARUSIRU, 8, 1100, 980, 0.45)--キャラの立ち絵を追加
Chara.brow(NARUSIRU, 1)
Chara.eye(NARUSIRU, 2)
Chara.mouth(NARUSIRU, 2)
Massage.setBoxR()
SimpleMassage(
name_("ナルシル"),
"く、くやしい・・・。",
"",
""
)

Scene(1)
Chara.isBack(IORIKO,false)
Chara.isBack(NARUSIRU,true)
Chara.brow(IORIKO, 1)
Chara.mouth(IORIKO, 1)
Massage.setBoxL()
SimpleMassage(
name_("庵狐"),
"うわ、かなり体力消耗しちゃった・・・",
"",
""
)

Scene(2)
Chara.brow(IORIKO, 0)
Chara.eye(IORIKO, 3)
Chara.spawnFacial(IORIKO, HAPPY, 0, 480)
SimpleMassage(
name_("庵狐"),
"うわ、かなり体力消耗しちゃった・・・",
"さてさて、君はお帰りの時間だよ？",
""
)

Scene(3)
Chara.mouth(IORIKO, 0)
Chara.eye(IORIKO, 0)
Chara.isBack(IORIKO,true)
SimpleMassage(
name_("まにわ"),
"まz・・・dすよ・・・!!",
"",
""
)

Scene(4)
Chara.spawnFacial(IORIKO, STOP, 0, 0)
SimpleMassage(
name_("まにわ"),
"まz・・・dすよ・・・!!",
"そ・・・・・・",
""
)

Scene(5)
SimpleMassage(
name_("まにわ"),
"まz・・・dすよ・・・!!",
"そ・・・・・・",
"・・・。"
)

Scene(6)
Chara.isBack(IORIKO,false)
Chara.spawnFacial(IORIKO, ACCENT, 150, 680)
SimpleMassage(
name_(""),
"",
"",
""
)
WaitAndSkip(90)

Scene(7)
Chara.eye(IORIKO, 0)
Chara.mouth(IORIKO, 1)
Chara.spawnFacial(IORIKO, STOP, 0, 0)
SimpleMassage(
name_("庵狐"),
"あらら、通信が悪いなぁ・・・。",
"まぁいっか。",
""
)

Scene(8)
Chara.mouth(IORIKO, 0)
Chara.isBack(IORIKO,true)
Chara.isBack(NARUSIRU,false)
Chara.brow(NARUSIRU, 1)
Chara.eye(NARUSIRU, 0)
Chara.mouth(NARUSIRU, 1)
Massage.setBoxR()
SimpleMassage(
name_("ナルシル"),
"この辺りは狂気勢が多いエリアよ",
"",
""
)

Scene(9)
SimpleMassage(
name_("ナルシル"),
"この辺りは狂気勢が多いエリアよ",
"とはいえ、私はもう動けないけど・・・。",
""
)

Scene(10)
Chara.isBack(IORIKO,false)
Chara.isBack(NARUSIRU,true)
Chara.mouth(NARUSIRU, 0)
Chara.brow(IORIKO, 0)
Chara.mouth(IORIKO, 1)
Massage.setBoxL()
SimpleMassage(
name_("庵狐"),
"へぇ～(聞いてない)",
"",
""
)

Scene(11)
SimpleMassage(
name_("庵狐"),
"とりあえずこのまま探索をしてみっか♪",
"",
""
)

Scene(12)
Chara.isBack(IORIKO,true)
Chara.isBack(MISATO,false)
Chara.mouth(IORIKO, 0)
Chara.mouth(MISATO, 1)
SimpleMassage(
name_("庵狐"),
"いったんここを離れて、",
"回復した方が良いかな？",
""
)

Scene(13)
Chara.mouth(MISATO, 0)
Chara.isBack(IORIKO,false)
Chara.isBack(MISATO,true)
SimpleMassage(
name_("庵狐"),
"よっしゃ！",
"じゃぁ行ってみるか。",
""
)

Scene(14)
Chara.hide(IORIKO)
WaitAndSkip(30)

Scene(15)
Chara.isBack(NARUSIRU,false)
Massage.setBoxR()
SimpleMassage(
name_("ナルシル"),
"・・・。",
"",
""
)

Scene(16)
Chara.spawn(FEATORIA, 9, 350, 800, 0.4)--キャラの立ち絵を追加
Chara.brow(FEATORIA, 0)
Chara.eye(FEATORIA, 0)
Chara.mouth(FEATORIA, 0)
Chara.body(FEATORIA, 2)
Massage.setBoxL()
SimpleMassage(
name_("頭のキノコ?"),
"あーあ、負けちゃったんだ。",
"",
""
)

Scene(17)
Chara.brow(NARUSIRU, 1)
Chara.eye(NARUSIRU, 2)
Chara.mouth(NARUSIRU, 2)
Massage.setBoxR()
SimpleMassage(
name_("ナルシル"),
"お許しください",
"",
""
)

Scene(18)
Massage.setBoxL()
SimpleMassage(
name_("頭のキノコ?"),
"・・・。",
"",
""
)

Scene(19)
SimpleMassage(
name_("頭のキノコ?"),
"ギルティー(有罪)!!!",
"",
""
)

Scene(20)
SimpleMassage(
name_("頭のキノコ?"),
"優秀だった騎士を失うのは残念だなぁ～",
"",
""
)

Scene(21)
SimpleMassage(
name_("頭のキノコ?"),
"優秀だった騎士を失うのは残念だなぁ～",
"でも仕方ないよね。",
""
)

Scene(22)
SimpleMassage(
name_("頭のキノコ?"),
"僕ら狂気ウィルスに楯突いた挙句、",
"ただの人間に負けたんだもん。",
""
)

Scene(23)
SimpleMassage(
name_("少女"),
"まって！ナルシルちゃんは",
"悪くないよ・・・。",
""
)

Scene(24)
SimpleMassage(
name_("少女"),
"私だって「こんな」だけど・・・。",
"",
""
)

Scene(25)
SimpleMassage(
name_("少女"),
"私だって「こんな」だけど・・・。",
"非狂気勢には賛成だし・・・。",
""
)

Scene(26)
SimpleMassage(
name_("頭のキノコ?"),
"あ？小娘ごときが生意気な",
"",
""
)

Scene(27)
SimpleMassage(
name_("頭のキノコ?"),
"まぁいいさ、",
"所詮、欠陥品の小娘が・・・。",
"余計な真似はするんじゃないぞ？"
)

Scene(28)
SimpleMassage(
name_("少女"),
"うぅっ・・・。",
"",
""
)

Scene(29)
Chara.brow(NARUSIRU, 1)
Chara.eye(NARUSIRU, 2)
Chara.mouth(NARUSIRU, 2)
Massage.setBoxR()
SimpleMassage(
name_("ナルシル"),
"(ごめんね、私には何もできないわ・・・。)",
"",
""
)

end

--@EndScript