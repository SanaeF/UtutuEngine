dofile( './dat/Script/Library/Talker/Library.lua' )
--4�ʒe���I����̉�b

function Ioriko()

IORIKO = 0
MISATO = 1
NARUSIRU=2
FEATORIA=3
ID_MAX = FEATORIA

Scene(0)
Chara.create_ID(ID_MAX)
Chara.spawn(IORIKO, 4, 500, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.brow(IORIKO, 0)
Chara.eye(IORIKO, 0)
Chara.mouth(IORIKO, 0)
Chara.isBack(IORIKO,true)
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
Chara.isBack(IORIKO,false)
Chara.isBack(NARUSIRU,true)
Chara.brow(IORIKO, 1)
Chara.mouth(IORIKO, 1)
Massage.setBoxL()
SimpleMassage(
name_("����"),
"����A���Ȃ�̗͏��Ղ���������E�E�E",
"",
""
)

Scene(2)
Chara.brow(IORIKO, 0)
Chara.eye(IORIKO, 3)
Chara.spawnFacial(IORIKO, HAPPY, 0, 480)
SimpleMassage(
name_("����"),
"����A���Ȃ�̗͏��Ղ���������E�E�E",
"���Ă��āA�N�͂��A��̎��Ԃ���H",
""
)

Scene(3)
Chara.mouth(IORIKO, 0)
Chara.eye(IORIKO, 0)
Chara.isBack(IORIKO,true)
SimpleMassage(
name_("�܂ɂ�"),
"��z�E�E�Ed����E�E�E!!",
"",
""
)

Scene(4)
Chara.spawnFacial(IORIKO, STOP, 0, 0)
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
Chara.isBack(IORIKO,false)
Chara.spawnFacial(IORIKO, ACCENT, 150, 680)
SimpleMassage(
name_(""),
"",
"",
""
)
WaitAndSkip(90)

Scene(7)
Chara.eye(IORIKO, 0)
Chara.mouth(IORIKO, 1)
Chara.spawnFacial(IORIKO, STOP, 0, 0)
SimpleMassage(
name_("����"),
"�����A�ʐM�������Ȃ��E�E�E�B",
"�܂��������B",
""
)

Scene(8)
Chara.mouth(IORIKO, 0)
Chara.isBack(IORIKO,true)
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

Scene(9)
SimpleMassage(
name_("�i���V��"),
"���̕ӂ�͋��C���������G���A��",
"�Ƃ͂����A���͂��������Ȃ����ǁE�E�E�B",
""
)

Scene(10)
Chara.isBack(IORIKO,false)
Chara.isBack(NARUSIRU,true)
Chara.mouth(NARUSIRU, 0)
Chara.brow(IORIKO, 0)
Chara.mouth(IORIKO, 1)
Massage.setBoxL()
SimpleMassage(
name_("����"),
"�ւ��`(�����ĂȂ�)",
"",
""
)

Scene(11)
SimpleMassage(
name_("����"),
"�Ƃ肠�������̂܂ܒT�������Ă݂�����",
"",
""
)

Scene(12)
Chara.isBack(IORIKO,true)
Chara.isBack(MISATO,false)
Chara.mouth(IORIKO, 0)
Chara.mouth(MISATO, 1)
SimpleMassage(
name_("����"),
"�������񂱂��𗣂�āA",
"�񕜂��������ǂ����ȁH",
""
)

Scene(13)
Chara.mouth(MISATO, 0)
Chara.isBack(IORIKO,false)
Chara.isBack(MISATO,true)
SimpleMassage(
name_("����"),
"�������I",
"���႟�s���Ă݂邩�B",
""
)

Scene(14)
Chara.hide(IORIKO)
WaitAndSkip(30)

Scene(15)
Chara.isBack(NARUSIRU,false)
Massage.setBoxR()
SimpleMassage(
name_("�i���V��"),
"�E�E�E�B",
"",
""
)

Scene(16)
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

Scene(17)
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

Scene(18)
Massage.setBoxL()
SimpleMassage(
name_("���̃L�m�R?"),
"�E�E�E�B",
"",
""
)

Scene(19)
SimpleMassage(
name_("���̃L�m�R?"),
"�M���e�B�[(�L��)!!!",
"",
""
)

Scene(20)
SimpleMassage(
name_("���̃L�m�R?"),
"�D�G�������R�m�������͎̂c�O���Ȃ��`",
"",
""
)

Scene(21)
SimpleMassage(
name_("���̃L�m�R?"),
"�D�G�������R�m�������͎̂c�O���Ȃ��`",
"�ł��d���Ȃ���ˁB",
""
)

Scene(22)
SimpleMassage(
name_("���̃L�m�R?"),
"�l�狶�C�E�B���X�ɏ|�˂�������A",
"�����̐l�Ԃɕ������񂾂���B",
""
)

Scene(23)
SimpleMassage(
name_("����"),
"�܂��āI�i���V��������",
"�����Ȃ���E�E�E�B",
""
)

Scene(24)
SimpleMassage(
name_("����"),
"�������āu����ȁv�����ǁE�E�E�B",
"",
""
)

Scene(25)
SimpleMassage(
name_("����"),
"�������āu����ȁv�����ǁE�E�E�B",
"�񋶋C���ɂ͎^�������E�E�E�B",
""
)

Scene(26)
SimpleMassage(
name_("���̃L�m�R?"),
"���H�������Ƃ������ӋC��",
"",
""
)

Scene(27)
SimpleMassage(
name_("���̃L�m�R?"),
"�܂��������A",
"���F�A���וi�̏������E�E�E�B",
"�]�v�Ȑ^���͂���񂶂�Ȃ����H"
)

Scene(28)
SimpleMassage(
name_("����"),
"�������E�E�E�B",
"",
""
)

Scene(29)
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