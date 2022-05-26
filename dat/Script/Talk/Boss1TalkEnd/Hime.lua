--1面弾幕終了後の会話

function Hime()

HIME = 0
MATUMI = 1
ID_MAX = MATUMI

Scene(0)
Massage.setBoxR()
Chara.create_ID(ID_MAX)
Chara.spawn(HIME, 3, 250, 1070, 0.47)
Chara.eye(HIME, 1)
Chara.mouth(HIME, 0)
Chara.brow(HIME, 1)
Chara.isBack(HIME,true)
Chara.spawn(MATUMI, 5, 1100, 600, 0.27)
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
Chara.mouth(HIME, 1)
Chara.isBack(MATUMI,true)
Chara.spawnFacial(HIME, BLACK, -120, 490)
SimpleMassage(
name_("媛"),
"驚愕した・・・。",
"",
""
)
Scene(2)
SimpleMassage(
name_("媛"),
"驚愕した・・・。",
"使い魔を強化したりしてきたん",
"ですけど・・・。"
)

Scene(3)
Chara.mouth(HIME, 0)
Chara.mouth(MATUMI, 0)
Chara.eye(MATUMI, 3)
Chara.mouth(MATUMI, 1)
Chara.isBack(HIME,true)
Chara.isBack(MATUMI,false)
Chara.spawnFacial(HIME, STOP, 0, 0)
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