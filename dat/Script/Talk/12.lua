dofile( './dat/Script/Library/Talker/Library.lua' )
--5面弾幕後の会話

function TalkScene()

FEATORIA=0
MATUMI=1
ID_MAX = MATUMI

Scene(0)
Chara.create_ID(ID_MAX)
Chara.spawn(FEATORIA, 9, 1100, 600, 0.4)--キャラの立ち絵を追加
Chara.img(tag(FEATORIA), brow(1), eye(2), mouth(2), back(false))
Massage.setBoxR()
SimpleMassage(
name_("フェアトリア"),
"・・・。",
"",
""
)

Scene(1)
Chara.spawn(MATUMI, 5, 200, 600, 0.27)--キャラの立ち絵を追加
Chara.img(tag(MATUMI), brow(1), eye(2), mouth(2), back(false))
Chara.img(tag(FEATORIA), brow(1), eye(2), mouth(2), back(true))
Massage.setBoxL()
SimpleMassage(
name_("マツミ"),
"・・・。",
"",
""
)

Scene(2)
Chara.img(tag(MATUMI), brow(1), eye(2), mouth(2), back(true))
Chara.img(tag(FEATORIA), brow(1), eye(2), mouth(2), back(false))
Massage.setBoxR()
SimpleMassage(
name_("頭のキノコ"),
"寝てるだけだよ。",
"",
""
)

Scene(3)
SimpleMassage(
name_("頭のキノコ"),
"ダメージも害も与えていないから",
"安心して。",
""
)

Scene(4)
Chara.img(tag(FEATORIA), brow(1), eye(1), mouth(2), back(false))
SimpleMassage(
name_("フェアトリア"),
"・・・。",
"",
""
)

Scene(5)
SimpleMassage(
name_("頭のキノコ"),
"僕たちは共存関係だ。",
"",
""
)

Scene(6)
SimpleMassage(
name_("頭のキノコ"),
"お互い傷を付け合うつもりはないよ。",
"",
""
)

Scene(7)
Chara.img(tag(FEATORIA), brow(1), eye(1), mouth(1), back(false))
SimpleMassage(
name_("フェアトリア"),
"そう・・・だね・・・。",
"",
""
)

Scene(8)
Chara.img(tag(FEATORIA), brow(1), eye(1), mouth(0), back(false))
SimpleMassage(
name_("頭のキノコ"),
"ほら、役目も終えたし",
"",
""
)

Scene(9)
SimpleMassage(
name_("頭のキノコ"),
"ほら、役目も終えたし",
"狂気集めようよ。",
""
)

Scene(10)
SimpleMassage(
name_("頭のキノコ"),
"ね？",
"",
""
)

end

--@EndScript