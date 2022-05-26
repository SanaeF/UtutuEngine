dofile( './dat/Script/Library/Talker/Library.lua' )
--7面弾幕後(アリスモード)の会話

function TalkScene()
AYANO = 0
ALICE = 1
ID_MAX = ALICE

Scene(0)
Chara.create_ID(ID_MAX)
Chara.spawn(ALICE, 11, 1200, 900, 0.4)--キャラの立ち絵を追加
Chara.body(ALICE,0)
Massage.setBoxR()
SimpleMassage(
name_("アリス"),
"良いことを教えてあげる。",
"",
""
)

Scene(1)
SimpleMassage(
name_("アリス"),
"虚界で出会った人たちの死因情報を",
"見たことはあるかい？",
""
)

Scene(2)
SimpleMassage(
name_("アリス"),
"あれは、実の世界・・・",
"ここでは実界と呼ぶわね。",
""
)

Scene(3)
SimpleMassage(
name_("アリス"),
"実界で危険にさらされている若者達を",
"虚界で保護するためのコジツケ。",
""
)

Scene(4)
SimpleMassage(
name_("アリス"),
"そして嫌な記憶を忘れさせて、",
"ここで安全に暮らせるんだ。",
""
)

Scene(5)
SimpleMassage(
name_("アリス"),
"一部の人を除いて・・・。",
"",
""
)

Scene(6)
SimpleMassage(
name_("アリス"),
"太っ腹だよね。",
"",
""
)

Scene(7)
SimpleMassage(
name_("アリス"),
"残念ながら虚界については謎ばかり",
"だから細かいことは分からないわ。",
""
)

Scene(8)
SimpleMassage(
name_("アリス"),
"さて、",
"私はこの虚界で記憶を",
"管理できるのだけど。"
)

Scene(9)
SimpleMassage(
name_("アリス"),
"綾乃には、",
"シエナとの記憶を取り戻させて",
"あげようか？"
)

Scene(10)
Chara.spawn(AYANO, 0, 300, 900, 0.32)
Chara.img(tag(AYANO), brow(2), eye(0), mouth(0), back(true))
Chara.body(ALICE,1)
SimpleMassage(
name_("アリス"),
"まぁその代り、",
"彼女は虚界から帰れなくなるけど。",
""
)

Scene(11)
SimpleMassage(
name_("アリス"),
"どうする？",
"",
""
)

Scene(12)
Chara.img(tag(AYANO), brow(0), eye(0), mouth(1), back(false))
Chara.spawnFacial(AYANO, HAPPY, 0, 380)
Chara.isBack(ALICE,true)
Chara.body(ALICE,0)
Massage.setBoxL()
SimpleMassage(
name_("綾乃"),
"記憶なんていらないわ♪",
"また新しく作れるもの。",
""
)

Scene(13)
Chara.img(tag(AYANO), brow(0), eye(0), mouth(0), back(true))
Chara.isBack(ALICE,false)
Chara.body(ALICE,0)
Massage.setBoxR()
SimpleMassage(
name_("アリス"),
"そう、彼女もそれを望んでいたわ。",
"",
""
)

Scene(14)
SimpleMassage(
name_("アリス"),
"末永くお幸せに・・・",
"",
""
)

Scene(15)
SimpleMassage(
name_("アリス"),
"でも、もうこの虚界に来るのは",
"あまりお勧めしないわ。",
""
)

Scene(16)
Chara.img(tag(AYANO), brow(0), eye(0), mouth(1), back(false))
Chara.spawnFacial(AYANO, STOP, 0, 380)
Chara.isBack(ALICE,true)
Massage.setBoxL()
SimpleMassage(
name_("綾乃"),
"いいえ、また来るわ。",
"",
""
)

Scene(17)
Chara.img(tag(AYANO), brow(0), eye(0), mouth(0), back(true))
Chara.isBack(ALICE,false)
Massage.setBoxR()
SimpleMassage(
name_("アリス"),
"わかったわ。",
"",
""
)

Scene(18)
Chara.body(ALICE,1)
SimpleMassage(
name_("アリス"),
"この虚界に耐えられる力を",
"与えるように言っておくわ。",
""
)

Scene(19)
Massage.setBoxGray()
Massage.setColor(1,55,255,55)
SimpleMassage(
name_(""),
"End 2「狂気の耐性持ち」",
"",
""
)

end

--@EndScript