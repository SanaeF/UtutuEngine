--1面弾幕前の会話

function Misato()

MISATO = 0
MATUMI = 1
ID_MAX = MATUMI

Scene(0)
Massage.setBoxR()
Chara.create_ID(ID_MAX)
Chara.spawn(MISATO, 1, 250, 1040, 0.46)--キャラの立ち絵を追加
Chara.eye(MISATO, 1)
Chara.mouth(MISATO, 0)
Chara.brow(MISATO, 1)
Chara.isBack(MISATO,true)
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
Chara.mouth(MISATO, 1)
Chara.isBack(MATUMI,true)
Chara.spawnFacial(MISATO, BLACK, -120, 490)
SimpleMassage(
name_("みさと"),
"使い魔の召喚、強化・・・。",
"",
""
)
Scene(2)
SimpleMassage(
name_("みさと"),
"使い魔の召喚、強化・・・。",
"その技術、実に興味深いね。",
""
)

Scene(3)
Chara.mouth(MISATO, 0)
Chara.mouth(MATUMI, 0)
Chara.eye(MATUMI, 3)
Chara.mouth(MATUMI, 1)
Chara.isBack(MISATO,true)
Chara.isBack(MATUMI,false)
Chara.spawnFacial(MISATO, STOP, 0, 0)
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