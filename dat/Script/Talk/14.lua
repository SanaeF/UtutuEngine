dofile( './dat/Script/Library/Talker/Library.lua' )
--6面弾幕後(アリスモード)の会話

function TalkScene()
Massage.reset()
SHIENA=0
ID_MAX = SHIENA

Scene(0)
Chara.create_ID(ID_MAX)
Chara.spawn(SHIENA, 10, 1200, 900, 0.4)--キャラの立ち絵を追加
Chara.img(tag(SHIENA), brow(0), eye(1), mouth(1), back(false))
Chara.body(SHIENA,1)
Massage.setBoxR()
SimpleMassage(
name_("シエナ"),
"楽しかった。",
"",
""
)

Scene(1)
Chara.img(tag(SHIENA), brow(0), eye(1), mouth(1), back(false))
SimpleMassage(
name_("シエナ"),
"またいつでも来て良いからね？",
"",
""
)

end

--@EndScript