--1�ʒe���I����̉�b

function Ioriko()

IORIKO = 0
MATUMI = 1
ID_MAX = MATUMI

Scene(0)
Massage.setBoxR()
Chara.create_ID(ID_MAX)
Chara.spawn(IORIKO, 4, 250, 1000, 0.4)
Chara.eye(IORIKO, 1)
Chara.mouth(IORIKO, 0)
Chara.brow(IORIKO, 1)
Chara.isBack(IORIKO,true)
Chara.spawn(MATUMI, 5, 1100, 600, 0.27)
Chara.eye(MATUMI, 1)
Chara.mouth(MATUMI, 2)
SimpleMassage(
name_("�}�c�~"),
"�������A",
"�������Ⴂ�܂����˂��B",
""
)
Scene(1)
Massage.setBoxL()
Chara.mouth(IORIKO, 1)
Chara.isBack(MATUMI,true)
Chara.spawnFacial(IORIKO, BLACK, -120, 490)
SimpleMassage(
name_("����"),
"��`�r�b�N�������B",
"",
""
)
Scene(2)
SimpleMassage(
name_("����"),
"��`�r�b�N�������B",
"�܂����g�������������Ă���",
"�Ȃ�āE�E�E�B"
)

Scene(3)
Chara.mouth(IORIKO, 0)
Chara.mouth(MATUMI, 0)
Chara.eye(MATUMI, 3)
Chara.mouth(MATUMI, 1)
Chara.isBack(IORIKO,true)
Chara.isBack(MATUMI,false)
Chara.spawnFacial(IORIKO, STOP, 0, 0)
Chara.spawnFacial(MATUMI, HAPPY, 10, -200)
Massage.setBoxR()
SimpleMassage(
name_("�}�c�~"),
"�����āA���ꂪ���̋����ًZ",
"�ł������",
""
)
Scene(4)
Chara.spawnFacial(MATUMI, STOP, 0, 0)
WaitAndSkip(1)

end

--@EndScript