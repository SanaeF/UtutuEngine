dofile( './dat/Script/Library/Talker/Library.lua' )
--4�ʒe���I����̉�b

function AyanoMisato()

AYANO = 0
MISATO = 1
NARUSIRU=2
FEATORIA=3
ID_MAX = FEATORIA

Scene(0)
Chara.create_ID(ID_MAX)
Chara.spawn(AYANO, 0, 500, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.brow(AYANO, 0)
Chara.eye(AYANO, 0)
Chara.mouth(AYANO, 0)
Chara.isBack(AYANO,true)
Chara.spawn(NARUSIRU, 8, 1100, 980, 0.45)--�L�����̗����G��ǉ�
Chara.brow(NARUSIRU, 1)
Chara.eye(NARUSIRU, 2)
Chara.mouth(NARUSIRU, 2)
Massage.setBoxR()
SimpleMassage(
name_("�i���V��"),
"���A���₵���E�E�E�B",
"",
""
)

Scene(1)
Chara.isBack(AYANO,false)
Chara.isBack(NARUSIRU,true)
Chara.brow(AYANO, 1)
Chara.mouth(AYANO, 1)
Massage.setBoxL()
SimpleMassage(
name_("���T"),
"���Ȃ�̗͏��Ղ���������݂����E�E�E",
"",
""
)

Scene(2)
Chara.brow(AYANO, 0)
Chara.eye(AYANO, 3)
Chara.spawnFacial(AYANO, HAPPY, 0, 480)
SimpleMassage(
name_("���T"),
"���Ȃ�̗͏��Ղ���������݂����E�E�E",
"���āA�R�R���狎���Ă��炦�邩�ȁH",
""
)

Scene(3)
Chara.mouth(AYANO, 0)
Chara.eye(AYANO, 0)
Chara.isBack(AYANO,true)
SimpleMassage(
name_("�܂ɂ�"),
"��z�E�E�Ed����E�E�E!!",
"",
""
)

Scene(4)
Chara.spawnFacial(AYANO, STOP, 0, 0)
SimpleMassage(
name_("�܂ɂ�"),
"��z�E�E�Ed����E�E�E!!",
"���E�E�E�E�E�E",
""
)

Scene(5)
SimpleMassage(
name_("�܂ɂ�"),
"��z�E�E�Ed����E�E�E!!",
"���E�E�E�E�E�E",
"�E�E�E�B"
)

Scene(6)
Chara.isBack(AYANO,false)
Chara.spawnFacial(AYANO, ACCENT, 150, 680)
SimpleMassage(
name_(""),
"",
"",
""
)
WaitAndSkip(90)

Scene(7)
Chara.eye(AYANO, 0)
Chara.mouth(AYANO, 1)
Chara.spawnFacial(AYANO, STOP, 0, 0)
SimpleMassage(
name_("���T"),
"����A�ʐM�������̂��ȁE�E�E�B",
"",
""
)

Scene(8)
Chara.isBack(AYANO,true)
Chara.mouth(AYANO, 0)
Chara.spawn(MISATO, 1, 170, 1040, 0.46)--�L�����̗����G��ǉ�
Chara.brow(MISATO, 0)
Chara.eye(MISATO, 0)
Chara.mouth(MISATO, 1)
SimpleMassage(
name_("�݂���"),
"���O�݂������ˁE�E�E�B",
"",
""
)

Scene(9)
Chara.isBack(MISATO,true)
Chara.isBack(AYANO,false)
Chara.mouth(MISATO, 0)
Chara.brow(AYANO, 1)
Chara.mouth(AYANO, 1)
SimpleMassage(
name_("���T"),
"�Ђ���I�E�E�E�݂��Ƃ��B",
"",
""
)
WaitAndSkip(50)

Scene(10)
Chara.mouth(AYANO, 0)
Chara.isBack(AYANO,true)
Chara.isBack(NARUSIRU,false)
Chara.brow(NARUSIRU, 1)
Chara.eye(NARUSIRU, 0)
Chara.mouth(NARUSIRU, 1)
Massage.setBoxR()
SimpleMassage(
name_("�i���V��"),
"���̕ӂ�͋��C���������G���A��",
"",
""
)

Scene(11)
SimpleMassage(
name_("�i���V��"),
"���̕ӂ�͋��C���������G���A��",
"�Ƃ͂����A���͂��������Ȃ����ǁE�E�E�B",
""
)

Scene(12)
Chara.isBack(AYANO,false)
Chara.isBack(NARUSIRU,true)
Chara.mouth(NARUSIRU, 0)
Chara.brow(AYANO, 0)
Chara.mouth(AYANO, 1)
Massage.setBoxL()
SimpleMassage(
name_("���T"),
"�����E�E�E�B",
"",
""
)

Scene(13)
SimpleMassage(
name_("���T"),
"�����E�E�E�B",
"�Ƃ肠�������̂܂ܒT�������Ă݂��",
""
)

Scene(14)
Chara.isBack(AYANO,true)
Chara.isBack(MISATO,false)
Chara.mouth(AYANO, 0)
Chara.mouth(MISATO, 1)
SimpleMassage(
name_("�݂���"),
"�������񂱂��𗣂�āA",
"�񕜂��������ǂ��ˁB",
""
)

Scene(15)
Chara.mouth(MISATO, 0)
Chara.isBack(AYANO,false)
Chara.isBack(MISATO,true)
SimpleMassage(
name_("���T"),
"�������[�B",
"���႟�s���Ă݂悤���B",
""
)

Scene(16)
Chara.hide(AYANO)
Chara.isBack(MISATO,false)
SimpleMassage(
name_("�݂���"),
"�E�E�E�E",
"",
""
)
WaitAndSkip(60)

Scene(17)
SimpleMassage(
name_("�݂���"),
"(����A�񋶋C���Ȃ̂ɁA",
"���C���̃G���A�܂ŗU�����Ă����́H)",
""
)

Scene(18)
Chara.hide(MISATO)
WaitAndSkip(30)

Scene(19)
Chara.isBack(NARUSIRU,false)
Massage.setBoxR()
SimpleMassage(
name_("�i���V��"),
"�E�E�E�B",
"",
""
)

Scene(20)
Chara.spawn(FEATORIA, 9, 350, 800, 0.4)--�L�����̗����G��ǉ�
Chara.brow(FEATORIA, 0)
Chara.eye(FEATORIA, 0)
Chara.mouth(FEATORIA, 0)
Chara.body(FEATORIA, 2)
Massage.setBoxL()
SimpleMassage(
name_("���̃L�m�R?"),
"���[���A������������񂾁B",
"",
""
)

Scene(21)
Chara.brow(NARUSIRU, 1)
Chara.eye(NARUSIRU, 2)
Chara.mouth(NARUSIRU, 2)
Massage.setBoxR()
SimpleMassage(
name_("�i���V��"),
"��������������",
"",
""
)

Scene(22)
Massage.setBoxL()
SimpleMassage(
name_("���̃L�m�R?"),
"�E�E�E�B",
"",
""
)

Scene(23)
SimpleMassage(
name_("���̃L�m�R?"),
"�M���e�B�[(�L��)!!!",
"",
""
)

Scene(24)
SimpleMassage(
name_("���̃L�m�R?"),
"�D�G�������R�m�������͎̂c�O���Ȃ��`",
"",
""
)

Scene(25)
SimpleMassage(
name_("���̃L�m�R?"),
"�D�G�������R�m�������͎̂c�O���Ȃ��`",
"�ł��d���Ȃ���ˁB",
""
)

Scene(26)
SimpleMassage(
name_("���̃L�m�R?"),
"�l�狶�C�E�B���X�ɏ|�˂�������A",
"�����̐l�Ԃɕ������񂾂���B",
""
)

Scene(27)
SimpleMassage(
name_("����"),
"�܂��āI�i���V��������",
"�����Ȃ���E�E�E�B",
""
)

Scene(28)
SimpleMassage(
name_("����"),
"�������āu����ȁv�����ǁE�E�E�B",
"",
""
)

Scene(29)
SimpleMassage(
name_("����"),
"�������āu����ȁv�����ǁE�E�E�B",
"�񋶋C���ɂ͎^�������E�E�E�B",
""
)

Scene(30)
SimpleMassage(
name_("���̃L�m�R?"),
"���H�������Ƃ������ӋC��",
"",
""
)

Scene(31)
SimpleMassage(
name_("���̃L�m�R?"),
"�܂��������A",
"���F�A���וi�̏������E�E�E�B",
"�]�v�Ȑ^���͂���񂶂�Ȃ����H"
)

Scene(32)
SimpleMassage(
name_("����"),
"�������E�E�E�B",
"",
""
)

Scene(33)
Chara.brow(NARUSIRU, 1)
Chara.eye(NARUSIRU, 2)
Chara.mouth(NARUSIRU, 2)
Massage.setBoxR()
SimpleMassage(
name_("�i���V��"),
"(���߂�ˁA���ɂ͉����ł��Ȃ���E�E�E�B)",
"",
""
)

end

--@EndScript