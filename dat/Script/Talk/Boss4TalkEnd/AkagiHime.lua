dofile( './dat/Script/Library/Talker/Library.lua' )
--4�ʒe���I����̉�b

function AkagiHime()

HIME = 0
AKAGI = 1
NARUSIRU=2
FEATORIA=3
ID_MAX = FEATORIA

Scene(0)
Chara.create_ID(ID_MAX)
Chara.spawn(HIME, 3, 500, 1070, 0.47)--�L�����̗����G��ǉ�
Chara.brow(HIME, 0)
Chara.eye(HIME, 0)
Chara.mouth(HIME, 0)
Chara.isBack(HIME,true)
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
Chara.isBack(HIME,false)
Chara.isBack(NARUSIRU,true)
Chara.brow(HIME, 1)
Chara.mouth(HIME, 1)
Massage.setBoxL()
SimpleMassage(
name_("�Q"),
"���ĂĂ��A�����������Ղ���������E�E�E",
"",
""
)

Scene(2)
Chara.brow(HIME, 0)
Chara.eye(HIME, 3)
Chara.spawnFacial(HIME, HAPPY, 0, 480)
SimpleMassage(
name_("�Q"),
"���ĂĂ��A�����������Ղ���������E�E�E",
"���႟�A��������A���Ă����������I",
""
)

Scene(3)
Chara.mouth(HIME, 0)
Chara.eye(HIME, 0)
Chara.isBack(HIME,true)
SimpleMassage(
name_("�܂ɂ�"),
"��z�E�E�Ed����E�E�E!!",
"",
""
)

Scene(4)
Chara.spawnFacial(HIME, STOP, 0, 0)
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
Chara.isBack(HIME,false)
Chara.spawnFacial(HIME, ACCENT, 150, 680)
SimpleMassage(
name_(""),
"",
"",
""
)
WaitAndSkip(90)

Scene(7)
Chara.eye(HIME, 0)
Chara.mouth(HIME, 1)
Chara.spawnFacial(HIME, STOP, 0, 0)
SimpleMassage(
name_("�Q"),
"���A�ʐM�������̂��Ȃ��E�E�E�B",
"",
""
)

Scene(8)
Chara.isBack(HIME,true)
Chara.mouth(HIME, 0)
Chara.spawn(AKAGI, 2, 170, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.brow(AKAGI, 0)
Chara.eye(AKAGI, 1)
Chara.mouth(AKAGI, 1)
SimpleMassage(
name_("�ԏ�"),
"���O�݂������ˁB",
"",
""
)

Scene(9)
Chara.isBack(AKAGI,true)
Chara.isBack(HIME,false)
Chara.mouth(AKAGI, 0)
Chara.brow(HIME, 1)
Chara.mouth(HIME, 1)
SimpleMassage(
name_("�Q"),
"�Ђ���I�E�E�E�ԏ邿���B",
"",
""
)
WaitAndSkip(50)

Scene(10)
Chara.mouth(HIME, 0)
Chara.isBack(HIME,true)
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
Chara.isBack(HIME,false)
Chara.isBack(NARUSIRU,true)
Chara.mouth(NARUSIRU, 0)
Chara.brow(HIME, 0)
Chara.mouth(HIME, 1)
Massage.setBoxL()
SimpleMassage(
name_("�Q"),
"�����`��E�E�E�B",
"",
""
)

Scene(13)
SimpleMassage(
name_("�Q"),
"�����`��E�E�E�B",
"�Ƃ肠�����T�������Ⴂ�܂����",
""
)

Scene(14)
Chara.isBack(HIME,true)
Chara.isBack(AKAGI,false)
Chara.mouth(HIME, 0)
Chara.mouth(AKAGI, 1)
SimpleMassage(
name_("�ԏ�"),
"���v�H�������񂱂��𗣂�āA",
"�񕜂��������ǂ���B",
""
)

Scene(15)
Chara.mouth(AKAGI, 0)
Chara.isBack(HIME,false)
Chara.isBack(AKAGI,true)
SimpleMassage(
name_("�Q"),
"����I��������ˁI",
"���肪�Ƃ��A�ԏ邿���",
""
)

Scene(16)
Chara.hide(HIME)
Chara.isBack(AKAGI,false)
SimpleMassage(
name_("�ԏ�"),
"�E�E�E�E",
"",
""
)
WaitAndSkip(60)

Scene(17)
SimpleMassage(
name_("�ԏ�"),
"(�����A�񋶋C���Ȃ̂ɁA",
"���C���̃G���A�܂ŗU�����Ă������A",
"�ꉞ�x�����Ă������B)"
)

Scene(18)
Chara.hide(AKAGI)
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