--1�ʒe���O�̉�b

function Ioriko()

IORIKO = 0
MATUMI = 1
ID_MAX = MATUMI

Scene(0)
Chara.create_ID(ID_MAX)
Massage.setBoxL()
Chara.spawn(IORIKO, 4, 250, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.eye(IORIKO, 3)
Chara.mouth(IORIKO, 1)
Chara.spawnFacial(IORIKO, HAPPY, 0, 480)
SimpleMassage(
name_("����"),
"�������I",
"���E�̍����x���ɂȂ�ƁA",
"���R�Ƀ��C�g�A�b�v�����񂾂�"
)
Scene(1)
Chara.eye(IORIKO, 1)
Chara.mouth(IORIKO, 0)
Chara.spawnFacial(IORIKO, ACCENT, 150, 680)
Chara.isBack(IORIKO,true)
SimpleMassage(
name_("�u�܂ɂ�v"),
"�Ⴂ�܂���I",
"",
""
)
Scene(2)
Chara.spawnFacial(IORIKO, STOP, 0, 0)
SimpleMassage(
name_("�u�܂ɂ�v"),
"�Ⴂ�܂���I",
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
Chara.isBack(IORIKO,false)
Chara.isBack(MATUMI,true)
Chara.mouth(IORIKO, 1)
Chara.eye(IORIKO, 3)
Massage.setBoxL()
SimpleMassage(
name_("����"),
"�s�R�ғ��m�A���ǂ����悤",
"�ЁX�������������",
""
)
Scene(8)
Chara.mouth(IORIKO, 0)
Chara.eye(IORIKO, 0)
Chara.eye(MATUMI, 1)
Chara.mouth(MATUMI, 1)
Chara.brow(MATUMI, 1)
Chara.isBack(MATUMI,false)
Chara.isBack(IORIKO,true)
Chara.spawnFacial(MATUMI, SWEAT, -80, -280)
Massage.setBoxR()
SimpleMassage(
name_("�}�c�~"),
"���ǂ��͂ł��Ȃ��ł��˂���",
"",
""
)
Scene(9)
Chara.mouth(MATUMI, 1)
Chara.brow(MATUMI, 0)
Chara.spawnFacial(MATUMI, STOP, 0, 0)
SimpleMassage(
name_("�}�c�~"),
"���ǂ��͂ł��Ȃ��ł��˂���",
"���������Ă鎄�ƁA���܂�",
"���ǂ��Ȃ�Ȃ������ǂ��ł���H"
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