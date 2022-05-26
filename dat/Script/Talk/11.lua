dofile( './dat/Script/Library/Talker/Library.lua' )
--5面弾幕前の会話

function TalkScene()

AYANO = 0
FEATORIA=1
MATUMI=2
ID_MAX = MATUMI

Scene(0)
Chara.create_ID(ID_MAX)
SummonBoss(N05_FEATORIA, 4)--ボス召喚
WaitAndSkip(60)

Scene(1)
Chara.spawn(FEATORIA, 9, 1100, 600, 0.4)--キャラの立ち絵を追加
Chara.img(tag(FEATORIA), brow(1), eye(4), mouth(2), back(false))
Massage.setBoxR()
SimpleMassage(
name_("フェアトリア"),
"うぅっっ・・・。",
"",
""
)

Scene(2)
SimpleMassage(
name_("フェアトリア"),
"うぅっっ・・・。",
"また生えてきた・・・。",
""
)

Scene(3)
SimpleMassage(
name_("頭のキノコ"),
"ねぇ、いま取ったよね",
"",
""
)

Scene(4)
SimpleMassage(
name_("頭のキノコ"),
"ねぇ、いま取ったよね？",
"どさくさに紛れてもぎ取ったよね？",
""
)

Scene(5)
SimpleMassage(
name_("フェアトリア"),
"違うよ・・・。",
"ちょっとぶつかっちゃっただけ・・・。",
""
)

Scene(6)
SimpleMassage(
name_("頭のキノコ"),
"・・・。",
"",
""
)

Scene(7)
SimpleMassage(
name_("頭のキノコ"),
"・・・。",
"まぁいい、狂気が集まればこの不便な",
"身体ともおさらばだ・・・。"
)

Scene(8)
SimpleMassage(
name_("頭のキノコ"),
"ココからは俺が主体で動く。",
"狂気も良い具合に濃いから、",
"時間稼ぎに最適だ。"
)

Scene(9)
Chara.img(tag(FEATORIA), brow(0), eye(1), mouth(1), back(false))
SimpleMassage(
name_("フェアトリア"),
"はい・・・。わかりました・・・。",
"",
""
)

Scene(10)
Chara.spawn(MATUMI, 5, 1100, 600, 0.27)--キャラの立ち絵を追加
Chara.img(tag(FEATORIA), brow(0), eye(1), mouth(2), back(true))
Chara.img(tag(MATUMI), brow(2), eye(1), mouth(2), back(false))
SimpleMassage(
name_("マツミ"),
"姉様どうしたの！？",
"そのキノコ・・・やっぱり変！",
""
)

Scene(11)
SimpleMassage(
name_("マツミ"),
"さっきもぎ取ったのに、",
"また生えてきてるもん！",
""
)

Scene(12)
Chara.img(tag(MATUMI), brow(0), eye(1), mouth(2), back(true))
Chara.img(tag(FEATORIA), brow(0), eye(3), mouth(2), back(false))
SimpleMassage(
name_("フェアトリア"),
"マツミ、ダメ！！！！",
"",
""
)

Scene(13)
SimpleMassage(
name_("頭のキノコ"),
"・・・。",
"",
""
)


end

--@EndScript