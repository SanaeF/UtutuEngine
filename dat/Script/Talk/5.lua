dofile( './dat/Script/Library/Talker/Library.lua' )
--3�ʒe���O�̉�b

function TalkScene()

AYANO = 0
HIME = 1
ALICE = 2
ID_MAX = ALICE

Scene(0)
Chara.create_ID(ID_MAX)
Chara.spawn(AYANO, 0, 250, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.isBack(AYANO,true)
Chara.eye(AYANO, 1)
Chara.mouth(AYANO, 0)
Massage.setBoxL()
SimpleMassage(
name_("�݂���"),
"�܂�ŋ��C�̔Z�x�Ȃ��",
"�����������̂悤�ɗD�낾�ˁB",
""
)
Scene(1)
Chara.isBack(AYANO,false)
Chara.eye(AYANO, 1)
Chara.mouth(AYANO, 1)
SimpleMassage(
name_("���T"),
"�m���ɁE�E�E�B",
"",
""
)
Scene(2)
Chara.spawnFacial(AYANO, HAPPY, 0, 480)
SimpleMassage(
name_("���T"),
"�m���ɁE�E�E�B",
"�R�R�ŉ����H�ׂĂ����H",
""
)
Scene(3)
Chara.isBack(AYANO,true)
Chara.mouth(AYANO, 0)
Chara.spawn(HIME, 3, 400, 1070, 0.47)
Chara.eye(HIME, 1)
Chara.brow(HIME, 1)
Chara.mouth(HIME, 1)
SimpleMassage(
name_("�Q"),
"���̓p�X�ŁB",
"",
""
)
Scene(4)
Chara.spawnFacial(AYANO, STOP, 0, 0)
Chara.isBack(AYANO,true)
Chara.mouth(AYANO, 0)
Chara.spawn(HIME, 3, 400, 1070, 0.47)
Chara.eye(HIME, 1)
Chara.brow(HIME, 1)
Chara.mouth(HIME, 1)
SimpleMassage(
name_("�Q"),
"���A�p�X...",
"����Ȏ��ԂɐH�ׂ��瑾�肻��",
"������E�E�E�B"
)
Scene(5)
Chara.isBack(HIME,true)
Chara.mouth(HIME, 0)
Massage.setBoxR()
SimpleMassage(
name_("???"),
"����ȂƂ���ŉ����Ă�́H",
"",
""
)
Scene(6)
SummonBoss(N03_ALICE, 7)
WaitAndSkip(60)
Scene(7)
Chara.spawn(ALICE, 7, 1100, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.eye(ALICE, 1)
Chara.mouth(ALICE, 1)
SimpleMassage(
name_("�A���X�E�V���b�g�E�X�J�[���b�g..."),
"�_������",
"���������ĂȂ����l�Ԃ�������",
"������B"
)
Scene(8)
SimpleMassage(
name_("�A���X�E�V���b�g(��)"),
"�m��Ȃ��́H",
"",
""
)
Scene(9)
SimpleMassage(
name_("�A���X�E�V���b�g(��)"),
"�m��Ȃ��́H",
"���C�Ɋ���������80%���ʂ񂾂�B",
""
)
Scene(10)
Chara.isBack(ALICE,true)
Chara.isBack(HIME,false)
Chara.mouth(HIME, 1)
Chara.brow(HIME, 2)
Chara.mouth(ALICE, 0)
Massage.setBoxL()
SimpleMassage(
name_("�Q"),
"��!?��������E�E�E",
"�^�O�H�����!�H",
""
)
Scene(11)
Chara.isBack(HIME,true)
Chara.mouth(HIME, 0)
SimpleMassage(
name_("�܂ɂ�"),
"�ӂ��ӂ��",
"",
""
)
Scene(12)
SimpleMassage(
name_("�܂ɂ�"),
"�ӂ��ӂ��",
"�m���Ă܂��Ƃ��I",
""
)
Scene(13)
SimpleMassage(
name_("�܂ɂ�"),
"�ӂ��ӂ��",
"�m���Ă܂��Ƃ��I",
"���ׂ̈̈ߑ��ƃ��N�`���ł�����!"
)
Scene(14)
SimpleMassage(
name_("�܂ɂ�"),
"���S���ē˂����񂶂����",
"���������I",
"�h���@"
)
Scene(15)
SimpleMassage(
name_("�܂ɂ�"),
"����A����[���o�C��",
"",
""
)
Scene(16)
Chara.isBack(HIME,false)
Chara.eye(HIME, 3)
Chara.brow(HIME, 1)
Chara.mouth(HIME, 1)
SimpleMassage(
name_("�Q"),
"�ӂ������E�E�E?",
"�ނ���s���ɂȂ����������(��)",
""
)
Scene(17)
Chara.mouth(HIME, 0)
Chara.isBack(HIME,true)
SimpleMassage(
name_("�܂ɂ�"),
"���A�{���ɑ��v�Ȃ�ŁB",
"�K�`�ł��B",
""
)
Scene(18)
Chara.eye(HIME, 1)
Chara.brow(HIME, 0)
Chara.brow(ALICE, 1)
Chara.mouth(ALICE, 1)
Chara.isBack(ALICE,false)
Massage.setBoxR()
SimpleMassage(
name_("�A���X�E�V���b�g(��)"),
"��������ׂ��Ă��������ȁH",
"",
""
)
Scene(19)
Chara.eye(ALICE, 2)
SimpleMassage(
name_("�A���X�E�V���b�g(��)"),
"�Ƃ͌����E�E�E",
"",
""
)
Scene(20)
SimpleMassage(
name_("�A���X�E�V���b�g(��)"),
"�Ƃ͌����E�E�E",
"�������ɗ������������",
"�ǂ��Ԃ��Ȃ�����"
)
Scene(21)
Chara.eye(ALICE, 1)
Chara.brow(ALICE, 2)
SimpleMassage(
name_("�A���X�E�V���b�g(��)"),
"�d���Ȃ���ˁB",
"�ł�������͂��Ă����邩��B",
""
)
Scene(22)
PlayBGM(6)
WaitAndSkip(1)

end

--@EndScript