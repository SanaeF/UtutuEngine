--1�ʒe���O�̉�b

function Misato()

MISATO = 0
MATUMI = 1
ID_MAX = MATUMI

Scene(0)
Chara.create_ID(ID_MAX)
Massage.setBoxL()
Chara.spawn(MISATO, 1, 250, 1040, 0.46)--�L�����̗����G��ǉ�
Chara.eye(MISATO, 0)
Chara.mouth(MISATO, 1)
SimpleMassage(
name_("�݂���"),
"���E�̖���͂��ꂢ���ˁB",
"���x�A�݂�Ȃł��Ԍ������",
""
)
Scene(1)
Chara.eye(MISATO, 1)
Chara.mouth(MISATO, 0)
Chara.spawnFacial(MISATO, ACCENT, 150, 720)
Chara.isBack(MISATO,true)
SimpleMassage(
name_("�u�܂ɂ�v"),
"��߂Ƃ����ق����ǂ��ł���E�E�E�B",
"",
""
)
Scene(2)
Chara.spawnFacial(MISATO, STOP, 0, 0)
SimpleMassage(
name_("�u�܂ɂ�v"),
"��߂Ƃ����ق����ǂ��ł���E�E�E�B",
"�����͋��C�E�B���X�ł��I",
""
)
Scene(3)
SimpleMassage(
name_("�u�܂ɂ�v"),
"���ُ̈펖�Ԃ�",
"�����̍����݂����Ȃ��̂ł��I",
""
)
Scene(4)
SummonBoss(N01_MATUMI, 5)--�{�X����
Chara.spawn(MATUMI, 5, 1100, 600, 0.27)--�L�����̗����G��ǉ�
Chara.eye(MATUMI, 1)
Chara.mouth(MATUMI, 1)
Massage.setBoxR()
SimpleMassage(
name_("�}�c�~"),
"�N�����N����",
"",
""
)
Scene(5)
SimpleMassage(
name_("�}�c�~"),
"�N�����N����",
"����Ȗ钆�ɉ����Ă��ł��H",
""
)
Scene(6)
Chara.eye(MATUMI, 3)
SimpleMassage(
name_("�}�c�~"),
"�N�����N����",
"����Ȗ钆�ɉ����Ă��ł��H",
"�s�R�҂ł�����"
)
Scene(7)
Chara.mouth(MATUMI, 0)
Chara.isBack(MISATO,false)
Chara.isBack(MATUMI,true)
Chara.mouth(MISATO, 1)
Massage.setBoxL()
SimpleMassage(
name_("�݂���"),
"�킽�����āA����Ȃɉ������̂��Ȃ��B",
"���Ȃ����̉������I�[���͖�����",
"�v�����ǁE�E�E�B"
)
Scene(8)
Chara.mouth(MISATO, 0)
Chara.eye(MATUMI, 1)
Chara.mouth(MATUMI, 2)
Chara.brow(MATUMI, 1)
Chara.isBack(MATUMI,false)
Chara.isBack(MISATO,true)
Chara.spawnFacial(MATUMI, SWEAT, -80, -280)
Massage.setBoxR()
SimpleMassage(
name_("�}�c�~"),
"������āA�ǂ�ȃI�[���ł����H",
"",
""
)
Scene(9)
Chara.mouth(MATUMI, 1)
Chara.brow(MATUMI, 0)
Chara.spawnFacial(MATUMI, STOP, 0, 0)
SimpleMassage(
name_("�}�c�~"),
"������āA�ǂ�ȃI�[���ł����H",
"�������̃I�[���ł����ˁ�",
""
)
Scene(10)
Chara.mouth(MATUMI, 0)
Chara.isBack(MATUMI,true)
Massage.setBoxL()
SimpleMassage(
name_("�u�܂ɂ�v"),
"�������E�E�E�Ȃ�قǁB",
"",
""
)
Scene(11)
SimpleMassage(
name_("�u�܂ɂ�v"),
"�������E�E�E�Ȃ�قǁB",
"���C�E�B���X�̊����҂�������",
"���Č����Ă�̂ˁB"
)
Scene(12)
Chara.mouth(MATUMI, 1)
Chara.isBack(MATUMI,false)
PlayBGM(2)
Chara.eye(MATUMI, 3)
Massage.setBoxR()
SimpleMassage(
name_("�}�c�~"),
"�͂���",
"",
""
)
Scene(13)
SimpleMassage(
name_("�}�c�~"),
"�͂���",
"���ꂶ�႟���������E�E�E",
""
	)
Scene(14)
Chara.eye(MATUMI, 0)
Chara.brow(MATUMI, 2)
SimpleMassage(
name_("�}�c�~"),
"�n�߂��Ⴂ�܂��ˁ�",
"",
""
)

end

--@EndScript