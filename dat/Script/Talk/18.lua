dofile( './dat/Script/Library/Talker/Library.lua' )
--Ex弾幕前の会話

function TalkScene()

AYANO=0
MISATO=1
AKAGI=2
HIME=3
IORIKO=4
KURO=5
ID_MAX = KURO

Scene(0)
SummonBoss(N08_KURO, 11)--ボス召喚
Massage.setBoxR()
SimpleMassage(
name_("???"),
"なんかやべー奴が入ってきたぞ！",
"",
""
)
WaitAndSkip(60)

Scene(1)
Chara.create_ID(ID_MAX)
Chara.spawn(KURO, 12, 1100, 800, 0.4)--キャラの立ち絵を追加
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Chara.body(KURO, 2)
SimpleMassage(
name_("クロ"),
"エナジーコアへいらっしゃい",
"",
""
)

Scene(2)
Chara.spawn(AKAGI, 2, 170, 1000, 0.4)--キャラの立ち絵を追加
Chara.img(tag(AKAGI), brow(1), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Massage.setBoxL()
Chara.spawnFacial(AKAGI, BLACK, 100, 600)
SimpleMassage(
name_("赤城"),
"うわ、",
"気持ち悪いくらいの狂気感じるよ。",
""
)

Scene(3)
Chara.spawnFacial(AKAGI, STOP, 100, 600)
Chara.img(tag(AKAGI), brow(2), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(2), eye(1), mouth(1), back(false))
Chara.setPos(KURO, 900, 900)
Chara.body(KURO, 0)
Massage.setBoxR()
SimpleMassage(
name_("クロ"),
"キョウキ？",
"あぁ、このウィルスを",
"狂気って呼んでいるのか？"
)

Scene(4)
Chara.hide(AKAGI)
Chara.spawn(AYANO, 0, 300, 900, 0.32)--キャラの立ち絵を追加
Chara.img(tag(AYANO), brow(1), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(1), eye(1), mouth(0), back(true))
Chara.setPos(KURO, 1100, 800)
Chara.body(KURO, 2)
Massage.setBoxL()
SimpleMassage(
name_("綾乃"),
"これが今、虚界",
"を狂わせているウィルス・・・？",
""
)

Scene(5)
Chara.img(tag(AYANO), brow(1), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(2), eye(1), mouth(1), back(false))
Chara.setPos(KURO, 900, 900)
Chara.body(KURO, 0)
Massage.setBoxR()
SimpleMassage(
name_("クロ"),
"いや、私はウィルスではないが",
"",
""
)

Scene(6)
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
SimpleMassage(
name_("クロ"),
"いや、私はウィルスではないが",
"その狂気はここで作られているよ。",
""
)

Scene(7)
Chara.hide(AYANO)
Chara.spawn(MISATO, 1, 300, 940, 0.36)--キャラの立ち絵を追加
Chara.img(tag(MISATO), brow(1), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Chara.setPos(KURO, 1100, 800)
Chara.body(KURO, 2)
Massage.setBoxL()
SimpleMassage(
name_("みさと"),
"さらっとすごい会話してる・・・。",
"",
""
)

Scene(8)
Chara.hide(MISATO)
Chara.spawn(HIME, 3, 300, 930, 0.36)--キャラの立ち絵を追加
Chara.img(tag(HIME), brow(1), eye(3), mouth(1), back(false))
SimpleMassage(
name_("媛"),
"私たちの目的は、そのエナジーコアを",
"",
""
)

Scene(9)
SimpleMassage(
name_("媛"),
"私たちの目的は、そのエナジーコアを",
"ぶっ壊すことです！",
""
)

Scene(10)
Chara.hide(HIME)
Chara.spawn(IORIKO, 4, 300, 950, 0.35)--キャラの立ち絵を追加
Chara.img(tag(IORIKO), brow(0), eye(1), mouth(1), back(false))
Chara.spawnFacial(IORIKO, HAPPY, 0, 380)
SimpleMassage(
name_("庵狐"),
"参ったか！",
"",
""
)

Scene(11)
Chara.spawnFacial(IORIKO, STOP, 0, 480)
Chara.hide(IORIKO)
tag_type=AYANO
if(Player.getType() == 0)then tag_type=AYANO end
if(Player.getType() == 1)then tag_type=MISATO end
if(Player.getType() == 2)then tag_type=AKAGI end
if(Player.getType() == 3)then tag_type=HIME end
if(Player.getType() == 4)then tag_type=IORIKO end
Chara.img(tag_type, brow(0), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(0), eye(2), mouth(1), back(false))
Chara.setPos(KURO, 900, 900)
Chara.body(KURO, 0)
Massage.setBoxR()
SimpleMassage(
name_("クロ"),
"フフッ！面白い奴らだ！",
"",
""
)

Scene(12)
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
SimpleMassage(
name_("クロ"),
"こうも堂々と",
"喧嘩を売られるのは嫌いじゃない。",
""
)

Scene(13)
Chara.img(tag(KURO), brow(1), eye(1), mouth(1), back(false))
SimpleMassage(
name_("クロ"),
"限界を超えて撃ち狂え！",
"",
""
)

Scene(14)
PlayBGM(14)
WaitAndSkip(1)

end

--@EndScript