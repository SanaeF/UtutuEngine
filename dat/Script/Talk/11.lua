dofile( './dat/Script/Library/Talker/Library.lua' )
--5�ʒe���O�̉�b

function TalkScene()

AYANO = 0
FEATORIA=1
MATUMI=2
ID_MAX = MATUMI

Scene(0)
Chara.create_ID(ID_MAX)
SummonBoss(N05_FEATORIA, 4)--�{�X����
WaitAndSkip(60)

Scene(1)
Chara.spawn(FEATORIA, 9, 1100, 600, 0.4)--�L�����̗����G��ǉ�
Chara.img(tag(FEATORIA), brow(1), eye(4), mouth(2), back(false))
Massage.setBoxR()
SimpleMassage(
name_("�t�F�A�g���A"),
"���������E�E�E�B",
"",
""
)

Scene(2)
SimpleMassage(
name_("�t�F�A�g���A"),
"���������E�E�E�B",
"�܂������Ă����E�E�E�B",
""
)

Scene(3)
SimpleMassage(
name_("���̃L�m�R"),
"�˂��A���܎�������",
"",
""
)

Scene(4)
SimpleMassage(
name_("���̃L�m�R"),
"�˂��A���܎������ˁH",
"�ǂ������ɕ���Ă����������ˁH",
""
)

Scene(5)
SimpleMassage(
name_("�t�F�A�g���A"),
"�Ⴄ��E�E�E�B",
"������ƂԂ���������������E�E�E�B",
""
)

Scene(6)
SimpleMassage(
name_("���̃L�m�R"),
"�E�E�E�B",
"",
""
)

Scene(7)
SimpleMassage(
name_("���̃L�m�R"),
"�E�E�E�B",
"�܂������A���C���W�܂�΂��̕s�ւ�",
"�g�̂Ƃ�������΂��E�E�E�B"
)

Scene(8)
SimpleMassage(
name_("���̃L�m�R"),
"�R�R����͉�����̂œ����B",
"���C���ǂ���ɔZ������A",
"���ԉ҂��ɍœK���B"
)

Scene(9)
Chara.img(tag(FEATORIA), brow(0), eye(1), mouth(1), back(false))
SimpleMassage(
name_("�t�F�A�g���A"),
"�͂��E�E�E�B�킩��܂����E�E�E�B",
"",
""
)

Scene(10)
Chara.spawn(MATUMI, 5, 1100, 600, 0.27)--�L�����̗����G��ǉ�
Chara.img(tag(FEATORIA), brow(0), eye(1), mouth(2), back(true))
Chara.img(tag(MATUMI), brow(2), eye(1), mouth(2), back(false))
SimpleMassage(
name_("�}�c�~"),
"�o�l�ǂ������́I�H",
"���̃L�m�R�E�E�E����ς�ρI",
""
)

Scene(11)
SimpleMassage(
name_("�}�c�~"),
"����������������̂ɁA",
"�܂������Ă��Ă����I",
""
)

Scene(12)
Chara.img(tag(MATUMI), brow(0), eye(1), mouth(2), back(true))
Chara.img(tag(FEATORIA), brow(0), eye(3), mouth(2), back(false))
SimpleMassage(
name_("�t�F�A�g���A"),
"�}�c�~�A�_���I�I�I�I",
"",
""
)

Scene(13)
SimpleMassage(
name_("���̃L�m�R"),
"�E�E�E�B",
"",
""
)


end

--@EndScript