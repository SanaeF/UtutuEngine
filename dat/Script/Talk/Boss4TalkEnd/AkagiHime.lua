dofile( './dat/Script/Library/Talker/Library.lua' )
--4面弾幕終了後の会話

function AkagiHime()

HIME = 0
AKAGI = 1
NARUSIRU=2
FEATORIA=3
ID_MAX = FEATORIA

Scene(0)
Chara.create_ID(ID_MAX)
Chara.spawn(HIME, 3, 500, 1070, 0.47)--キャラの立ち絵を追加
Chara.brow(HIME, 0)
Chara.eye(HIME, 0)
Chara.mouth(HIME, 0)
Chara.isBack(HIME,true)
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
Chara.isBack(HIME,false)
Chara.isBack(NARUSIRU,true)
Chara.brow(HIME, 1)
Chara.mouth(HIME, 1)
Massage.setBoxL()
SimpleMassage(
name_("媛"),
"いててっ、けっこう消耗しちゃった・・・",
"",
""
)

Scene(2)
Chara.brow(HIME, 0)
Chara.eye(HIME, 3)
Chara.spawnFacial(HIME, HAPPY, 0, 480)
SimpleMassage(
name_("媛"),
"いててっ、けっこう消耗しちゃった・・・",
"じゃぁ、ここから帰ってくださいぃ！",
""
)

Scene(3)
Chara.mouth(HIME, 0)
Chara.eye(HIME, 0)
Chara.isBack(HIME,true)
SimpleMassage(
name_("まにわ"),
"まz・・・dすよ・・・!!",
"",
""
)

Scene(4)
Chara.spawnFacial(HIME, STOP, 0, 0)
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
Chara.isBack(HIME,false)
Chara.spawnFacial(HIME, ACCENT, 150, 680)
SimpleMassage(
name_(""),
"",
"",
""
)
WaitAndSkip(90)

Scene(7)
Chara.eye(HIME, 0)
Chara.mouth(HIME, 1)
Chara.spawnFacial(HIME, STOP, 0, 0)
SimpleMassage(
name_("媛"),
"え、通信が悪いのかなぁ・・・。",
"",
""
)

Scene(8)
Chara.isBack(HIME,true)
Chara.mouth(HIME, 0)
Chara.spawn(AKAGI, 2, 170, 1000, 0.4)--キャラの立ち絵を追加
Chara.brow(AKAGI, 0)
Chara.eye(AKAGI, 1)
Chara.mouth(AKAGI, 1)
SimpleMassage(
name_("赤城"),
"圏外みたいだね。",
"",
""
)

Scene(9)
Chara.isBack(AKAGI,true)
Chara.isBack(HIME,false)
Chara.mouth(AKAGI, 0)
Chara.brow(HIME, 1)
Chara.mouth(HIME, 1)
SimpleMassage(
name_("媛"),
"ひゃっ！・・・赤城ちゃん。",
"",
""
)
WaitAndSkip(50)

Scene(10)
Chara.mouth(HIME, 0)
Chara.isBack(HIME,true)
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
Chara.isBack(HIME,false)
Chara.isBack(NARUSIRU,true)
Chara.mouth(NARUSIRU, 0)
Chara.brow(HIME, 0)
Chara.mouth(HIME, 1)
Massage.setBoxL()
SimpleMassage(
name_("媛"),
"うぅ～ん・・・。",
"",
""
)

Scene(13)
SimpleMassage(
name_("媛"),
"うぅ～ん・・・。",
"とりあえず探索しちゃいましょ♪",
""
)

Scene(14)
Chara.isBack(HIME,true)
Chara.isBack(AKAGI,false)
Chara.mouth(HIME, 0)
Chara.mouth(AKAGI, 1)
SimpleMassage(
name_("赤城"),
"大丈夫？いったんここを離れて、",
"回復した方が良いよ。",
""
)

Scene(15)
Chara.mouth(AKAGI, 0)
Chara.isBack(HIME,false)
Chara.isBack(AKAGI,true)
SimpleMassage(
name_("媛"),
"うん！そうするね！",
"ありがとう、赤城ちゃん",
""
)

Scene(16)
Chara.hide(HIME)
Chara.isBack(AKAGI,false)
SimpleMassage(
name_("赤城"),
"・・・・",
"",
""
)
WaitAndSkip(60)

Scene(17)
SimpleMassage(
name_("赤城"),
"(こいつ、非狂気勢なのに、",
"狂気勢のエリアまで誘導してきたぞ、",
"一応警戒しておくか。)"
)

Scene(18)
Chara.hide(AKAGI)
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