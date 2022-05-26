dofile( './dat/Script/Library/Talker/Library.lua' )
--6面弾幕前の会話

function StoryMode()

AYANO=0
SHIENA=1
ID_MAX = SHIENA

Scene(0)
Chara.create_ID(ID_MAX)
SummonBoss(N06_SHIENA, 10)--ボス召喚
WaitAndSkip(60)

Scene(1)
Chara.spawn(AYANO, 0, 250, 1000, 0.4)--キャラの立ち絵を追加
Chara.img(tag(AYANO), brow(0), eye(1), mouth(0), back(true))
Chara.spawn(SHIENA, 10, 1200, 900, 0.4)--キャラの立ち絵を追加
Chara.img(tag(SHIENA), brow(0), eye(1), mouth(1), back(false))
Chara.body(SHIENA,1)
Massage.setBoxR()
SimpleMassage(
name_("シエナ"),
"ようやくここまで来てくれたんだね。",
"",
""
)

Scene(2)
Chara.img(tag(AYANO), brow(0), eye(1), mouth(1), back(false))
Chara.img(tag(SHIENA), brow(0), eye(1), mouth(2), back(true))
Massage.setBoxL()
SimpleMassage(
name_("綾乃"),
"この人が、惡の根源？",
"",
""
)

Scene(3)
Chara.img(tag(AYANO), brow(2), eye(1), mouth(1), back(false))
Chara.spawnFacial(AYANO, ANGRY, 80, 570)
SimpleMassage(
name_("綾乃"),
"この人が、惡の根源？",
"さぁ、狂気を止めてもらおうか！",
""
)

Scene(4)
Chara.img(tag(AYANO), brow(2), eye(1), mouth(0), back(true))
Chara.img(tag(SHIENA), brow(1), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("シエナ"),
"う～ん、",
"狂気を扱ってるのは私じゃないんだ。",
""
)

Scene(5)
Chara.img(tag(AYANO), brow(1), eye(1), mouth(1), back(false))
Chara.img(tag(SHIENA), brow(1), eye(1), mouth(0), back(true))
Chara.spawnFacial(AYANO, STOP, 80, 570)
Massage.setBoxL()
SimpleMassage(
name_("綾乃"),
"当てが外れたのか・・・。どうしよう。",
"",
""
)

Scene(6)
Chara.body(SHIENA,0)
Chara.img(tag(AYANO), brow(1), eye(1), mouth(0), back(true))
Chara.img(tag(SHIENA), brow(0), eye(2), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("シエナ"),
"では改めまして、",
"",
""
)

Scene(7)
Chara.img(tag(SHIENA), brow(0), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("シエナ"),
"では改めまして、お久しぶり",
"また会えてうれしいわ。",
""
)

Scene(8)
Chara.img(tag(AYANO), brow(1), eye(1), mouth(1), back(false))
Chara.img(tag(SHIENA), brow(0), eye(1), mouth(0), back(true))
Chara.spawnFacial(AYANO, ACCENT, 150, 680)
Massage.setBoxL()
SimpleMassage(
name_("綾乃"),
"え？",
"",
""
)

Scene(9)
Chara.img(tag(AYANO), brow(1), eye(1), mouth(0), back(true))
Chara.img(tag(SHIENA), brow(0), eye(3), mouth(1), back(false))
Chara.spawnFacial(AYANO, STOP, 150, 680)
Chara.spawnFacial(SHIENA, HAPPY, -50, 380)
Massage.setBoxR()
SimpleMassage(
name_("シエナ"),
"ずっと前から私、",
"あなたと直接戦ってみたかったの。",
""
)

Scene(10)
Chara.img(tag(AYANO), brow(0), eye(3), mouth(1), back(false))
Chara.img(tag(SHIENA), brow(0), eye(3), mouth(0), back(true))
Chara.spawnFacial(AYANO, SWEAT, 80, 570)
Massage.setBoxL()
SimpleMassage(
name_("綾乃"),
"それはどうも・・・。",
"",
""
)

Scene(11)
Chara.img(tag(AYANO), brow(0), eye(1), mouth(0), back(true))
Chara.img(tag(SHIENA), brow(1), eye(1), mouth(1), back(false))
Chara.spawnFacial(AYANO, STOP, 150, 680)
Chara.spawnFacial(SHIENA, STOP, -150, 380)
Massage.setBoxR()
SimpleMassage(
name_("シエナ"),
"ごめんね、",
"",
""
)

Scene(12)
SimpleMassage(
name_("シエナ"),
"ごめんね、",
"その為にわざわざ虚界まで呼んじゃって",
""
)

Scene(13)
Chara.img(tag(AYANO), brow(0), eye(1), mouth(1), back(false))
Chara.img(tag(SHIENA), brow(1), eye(1), mouth(2), back(true))
Massage.setBoxL()
SimpleMassage(
name_("綾乃"),
"私たち、どこかで会ったことあるっけ？",
"",
""
)

Scene(14)
Chara.img(tag(AYANO), brow(0), eye(1), mouth(0), back(true))
Chara.img(tag(SHIENA), brow(1), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("シエナ"),
"そっか、覚えてるわけないよね・・・。",
"",
""
)

Scene(14)
SimpleMassage(
name_("シエナ"),
"そっか、覚えてるわけないよね・・・。",
"うん、大丈夫。",
""
)

Scene(15)
Chara.img(tag(SHIENA), brow(0), eye(3), mouth(1), back(false))
SimpleMassage(
name_("シエナ"),
"始めましょう。",
"私の考えた弾幕、魅せてあげる！",
""
)

Scene(16)
PlayBGM(11)
WaitAndSkip(1)

end

--@EndScript