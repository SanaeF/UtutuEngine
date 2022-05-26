dofile( './dat/Script/Library/Talker/Library.lua' )
--Ex中ボスの会話

function TalkScene()

NARUSIRU=0
ID_MAX = NARUSIRU

Scene(0)
Chara.create_ID(ID_MAX)
SummonInterBoss(N04_NARSIRU, 2)
WaitAndSkip(60)

Scene(1)
Chara.spawn(NARUSIRU, 8, 1100, 980, 0.45)--キャラの立ち絵を追加
Chara.img(tag(NARUSIRU), brow(2), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("ナルシル"),
"ここから先は通さない。",
"",
""
)
WaitAndSkip(120)


Scene(2)
SimpleMassage(
name_("ナルシル"),
"ここから先は通さない。",
"ココだけは譲れないわ！",
""
)
WaitAndSkip(120)

Scene(3)
Chara.img(tag(NARUSIRU), brow(1), eye(2), mouth(1), back(false))
SimpleMassage(
name_("ナルシル"),
"守らなきゃ・・・。",
"",
""
)
WaitAndSkip(120)

Scene(4)
Chara.img(tag(NARUSIRU), brow(2), eye(1), mouth(1), back(false))
SimpleMassage(
name_("ナルシル"),
"さぁ、",
"正義を賭けて我が身を燃やしなさい！",
""
)
WaitAndSkip(180)

end

--@EndScript