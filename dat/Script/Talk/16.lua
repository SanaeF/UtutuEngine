dofile( './dat/Script/Library/Talker/Library.lua' )
--7�ʒe����(�A���X���[�h)�̉�b

function TalkScene()
AYANO = 0
ALICE = 1
ID_MAX = ALICE

Scene(0)
Chara.create_ID(ID_MAX)
Chara.spawn(ALICE, 11, 1200, 900, 0.4)--�L�����̗����G��ǉ�
Chara.body(ALICE,0)
Massage.setBoxR()
SimpleMassage(
name_("�A���X"),
"�ǂ����Ƃ������Ă�����B",
"",
""
)

Scene(1)
SimpleMassage(
name_("�A���X"),
"���E�ŏo������l�����̎�������",
"�������Ƃ͂��邩���H",
""
)

Scene(2)
SimpleMassage(
name_("�A���X"),
"����́A���̐��E�E�E�E",
"�����ł͎��E�ƌĂԂ�ˁB",
""
)

Scene(3)
SimpleMassage(
name_("�A���X"),
"���E�Ŋ댯�ɂ��炳��Ă����ҒB��",
"���E�ŕی삷�邽�߂̃R�W�c�P�B",
""
)

Scene(4)
SimpleMassage(
name_("�A���X"),
"�����Č��ȋL����Y�ꂳ���āA",
"�����ň��S�ɕ�点��񂾁B",
""
)

Scene(5)
SimpleMassage(
name_("�A���X"),
"�ꕔ�̐l�������āE�E�E�B",
"",
""
)

Scene(6)
SimpleMassage(
name_("�A���X"),
"����������ˁB",
"",
""
)

Scene(7)
SimpleMassage(
name_("�A���X"),
"�c�O�Ȃ��狕�E�ɂ��Ă͓�΂���",
"������ׂ������Ƃ͕�����Ȃ���B",
""
)

Scene(8)
SimpleMassage(
name_("�A���X"),
"���āA",
"���͂��̋��E�ŋL����",
"�Ǘ��ł���̂����ǁB"
)

Scene(9)
SimpleMassage(
name_("�A���X"),
"���T�ɂ́A",
"�V�G�i�Ƃ̋L�������߂�����",
"�����悤���H"
)

Scene(10)
Chara.spawn(AYANO, 0, 300, 900, 0.32)
Chara.img(tag(AYANO), brow(2), eye(0), mouth(0), back(true))
Chara.body(ALICE,1)
SimpleMassage(
name_("�A���X"),
"�܂����̑��A",
"�ޏ��͋��E����A��Ȃ��Ȃ邯�ǁB",
""
)

Scene(11)
SimpleMassage(
name_("�A���X"),
"�ǂ�����H",
"",
""
)

Scene(12)
Chara.img(tag(AYANO), brow(0), eye(0), mouth(1), back(false))
Chara.spawnFacial(AYANO, HAPPY, 0, 380)
Chara.isBack(ALICE,true)
Chara.body(ALICE,0)
Massage.setBoxL()
SimpleMassage(
name_("���T"),
"�L���Ȃ�Ă���Ȃ����",
"�܂��V����������́B",
""
)

Scene(13)
Chara.img(tag(AYANO), brow(0), eye(0), mouth(0), back(true))
Chara.isBack(ALICE,false)
Chara.body(ALICE,0)
Massage.setBoxR()
SimpleMassage(
name_("�A���X"),
"�����A�ޏ��������]��ł�����B",
"",
""
)

Scene(14)
SimpleMassage(
name_("�A���X"),
"���i�����K���ɁE�E�E",
"",
""
)

Scene(15)
SimpleMassage(
name_("�A���X"),
"�ł��A�������̋��E�ɗ���̂�",
"���܂肨���߂��Ȃ���B",
""
)

Scene(16)
Chara.img(tag(AYANO), brow(0), eye(0), mouth(1), back(false))
Chara.spawnFacial(AYANO, STOP, 0, 380)
Chara.isBack(ALICE,true)
Massage.setBoxL()
SimpleMassage(
name_("���T"),
"�������A�܂������B",
"",
""
)

Scene(17)
Chara.img(tag(AYANO), brow(0), eye(0), mouth(0), back(true))
Chara.isBack(ALICE,false)
Massage.setBoxR()
SimpleMassage(
name_("�A���X"),
"�킩������B",
"",
""
)

Scene(18)
Chara.body(ALICE,1)
SimpleMassage(
name_("�A���X"),
"���̋��E�ɑς�����͂�",
"�^����悤�Ɍ����Ă�����B",
""
)

Scene(19)
Massage.setBoxGray()
Massage.setColor(1,55,255,55)
SimpleMassage(
name_(""),
"End 2�u���C�̑ϐ������v",
"",
""
)

end

--@EndScript