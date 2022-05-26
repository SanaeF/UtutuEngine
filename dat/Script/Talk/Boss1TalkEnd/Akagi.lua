--1面弾幕前の会話

function Akagi()

AKAGI = 0
MATUMI = 1
ID_MAX = MATUMI

Scene(0)
Massage.setBoxR()
Chara.create_ID(ID_MAX)
Chara.spawn(AKAGI, 2, 250, 1000, 0.4)--キャラの立ち絵を追加
Chara.eye(AKAGI, 1)
Chara.mouth(AKAGI, 0)
Chara.brow(AKAGI, 1)
Chara.isBack(AKAGI,true)
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
Chara.mouth(AKAGI, 1)
Chara.isBack(MATUMI,true)
Chara.spawnFacial(AKAGI, BLACK, -120, 490)
SimpleMassage(
name_("赤城"),
"召喚はともかく、巨大化やら",
"強化やらしてた・・・。",
""
)
Scene(2)
SimpleMassage(
name_("綾乃"),
"初めて見たよ。ビックリ。",
"",
""
)

Scene(3)
Chara.mouth(AKAGI, 0)
Chara.mouth(MATUMI, 0)
Chara.eye(MATUMI, 3)
Chara.mouth(MATUMI, 1)
Chara.isBack(AKAGI,true)
Chara.isBack(MATUMI,false)
Chara.spawnFacial(AKAGI, STOP, 0, 0)
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