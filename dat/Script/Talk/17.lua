dofile( './dat/Script/Library/Talker/Library.lua' )
--Ex���{�X�̉�b

function TalkScene()

NARUSIRU=0
ID_MAX = NARUSIRU

Scene(0)
Chara.create_ID(ID_MAX)
SummonInterBoss(N04_NARSIRU, 2)
WaitAndSkip(60)

Scene(1)
Chara.spawn(NARUSIRU, 8, 1100, 980, 0.45)--�L�����̗����G��ǉ�
Chara.img(tag(NARUSIRU), brow(2), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("�i���V��"),
"���������͒ʂ��Ȃ��B",
"",
""
)
WaitAndSkip(120)


Scene(2)
SimpleMassage(
name_("�i���V��"),
"���������͒ʂ��Ȃ��B",
"�R�R�����͏���Ȃ���I",
""
)
WaitAndSkip(120)

Scene(3)
Chara.img(tag(NARUSIRU), brow(1), eye(2), mouth(1), back(false))
SimpleMassage(
name_("�i���V��"),
"���Ȃ���E�E�E�B",
"",
""
)
WaitAndSkip(120)

Scene(4)
Chara.img(tag(NARUSIRU), brow(2), eye(1), mouth(1), back(false))
SimpleMassage(
name_("�i���V��"),
"�����A",
"���`��q���ĉ䂪�g��R�₵�Ȃ����I",
""
)
WaitAndSkip(180)

end

--@EndScript