--7�ʒe���O(�A���X���[�h)�̉�b

function Ayano()
AYANO = 0
ALICE = 1
ID_MAX = ALICE

Scene(0)
SummonBoss(N07_ALICE, 7)--�{�X����
WaitAndSkip(60)

Scene(1)
Chara.create_ID(ID_MAX)
Chara.spawn(ALICE, 11, 1200, 900, 0.4)--�L�����̗����G��ǉ�
Chara.body(ALICE,0)
Massage.setBoxR()
SimpleMassage(
name_("�A���X"),
"���ӂӁA",
"���C�ɐ��܂��������傤����B",
""
)

Scene(2)
Chara.spawn(AYANO, 0, 300, 900, 0.32)--�L�����̗����G��ǉ�
Chara.img(tag(AYANO), brow(1), eye(2), mouth(1), back(false))
Chara.isBack(ALICE,true)
Chara.spawnFacial(AYANO, BLACK, 100, 600)
Massage.setBoxL()
SimpleMassage(
name_("���T"),
"�Ȃ񂾂����炭�炷��B",
"",
""
)

Scene(3)
Chara.img(tag(AYANO), brow(1), eye(2), mouth(0), back(true))
Chara.isBack(ALICE,false)
Chara.spawnFacial(AYANO, STOP, 100, 600)
Massage.setBoxR()
SimpleMassage(
name_("�A���X"),
"�����ł��傤�ˁB",
"",
""
)

Scene(4)
SimpleMassage(
name_("�A���X"),
"���Ȃ��͍��A���o�������Ă�����́B",
"",
""
)

Scene(5)
Chara.img(tag(AYANO), brow(2), eye(1), mouth(1), back(false))
Chara.isBack(ALICE,true)
Massage.setBoxL()
Chara.spawnFacial(AYANO, ANGRY, 100, 600)
SimpleMassage(
name_("���T"),
"�������A�����������傫��������B",
"",
""
)

Scene(6)
Chara.img(tag(AYANO), brow(2), eye(1), mouth(0), back(true))
Chara.isBack(ALICE,false)
Massage.setBoxR()
SimpleMassage(
name_("�A���X"),
"���x���J��Ԃ������X�A",
"",
""
)

Scene(7)
Chara.body(ALICE,2)
SimpleMassage(
name_("�A���X"),
"���x���J��Ԃ������X�A",
"���Ȃ��ɏI�����邩����E�E�E�B",
""
)

Scene(8)
Chara.body(ALICE,2)
SimpleMassage(
name_("�A���X"),
"���ꂮ���",
"�E��������̉Η͂ɊÂ���Ȃ�B",
""
)
end

--@EndScript