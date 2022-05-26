dofile( './dat/Script/Library/Talker/Library.lua' )
--4面弾幕終了後の会話

function AyanoMisato()

AYANO = 0
MISATO = 1
NARUSIRU=2
FEATORIA=3
ID_MAX = FEATORIA

Scene(0)
Chara.create_ID(ID_MAX)
Chara.spawn(AYANO, 0, 500, 1000, 0.4)--キャラの立ち絵を追加
Chara.brow(AYANO, 0)
Chara.eye(AYANO, 0)
Chara.mouth(AYANO, 0)
Chara.isBack(AYANO,true)
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
Chara.isBack(AYANO,false)
Chara.isBack(NARUSIRU,true)
Chara.brow(AYANO, 1)
Chara.mouth(AYANO, 1)
Massage.setBoxL()
SimpleMassage(
name_("綾乃"),
"かなり体力消耗しちゃったみたい・・・",
"",
""
)

Scene(2)
Chara.brow(AYANO, 0)
Chara.eye(AYANO, 3)
Chara.spawnFacial(AYANO, HAPPY, 0, 480)
SimpleMassage(
name_("綾乃"),
"かなり体力消耗しちゃったみたい・・・",
"さて、ココから去ってもらえるかな？",
""
)

Scene(3)
Chara.mouth(AYANO, 0)
Chara.eye(AYANO, 0)
Chara.isBack(AYANO,true)
SimpleMassage(
name_("まにわ"),
"まz・・・dすよ・・・!!",
"",
""
)

Scene(4)
Chara.spawnFacial(AYANO, STOP, 0, 0)
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
Chara.isBack(AYANO,false)
Chara.spawnFacial(AYANO, ACCENT, 150, 680)
SimpleMassage(
name_(""),
"",
"",
""
)
WaitAndSkip(90)

Scene(7)
Chara.eye(AYANO, 0)
Chara.mouth(AYANO, 1)
Chara.spawnFacial(AYANO, STOP, 0, 0)
SimpleMassage(
name_("綾乃"),
"あれ、通信が悪いのかな・・・。",
"",
""
)

Scene(8)
Chara.isBack(AYANO,true)
Chara.mouth(AYANO, 0)
Chara.spawn(MISATO, 1, 170, 1040, 0.46)--キャラの立ち絵を追加
Chara.brow(MISATO, 0)
Chara.eye(MISATO, 0)
Chara.mouth(MISATO, 1)
SimpleMassage(
name_("みさと"),
"圏外みたいだね・・・。",
"",
""
)

Scene(9)
Chara.isBack(MISATO,true)
Chara.isBack(AYANO,false)
Chara.mouth(MISATO, 0)
Chara.brow(AYANO, 1)
Chara.mouth(AYANO, 1)
SimpleMassage(
name_("綾乃"),
"ひゃっ！・・・みさとか。",
"",
""
)
WaitAndSkip(50)

Scene(10)
Chara.mouth(AYANO, 0)
Chara.isBack(AYANO,true)
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

Scene(11)
SimpleMassage(
name_("ナルシル"),
"この辺りは狂気勢が多いエリアよ",
"とはいえ、私はもう動けないけど・・・。",
""
)

Scene(12)
Chara.isBack(AYANO,false)
Chara.isBack(NARUSIRU,true)
Chara.mouth(NARUSIRU, 0)
Chara.brow(AYANO, 0)
Chara.mouth(AYANO, 1)
Massage.setBoxL()
SimpleMassage(
name_("綾乃"),
"あぁ・・・。",
"",
""
)

Scene(13)
SimpleMassage(
name_("綾乃"),
"あぁ・・・。",
"とりあえずこのまま探索をしてみよ♪",
""
)

Scene(14)
Chara.isBack(AYANO,true)
Chara.isBack(MISATO,false)
Chara.mouth(AYANO, 0)
Chara.mouth(MISATO, 1)
SimpleMassage(
name_("みさと"),
"いったんここを離れて、",
"回復した方が良いね。",
""
)

Scene(15)
Chara.mouth(MISATO, 0)
Chara.isBack(AYANO,false)
Chara.isBack(MISATO,true)
SimpleMassage(
name_("綾乃"),
"おっけー。",
"じゃぁ行ってみようか。",
""
)

Scene(16)
Chara.hide(AYANO)
Chara.isBack(MISATO,false)
SimpleMassage(
name_("みさと"),
"・・・・",
"",
""
)
WaitAndSkip(60)

Scene(17)
SimpleMassage(
name_("みさと"),
"(あれ、非狂気勢なのに、",
"狂気勢のエリアまで誘導してきたの？)",
""
)

Scene(18)
Chara.hide(MISATO)
WaitAndSkip(30)

Scene(19)
Chara.isBack(NARUSIRU,false)
Massage.setBoxR()
SimpleMassage(
name_("ナルシル"),
"・・・。",
"",
""
)

Scene(20)
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

Scene(21)
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

Scene(22)
Massage.setBoxL()
SimpleMassage(
name_("頭のキノコ?"),
"・・・。",
"",
""
)

Scene(23)
SimpleMassage(
name_("頭のキノコ?"),
"ギルティー(有罪)!!!",
"",
""
)

Scene(24)
SimpleMassage(
name_("頭のキノコ?"),
"優秀だった騎士を失うのは残念だなぁ～",
"",
""
)

Scene(25)
SimpleMassage(
name_("頭のキノコ?"),
"優秀だった騎士を失うのは残念だなぁ～",
"でも仕方ないよね。",
""
)

Scene(26)
SimpleMassage(
name_("頭のキノコ?"),
"僕ら狂気ウィルスに楯突いた挙句、",
"ただの人間に負けたんだもん。",
""
)

Scene(27)
SimpleMassage(
name_("少女"),
"まって！ナルシルちゃんは",
"悪くないよ・・・。",
""
)

Scene(28)
SimpleMassage(
name_("少女"),
"私だって「こんな」だけど・・・。",
"",
""
)

Scene(29)
SimpleMassage(
name_("少女"),
"私だって「こんな」だけど・・・。",
"非狂気勢には賛成だし・・・。",
""
)

Scene(30)
SimpleMassage(
name_("頭のキノコ?"),
"あ？小娘ごときが生意気な",
"",
""
)

Scene(31)
SimpleMassage(
name_("頭のキノコ?"),
"まぁいいさ、",
"所詮、欠陥品の小娘が・・・。",
"余計な真似はするんじゃないぞ？"
)

Scene(32)
SimpleMassage(
name_("少女"),
"うぅっ・・・。",
"",
""
)

Scene(33)
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