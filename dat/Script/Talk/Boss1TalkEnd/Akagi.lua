--1�ʒe���O�̉�b

function Akagi()

AKAGI = 0
MATUMI = 1
ID_MAX = MATUMI

Scene(0)
Massage.setBoxR()
Chara.create_ID(ID_MAX)
Chara.spawn(AKAGI, 2, 250, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.eye(AKAGI, 1)
Chara.mouth(AKAGI, 0)
Chara.brow(AKAGI, 1)
Chara.isBack(AKAGI,true)
Chara.spawn(id_(MATUMI), 5, 1100, 600, 0.27)
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
Chara.mouth(AKAGI, 1)
Chara.isBack(MATUMI,true)
Chara.spawnFacial(AKAGI, BLACK, -120, 490)
SimpleMassage(
name_("�ԏ�"),
"�����͂Ƃ������A���剻���",
"������炵�Ă��E�E�E�B",
""
)
Scene(2)
SimpleMassage(
name_("���T"),
"���߂Č�����B�r�b�N���B",
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