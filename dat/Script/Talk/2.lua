dofile( './dat/Script/Library/Talker/Library.lua' )
--2�ʒe���O�̉�b

function TalkScene()

AYANO = 0
AKAGI = 1
HIME = 2
EREMIRA = 3
ID_MAX = EREMIRA

Scene(0)
Chara.create_ID(ID_MAX)
Massage.setBoxL()
Chara.spawn(AYANO, 0, 250, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.eye(AYANO, 1)
Chara.mouth(AYANO, 0)
Chara.isBack(AYANO,true)
Chara.spawn(AKAGI, 2, 400, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.brow(AYANO, 0)
Chara.eye(AKAGI, 1)
Chara.mouth(AKAGI, 1)
SimpleMassage(
name_("�ԏ�"),
"���낻����t���ς�肻���B",
"",
""
)
Scene(1)
Chara.brow(AYANO, 1)
SimpleMassage(
name_("�ԏ�"),
"���낻����t���ς�肻���B",
"�}���Ȃ���I",
""
)
Scene(2)
Chara.mouth(AKAGI, 0)
Chara.isBack(AKAGI,true)
Massage.setBoxR()
SimpleMassage(
name_("???"),
"������Ƒ҂����I",
"",
""
)
Scene(3)
SummonBoss(N02_EREMIRA, 6)--�{�X����
WaitAndSkip(60)
Scene(4)
Chara.spawn(EREMIRA, 6, 1100, 800, 0.4)--�L�����̗����G��ǉ�
Chara.eye(EREMIRA, 1)
Chara.brow(EREMIRA, 2)
Chara.mouth(EREMIRA, 1)
Chara.spawnFacial(EREMIRA, ANGRY, 250, 480)
Massage.setBoxR()
SimpleMassage(
name_("???"),
"������Ƒ҂����I",
"���Ȃ��B�A�񋶋C���ˁH",
""
)
Scene(5)
Chara.isBack(AYANO,false)
Chara.isBack(EREMIRA,true)
Chara.brow(AYANO, 1)
Chara.mouth(AYANO, 1)
Chara.mouth(EREMIRA, 0)
Massage.setBoxL()
SimpleMassage(
name_("���T"),
"������m��Ȃ��B�ǂ��������H",
"",
""
)
Scene(6)
Chara.isBack(AYANO,true)
Chara.mouth(AYANO, 0)
SimpleMassage(
name_("�u�܂ɂ�v"),
"���E�̒��ɂ́A�����ɖ߂肽��",
"���Ă����ӌ��������܂��˂��B",
"���C�I�Ȓc�̂̎����Ǝv��"
)
Scene(7)
Chara.brow(EREMIRA, 0)
SimpleMassage(
name_("�u�܂ɂ�v"),
"�Ă��������ꁙ",
"",
""
)
Scene(8)
Chara.isBack(EREMIRA,false)
Chara.mouth(EREMIRA, 1)
Chara.brow(EREMIRA, 1)
Chara.spawnFacial(EREMIRA, ACCENT, 220, 550)
Massage.setBoxR()
SimpleMassage(
name_("???"),
"����H��������",
"���̎q�B�A���E�̖�����Ȃ��H",
""
)
Scene(9)
Chara.spawnFacial(EREMIRA, SWEAT, 200, 480)
SimpleMassage(
name_("???"),
"����H��������",
"���̎q�B�A���E�̖�����Ȃ��H",
"�Ȃ񂩈����Ȃ��E�E�E�B"
)
Scene(10)
Chara.brow(EREMIRA, 0)
Chara.eye(EREMIRA, 3)
Chara.spawnFacial(EREMIRA, HAPPY, 150, 380)
SimpleMassage(
name_("???"),
"���႟�C�C��I(�K��)",
"���̃��C�u�ɏ��҂��Ă�����I",
""
)
Scene(11)
Chara.isBack(AKAGI,false)
Chara.mouth(AKAGI, 1)
Chara.isBack(EREMIRA,true)
Chara.eye(EREMIRA, 0)
Chara.mouth(EREMIRA, 0)
Massage.setBoxL()
SimpleMassage(
name_("�ԏ�"),
"���A���������ăA�C�h���H",
"",
""
)
Scene(12)
Chara.hide(AKAGI)
Chara.spawn(HIME, 3, 400, 1070, 0.47)
Chara.eye(HIME, 1)
Chara.brow(HIME, 1)
Chara.mouth(HIME, 1)
SimpleMassage(
name_("�Q"),
"�o���ĂȂ��Ǝv���񂾂��ǁA",
"�Ȃ����������Ƃ���C��...",
""
)
Scene(13)
Chara.isBack(EREMIRA,false)
Chara.isBack(HIME,true)
Chara.eye(EREMIRA, 1)
Chara.brow(EREMIRA, 1)
Chara.mouth(EREMIRA, 1)
Chara.mouth(HIME, 0)
Chara.spawnFacial(EREMIRA, STOP, 0, 0)
Massage.setBoxR()
SimpleMassage(
name_("???"),
"�������A�؂Ȃ��ˁE�E�E�B",
"",
""
)
Scene(14)
Chara.brow(EREMIRA, 0)
SimpleMassage(
name_("???"),
"���̖��O�̓G���~���I",
"",
""
)
Scene(15)
SimpleMassage(
name_("�G���~��"),
"���̖��O�̓G���~���I",
"��낵���ˁI",
""
)
Scene(16)
Chara.body(EREMIRA,2)
SimpleMassage(
name_("�G���~��"),
"����ł͍s���܂��B",
"",
""
)
Scene(17)
SimpleMassage(
name_("�G���~��"),
"�O���X�̊D���A�C�h���I",
"",
""
)
Scene(18)
PlayBGM(4)
WaitAndSkip(1)

end

--@EndScript