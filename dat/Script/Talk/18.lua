dofile( './dat/Script/Library/Talker/Library.lua' )
--Ex�e���O�̉�b

function TalkScene()

AYANO=0
MISATO=1
AKAGI=2
HIME=3
IORIKO=4
KURO=5
ID_MAX = KURO

Scene(0)
SummonBoss(N08_KURO, 11)--�{�X����
Massage.setBoxR()
SimpleMassage(
name_("???"),
"�Ȃ񂩂�ׁ[�z�������Ă������I",
"",
""
)
WaitAndSkip(60)

Scene(1)
Chara.create_ID(ID_MAX)
Chara.spawn(KURO, 12, 1100, 800, 0.4)--�L�����̗����G��ǉ�
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
Chara.body(KURO, 2)
SimpleMassage(
name_("�N��"),
"�G�i�W�[�R�A�ւ�������Ⴂ",
"",
""
)

Scene(2)
Chara.spawn(AKAGI, 2, 170, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.img(tag(AKAGI), brow(1), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Massage.setBoxL()
Chara.spawnFacial(AKAGI, BLACK, 100, 600)
SimpleMassage(
name_("�ԏ�"),
"����A",
"�C�����������炢�̋��C�������B",
""
)

Scene(3)
Chara.spawnFacial(AKAGI, STOP, 100, 600)
Chara.img(tag(AKAGI), brow(2), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(2), eye(1), mouth(1), back(false))
Chara.setPos(KURO, 900, 900)
Chara.body(KURO, 0)
Massage.setBoxR()
SimpleMassage(
name_("�N��"),
"�L���E�L�H",
"�����A���̃E�B���X��",
"���C���ČĂ�ł���̂��H"
)

Scene(4)
Chara.hide(AKAGI)
Chara.spawn(AYANO, 0, 300, 900, 0.32)--�L�����̗����G��ǉ�
Chara.img(tag(AYANO), brow(1), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(1), eye(1), mouth(0), back(true))
Chara.setPos(KURO, 1100, 800)
Chara.body(KURO, 2)
Massage.setBoxL()
SimpleMassage(
name_("���T"),
"���ꂪ���A���E",
"�����킹�Ă���E�B���X�E�E�E�H",
""
)

Scene(5)
Chara.img(tag(AYANO), brow(1), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(2), eye(1), mouth(1), back(false))
Chara.setPos(KURO, 900, 900)
Chara.body(KURO, 0)
Massage.setBoxR()
SimpleMassage(
name_("�N��"),
"����A���̓E�B���X�ł͂Ȃ���",
"",
""
)

Scene(6)
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
SimpleMassage(
name_("�N��"),
"����A���̓E�B���X�ł͂Ȃ���",
"���̋��C�͂����ō���Ă����B",
""
)

Scene(7)
Chara.hide(AYANO)
Chara.spawn(MISATO, 1, 300, 940, 0.36)--�L�����̗����G��ǉ�
Chara.img(tag(MISATO), brow(1), eye(1), mouth(1), back(false))
Chara.img(tag(KURO), brow(0), eye(1), mouth(0), back(true))
Chara.setPos(KURO, 1100, 800)
Chara.body(KURO, 2)
Massage.setBoxL()
SimpleMassage(
name_("�݂���"),
"������Ƃ�������b���Ă�E�E�E�B",
"",
""
)

Scene(8)
Chara.hide(MISATO)
Chara.spawn(HIME, 3, 300, 930, 0.36)--�L�����̗����G��ǉ�
Chara.img(tag(HIME), brow(1), eye(3), mouth(1), back(false))
SimpleMassage(
name_("�Q"),
"�������̖ړI�́A���̃G�i�W�[�R�A��",
"",
""
)

Scene(9)
SimpleMassage(
name_("�Q"),
"�������̖ړI�́A���̃G�i�W�[�R�A��",
"�Ԃ��󂷂��Ƃł��I",
""
)

Scene(10)
Chara.hide(HIME)
Chara.spawn(IORIKO, 4, 300, 950, 0.35)--�L�����̗����G��ǉ�
Chara.img(tag(IORIKO), brow(0), eye(1), mouth(1), back(false))
Chara.spawnFacial(IORIKO, HAPPY, 0, 380)
SimpleMassage(
name_("����"),
"�Q�������I",
"",
""
)

Scene(11)
Chara.spawnFacial(IORIKO, STOP, 0, 480)
Chara.hide(IORIKO)
tag_type=AYANO
if(Player.getType() == 0)then tag_type=AYANO end
if(Player.getType() == 1)then tag_type=MISATO end
if(Player.getType() == 2)then tag_type=AKAGI end
if(Player.getType() == 3)then tag_type=HIME end
if(Player.getType() == 4)then tag_type=IORIKO end
Chara.img(tag_type, brow(0), eye(1), mouth(0), back(true))
Chara.img(tag(KURO), brow(0), eye(2), mouth(1), back(false))
Chara.setPos(KURO, 900, 900)
Chara.body(KURO, 0)
Massage.setBoxR()
SimpleMassage(
name_("�N��"),
"�t�t�b�I�ʔ����z�炾�I",
"",
""
)

Scene(12)
Chara.img(tag(KURO), brow(0), eye(1), mouth(1), back(false))
SimpleMassage(
name_("�N��"),
"���������X��",
"���܂𔄂���̂͌�������Ȃ��B",
""
)

Scene(13)
Chara.img(tag(KURO), brow(1), eye(1), mouth(1), back(false))
SimpleMassage(
name_("�N��"),
"���E�𒴂��Č��������I",
"",
""
)

Scene(14)
PlayBGM(14)
WaitAndSkip(1)

end

--@EndScript