dofile( './dat/Script/Library/Talker/Library.lua' )
--Ex�e����̉�b

function TalkScene()

AYANO=0
MISATO=1
AKAGI=2
HIME=3
IORIKO=4
KURO=5
ID_MAX = KURO

Scene(0)
Chara.create_ID(ID_MAX)
Chara.spawn(KURO, 12, 900, 900, 0.4)--�L�����̗����G��ǉ�
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("�N��"),
"�����񂾁B",
"",
""
)

Scene(1)
SimpleMassage(
name_("�N��"),
"�����񂾁B",
"���̎{�݂͍D���ɂ��Ă����",
"���܂�Ȃ��B"
)

Scene(2)
Chara.spawn(AKAGI, 2, 170, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.img(tag(AKAGI), brow(1), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Massage.setBoxL()
SimpleMassage(
name_("�ԏ�"),
"�ӊO�Ƃ�������B�키�K�v�������H",
"",
""
)

Scene(3)
Chara.img(tag(AKAGI), brow(1), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("�N��"),
"�V�G�i�̗p�����ς񂾗l�q�����A",
"",
""
)

Scene(4)
Chara.img(tag(AKAGI), brow(1), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("�N��"),
"�V�G�i�̗p�����ς񂾗l�q�����A",
"�������ꂾ���킦�Β��߂��t����B",
""
)

Scene(5)
Chara.hide(AKAGI)
Chara.spawn(AYANO, 0, 300, 900, 0.32)--�L�����̗����G��ǉ�
Chara.img(tag(AYANO), brow(0), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Massage.setBoxL()
SimpleMassage(
name_("���T"),
"���낢��m���Ă�񂾂�ˁA",
"",
""
)

Scene(6)
SimpleMassage(
name_("���T"),
"���낢��m���Ă�񂾂�ˁA",
"���C�Ƃ��ڂ����������Ă�B",
""
)

Scene(7)
Chara.img(tag(AYANO), brow(0), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(0), eye(2), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("�N��"),
"�ǂ����낤�B�������Ă��B",
"",
""
)

Scene(8)
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
SimpleMassage(
name_("�N��"),
"��X�A���C���͂��̋��C�̌�",
"",
""
)

Scene(9)
SimpleMassage(
name_("�N��"),
"�G�i�W�[�R�A�ɂ���Ă΂�",
"�T���ꂽ�ۗނŐl�g�������Ă���B",
""
)

Scene(10)
SimpleMassage(
name_("�N��"),
"���ꂾ���łȂ��A���̋ۗނ�",
"�u���E�E���v��v�̎�|����ɂȂ�",
"�̂������������Ă���B"
)


Scene(11)
Chara.hide(AYANO)
Chara.spawn(AKAGI, 2, 170, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Massage.setBoxL()
SimpleMassage(
name_("�ԏ�"),
"�悤����ɁA���̐����Ă������E��",
"�A�邽�߂̌����ŋ��C�E�B���X��",
"�������Ă������Ă킯�H"
)

Scene(12)
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("�N��"),
"�����A���̒ʂ肾�B",
"�������A���C�ƌ�����قǂ�",
"�����Ƃ͎v���Ă��Ȃ��������ȁB"
)

Scene(13)
SimpleMassage(
name_("�N��"),
"�Ⴍ���Đg���댯�ɂ��Ă���ҒB",
"�����E�ɕی삵�A",
"���S�Ȑ����𑗂�B"
)

Scene(14)
SimpleMassage(
name_("�N��"),
"�R�R�́A���������ꏊ�炵��",
"",
""
)

Scene(15)
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Massage.setBoxL()
SimpleMassage(
name_("�ԏ�"),
"�ւ��A�����ꏊ�����",
"",
""
)

Scene(16)
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(1), eye(2), mouth(3), back(false))
Massage.setBoxR()
SimpleMassage(
name_("�N��"),
"�ł��F�������ł͖����񂾁B",
"",
""
)

Scene(17)
Chara.img(tag(KURO), brow(1), eye(2), mouth(1), back(false))
SimpleMassage(
name_("�N��"),
"�ی삷��K�v�������n�Y�Ȃ̂ɁA",
"",
""
)

Scene(18)
Chara.img(tag(KURO), brow(2), eye(1), mouth(1), back(false))
SimpleMassage(
name_("�N��"),
"�ی삷��K�v�������n�Y�Ȃ̂ɁA",
"�����ȗ��R��t������",
"�^�΂�ė����z������񂾁B"
)

Scene(19)
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
SimpleMassage(
name_("�N��"),
"���C���͂��������z��̏W�܂�E�E�E�B",
"",
""
)

Scene(20)
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Massage.setBoxL()
SimpleMassage(
name_("�ԏ�"),
"����͒m��Ȃ������E�E�E�B",
"",
""
)

Scene(21)
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("�N��"),
"���āA�N�����͂��̋��C�E�B���X��",
"���̐��E�ƐڐG�ł���Ƃ�������",
"���������ȁH"
)

Scene(22)
Chara.hide(AKAGI)
Chara.spawn(MISATO, 1, 300, 940, 0.36)--�L�����̗����G��ǉ�
Chara.img(tag(MISATO), brow(0), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Massage.setBoxL()
SimpleMassage(
name_("�݂���"),
"��ʂ莑�����m�F�������ǁA",
"����ȏ��͂Ȃ�������B",
""
)

Scene(23)
Chara.img(tag(MISATO), brow(0), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("�N��"),
"�������B",
"",
""
)

Scene(24)
SimpleMassage(
name_("�N��"),
"�������B",
"�m���Ă���̂�",
"��X�����̂悤���ȁB"
)

Scene(25)
SimpleMassage(
name_("�N��"),
"�������̃G�i�W�[�R�A����������",
"�ɂ͂��łɉe����",
"�󂯂Ă�������A"
)

Scene(26)
SimpleMassage(
name_("�N��"),
"�ׂ��������͂킩���Ă��Ȃ��񂾂�",
"",
""
)

Scene(27)
SimpleMassage(
name_("�N��"),
"���̐��E�ŋN�������������",
"���ω����󂯌��̐��E�ƐڐG",
"�ł���悤�ɂȂ����炵���񂾁B"
)

Scene(28)
Chara.hide(MISATO)
Chara.spawn(AYANO, 0, 300, 900, 0.32)--�L�����̗����G��ǉ�
Chara.img(tag(AYANO), brow(1), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Chara.spawnFacial(AYANO, SWEAT, -100, 300)
Massage.setBoxL()
SimpleMassage(
name_("���T"),
"�F�X��������������Ȃ��E�E�E�B",
"",
""
)

Scene(29)
Chara.img(tag(AYANO), brow(1), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Chara.spawnFacial(AYANO, STOP, -100, 600)
Massage.setBoxR()
SimpleMassage(
name_("�N��"),
"�ł����̐��E�ƐڐG�ł��邱�Ƃ�",
"�m�M���������̂́A",
"�V�G�i�̃��K�}�}�ɕt�������������B"
)

Scene(30)
SimpleMassage(
name_("�N��"),
"��g��̓s�����ēz���B",
"",
""
)

Scene(31)
SimpleMassage(
name_("�N��"),
"��g��̓s�����ēz���B",
"�ق��̓z��������f���Ă������ˁB",
""
)

Scene(32)
Chara.hide(AYANO)
Chara.spawn(AKAGI, 2, 170, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Massage.setBoxL()
SimpleMassage(
name_("�ԏ�"),
"�ǂ�ȃ��K�}�}�ɕt���������́H",
"",
""
)

Scene(33)
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("�N��"),
"�������A",
"�u������x�������T�Ƃ��b���������v",
"�������ȁB"
)

Scene(34)
SimpleMassage(
name_("�N��"),
"�[���͕����Ȃ��������B",
"",
""
)

Scene(35)
SimpleMassage(
name_("�N��"),
"�����͊��ƒP���ŁA",
"",
""
)

Scene(36)
SimpleMassage(
name_("�N��"),
"�N��A",
"���N�O�ɍ~�����s�v�c��",
"�a����m���Ă��邩�H"
)

Scene(37)
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Massage.setBoxL()
SimpleMassage(
name_("�ԏ�"),
"�����A�Q�����킳�ꂽ�V���̎����ˁB",
"",
""
)

Scene(38)
Chara.hide(AKAGI)
Chara.spawn(HIME, 3, 300, 930, 0.36)--�L�����̗����G��ǉ�
Chara.img(tag(HIME), brow(1), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
SimpleMassage(
name_("�Q"),
"������Ɛԏ�E�E�E!?",
"",
""
)

Scene(39)
Chara.img(tag(HIME), brow(1), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("�N��"),
"���̜a���́A",
"�������E����ӂ��ė��Ƃ���",
"��ՂȂ񂾁B"
)

Scene(40)
SimpleMassage(
name_("�N��"),
"���C���܂܂����猳�̐��E�ɗ��āA",
"�{���ɋ�������B",
""
)

Scene(41)
SimpleMassage(
name_("�N��"),
"���ƁA���̜a���ɂ�",
"�莆�����ɂ������͂����B",
""
)

Scene(41)
Chara.hide(HIME)
Chara.spawn(AKAGI, 2, 170, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Chara.spawnFacial(AKAGI, ACCENT, 100, 600)
Massage.setBoxL()
SimpleMassage(
name_("�ԏ�"),
"���I���ꂩ�I",
"",
""
)

Scene(42)
Chara.hide(AKAGI)
Chara.spawn(AYANO, 0, 300, 900, 0.32)--�L�����̗����G��ǉ�
Chara.img(tag(AYANO), brow(0), eye(1), mouth(1), back(false))
Chara.spawnFacial(AKAGI, STOP, 100, 600)
SimpleMassage(
name_("���T"),
"�Ȃ�ď����Ă�������",
"",
""
)

Scene(43)
Chara.hide(AYANO)
Chara.spawn(AKAGI, 2, 170, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.img(tag(AKAGI), brow(0), eye(1), mouth(1), back(false))
SimpleMassage(
name_("�ԏ�"),
"�u���T�Ƌ��C�֘A�v�̓��e��������B",
"",
""
)

Scene(44)
Chara.hide(AKAGI)
Chara.spawn(MISATO, 1, 300, 940, 0.36)--�L�����̗����G��ǉ�
Chara.img(tag(MISATO), brow(1), eye(1), mouth(1), back(false))
SimpleMassage(
name_("�݂���"),
"������ȑO�A",
"�ԏ�͈��T��T���Ă��񂾂ˁB",
""
)

Scene(45)
Chara.hide(MISATO)
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("�N��"),
"�܂��A���������󂾁B",
"",
""
)

Scene(46)
SimpleMassage(
name_("�N��"),
"�X�g���X���U��",
"�t�������Ă�����������",
""
)

Scene(47)
SimpleMassage(
name_("�N��"),
"���肪�ƂȁB",
"",
""
)

Scene(48)
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(false))
SimpleMassage(
name_("�N��"),
"���́A�������ꏊ�ŉ��",
"",
""
)

end

--@EndScript