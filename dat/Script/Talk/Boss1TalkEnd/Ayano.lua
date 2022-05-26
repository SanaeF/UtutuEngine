--1面弾幕終了後の会話

function Ayano()

AYANO = 0
MATUMI = 1
ID_MAX = MATUMI

Scene(0)
Massage.setBoxR()
Chara.create_ID(ID_MAX)
Chara.spawn(id_(AYANO), 0, 250, 1000, 0.4)
Chara.eye(AYANO, 1)
Chara.mouth(AYANO, 0)
Chara.brow(AYANO, 1)
Chara.isBack(AYANO,true)
Chara.spawn(id_(MATUMI), 5, 1100, 600, 0.27)
Chara.eye(MATUMI, 1)
Chara.mouth(MATUMI, 2)
SimpleMassage(
name_("マツミ"),
"ありゃりゃ、",
"負けちゃいましたねぇ。",
""
)
Scene(1)
Massage.setBoxL()
Chara.mouth(AYANO, 1)
Chara.isBack(MATUMI,true)
Chara.spawnFacial(AYANO, BLACK, -120, 490)
SimpleMassage(
name_("綾乃"),
"何なのこの子・・・",
"",
""
)
Scene(2)
SimpleMassage(
name_("綾乃"),
"何なのこの子・・・",
"召喚したり強化したりしてきたん",
"だけど"
)

Scene(3)
Chara.mouth(AYANO, 0)
Chara.mouth(MATUMI, 0)
Chara.eye(MATUMI, 3)
Chara.mouth(MATUMI, 1)
Chara.isBack(AYANO,true)
Chara.isBack(MATUMI,false)
Chara.spawnFacial(AYANO, STOP, 0, 0)
Chara.spawnFacial(MATUMI, HAPPY, 10, -200)
Massage.setBoxR()
SimpleMassage(
name_("マツミ"),
"だって、それが私の強化異技",
"ですから♪",
""
)
Scene(4)
Chara.spawnFacial(MATUMI, STOP, 0, 0)
WaitAndSkip(1)

end

--@EndScript