dofile( './dat/Script/Library/Talker/Library.lua' )

function Ioriko()--4�ʒe���O�̉�b

IORIKO = 0
NARUSIRU=1
ID_MAX = NARUSIRU

Scene(0)
Chara.create_ID(ID_MAX)
Massage.setBoxR()
SimpleMassage(
name_("???"),
"�����I�~�܂�Ȃ����I",
"",
""
)

Scene(1)
SummonBoss(N04_NARSIRU, 7)--�{�X����
WaitAndSkip(60)

Scene(2)
Chara.spawn(IORIKO, 4, 250, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.brow(IORIKO, 0)
Chara.eye(IORIKO, 0)
Chara.mouth(IORIKO, 0)
Chara.isBack(IORIKO,true)
Chara.spawn(NARUSIRU, 8, 1100, 980, 0.45)--�L�����̗����G��ǉ�
Chara.brow(NARUSIRU, 2)
Chara.eye(NARUSIRU, 0)
Chara.mouth(NARUSIRU, 1)
SimpleMassage(
name_("�i���V��"),
"���ƂȂ������̓��������Ԃ���",
"���炦�Ȃ�������!",
""
)

Scene(3)
Chara.isBack(IORIKO,false)
Chara.brow(IORIKO, 2)
Chara.mouth(IORIKO, 1)
Chara.isBack(NARUSIRU,true)
Chara.mouth(NARUSIRU, 0)
Massage.setBoxL()
SimpleMassage(
name_("����"),
"����͂ł��ȂȂ��B",
"�R�R�ɂ͋��C�E�B���X�̏���",
"���ӂ�Ă���炵����"
)

Scene(4)
Chara.isBack(IORIKO,true)
Chara.mouth(IORIKO, 0)
SimpleMassage(
name_("�܂ɂ�"),
"�����ł��I",
"",
""
)

Scene(4)
Chara.isBack(IORIKO,true)
SimpleMassage(
name_("�܂ɂ�"),
"�����ł��I",
"�����̍�����O��I�ɒ��׏グ�āA",
""
)

Scene(5)
Chara.isBack(IORIKO,true)
SimpleMassage(
name_("�܂ɂ�"),
"���̕s�тȐ킢��",
"����₵�ɂ��Ă��܂�����!",
""
)

Scene(6)
Chara.isBack(IORIKO,true)
Chara.brow(IORIKO, 0)
Chara.eye(IORIKO, 0)
Chara.mouth(IORIKO, 0)
SimpleMassage(
name_("�܂ɂ�"),
"�ז����I�����E�B���X�M��!",
"",
""
)

Scene(7)
Chara.isBack(IORIKO,true)
SimpleMassage(
name_("�܂ɂ�"),
"�ז����I�����E�B���X�M��!",
"���΂炭�ق��Ď��l����!",
""
)

Scene(8)
Chara.isBack(NARUSIRU,false)
Chara.brow(NARUSIRU, 1)
Chara.eye(NARUSIRU, 0)
Chara.mouth(NARUSIRU, 1)
Massage.setBoxR()
SimpleMassage(
name_("�i���V��"),
"����A���������B",
"���������ǂ��̌��������?",
""
)

Scene(9)
Chara.isBack(NARUSIRU,true)
Chara.brow(NARUSIRU, 0)
Chara.mouth(NARUSIRU, 0)
Massage.setBoxL()
SimpleMassage(
name_("�܂ɂ�"),
"�E�E�E�E�E�B",
"",
""
)

Scene(10)
Chara.isBack(NARUSIRU,false)
Chara.eye(NARUSIRU, 1)
Chara.mouth(NARUSIRU, 1)
Massage.setBoxR()
SimpleMassage(
name_("�i���V��"),
"�ł����ӂ���B",
"",
""
)

Scene(11)
Chara.eye(NARUSIRU, 0)
Chara.brow(NARUSIRU, 2)
SimpleMassage(
name_("�i���V��"),
"�����ɂ��A���͔񋶋C���B",
"",
""
)

Scene(12)
SimpleMassage(
name_("�i���V��"),
"���ڂ�Ă����Ȃ����A",
"����ȗ́A�g���Ă�������B",
""
)

Scene(13)
Chara.isBack(IORIKO,false)
Chara.mouth(IORIKO, 1)
Chara.isBack(NARUSIRU,true)
Chara.mouth(NARUSIRU, 0)
Massage.setBoxL()
SimpleMassage(
name_("����"),
"����H",
"���႟�A�Ȃ��č�������",
"�����ǂ����Ă�́H"
)

Scene(14)
Chara.isBack(IORIKO,true)
Chara.mouth(IORIKO, 0)
Chara.isBack(NARUSIRU,false)
Chara.brow(NARUSIRU, 1)
Chara.eye(NARUSIRU, 1)
Chara.mouth(NARUSIRU, 1)
Massage.setBoxR()
SimpleMassage(
name_("�i���V��"),
"�d��������d���Ȃ���",
"",
""
)

Scene(15)
Chara.isBack(IORIKO,true)
Chara.isBack(NARUSIRU,false)
Massage.setBoxR()
Chara.eye(NARUSIRU, 0)
SimpleMassage(
name_("�i���V��"),
"�d��������d���Ȃ���",
"�t�b�g���[�N�����{�̋R�m�����́E�E�E�B",
""
)

Scene(16)
Chara.brow(NARUSIRU, 2)
SimpleMassage(
name_("�i���V��"),
"���āA�I�тȂ����I",
"",
""
)

Scene(17)
SimpleMassage(
name_("�i���V��"),
"���āA�I�тȂ����I",
"���̏�����邩�A",
""
)

Scene(18)
SimpleMassage(
name_("�i���V��"),
"���āA�I�тȂ����I",
"���̏�����邩�A�����ŋ����ޏꂷ�邩",
""
)

Scene(19)
Chara.isBack(IORIKO,false)
Chara.brow(IORIKO, 2)
Chara.mouth(IORIKO, 1)
Chara.isBack(NARUSIRU,true)
Chara.mouth(NARUSIRU, 0)
Massage.setBoxL()
SimpleMassage(
name_("����"),
"���߂��I���Ȃ����ޏꂷ��B",
"",
""
)

Scene(20)
Chara.isBack(IORIKO,true)
Chara.mouth(IORIKO, 0)
Chara.isBack(NARUSIRU,false)
Chara.brow(NARUSIRU, 0)
Chara.eye(NARUSIRU, 1)
Chara.mouth(NARUSIRU, 1)
Massage.setBoxR()
SimpleMassage(
name_("�i���V��"),
"�����E�E�E�B",
"",
""
)
Scene(21)
Massage.setBoxR()
Chara.brow(NARUSIRU, 2)
Chara.eye(NARUSIRU, 0)
SimpleMassage(
name_("�i���V��"),
"�����E�E�E�B",
"�����܂Ō����Ȃ�A�����Ŏa�����Ⴄ��!",
""
)
Scene(22)
PlayBGM(8)
WaitAndSkip(1)

end

--@EndScript