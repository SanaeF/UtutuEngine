--7面弾幕前(アリスモード)の会話

function Hime()
HIME = 0
ALICE = 1
ID_MAX = ALICE

Scene(0)
SummonBoss(N07_ALICE, 7)--ボス召喚
WaitAndSkip(60)

Scene(1)
Chara.create_ID(ID_MAX)
Chara.spawn(ALICE, 11, 1200, 900, 0.4)--キャラの立ち絵を追加
Chara.body(ALICE,0)
Massage.setBoxR()
SimpleMassage(
name_("アリス"),
"うふふ、",
"狂気に染まったおじょうさん。",
""
)

Scene(2)
Chara.spawn(HIME, 3, 300, 930, 0.36)--キャラの立ち絵を追加
Chara.img(tag(HIME), brow(1), eye(2), mouth(1), back(false))
Chara.isBack(ALICE,true)
Chara.spawnFacial(HIME, BLACK, 100, 600)
Massage.setBoxL()
SimpleMassage(
name_("媛"),
"うえ〜ぇ、なんだかくらくらするよ。",
"",
""
)

Scene(3)
Chara.img(tag(HIME), brow(1), eye(2), mouth(0), back(true))
Chara.isBack(ALICE,false)
Chara.spawnFacial(HIME, STOP, 100, 600)
Massage.setBoxR()
SimpleMassage(
name_("アリス"),
"そうでしょうね。",
"",
""
)

Scene(4)
SimpleMassage(
name_("アリス"),
"あなたは今、視覚が狂っているもの。",
"",
""
)

Scene(5)
Chara.img(tag(HIME), brow(2), eye(1), mouth(1), back(false))
Chara.isBack(ALICE,true)
Massage.setBoxL()
Chara.spawnFacial(HIME, ANGRY, 100, 600)
SimpleMassage(
name_("媛"),
"狂気に酔うとつらいよぉ・・・。",
"",
""
)

Scene(6)
Chara.img(tag(HIME), brow(2), eye(1), mouth(0), back(true))
Chara.isBack(ALICE,false)
Massage.setBoxR()
SimpleMassage(
name_("アリス"),
"何度も繰り返される日々、",
"",
""
)

Scene(7)
Chara.body(ALICE,2)
SimpleMassage(
name_("アリス"),
"何度も繰り返される日々、",
"あなたに終えられるかしら・・・。",
""
)

Scene(8)
Chara.body(ALICE,2)
SimpleMassage(
name_("アリス"),
"くれぐれも",
"拾った武器の火力に甘えるなよ。",
""
)

end

--@EndScript