dofile( './dat/Script/Library/Talker/Library.lua' )
--5�ʒe���O�̉�b

function Ioriko()

IORIKO = 0
AYANO = 1
FEATORIA=2
MATUMI=3
ID_MAX = MATUMI

Scene(0)
Chara.create_ID(ID_MAX)
Massage.setBoxR()
SimpleMassage(
name_("����"),
"��������!",
"",
""
)

Scene(1)
SummonInterBoss(N05_FEATORIA, 3)--�{�X����
WaitAndSkip(60)

Scene(2)
Chara.spawn(IORIKO, 4, 250, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.spawn(FEATORIA, 9, 1100, 600, 0.4)--�L�����̗����G��ǉ�
Chara.isBack(FEATORIA,true)
Chara.mouth(IORIKO, 1)
Massage.setBoxL()
SimpleMassage(
name_("����"),
"�������I���ɃL�m�R���Ԃ��h�����Ă�I",
"",
""
)

Scene(3)
Chara.isBack(IORIKO,true)
Chara.isBack(FEATORIA,false)
Chara.mouth(IORIKO, 0)
Chara.mouth(FEATORIA, 1)
Massage.setBoxR()
SimpleMassage(
name_("����"),
"���A�͂��B�L�m�R�ł��B",
"",
""
)

Scene(4)
Chara.isBack(IORIKO,false)
Chara.isBack(FEATORIA,true)
Chara.mouth(IORIKO, 1)
Chara.mouth(FEATORIA, 0)
Massage.setBoxL()
SimpleMassage(
name_("����"),
"�ǂ��Ȃ��Ă�̂���H",
"",
""
)

Scene(5)
Chara.isBack(IORIKO,true)
Chara.isBack(FEATORIA,false)
Chara.mouth(IORIKO, 0)
Chara.mouth(FEATORIA, 1)
Massage.setBoxR()
SimpleMassage(
name_("����"),
"�����ƁE�E�E�B",
"",
""
)

Scene(6)
Chara.eye(FEATORIA, 4)
Chara.brow(FEATORIA, 1)
Chara.mouth(FEATORIA, 2)
SimpleMassage(
name_("���̃L�m�R"),
"���܂肵��ׂ��Ă���]�T�͖�����",
"",
""
)

Scene(7)
Chara.eye(FEATORIA, 0)
SimpleMassage(
name_("���̃L�m�R"),
"���̎q�Ƃ̌v������邪�A��X�͕ʂ�",
"���C�E�B���X���W�߂Ȃ��Ă͂Ȃ�Ȃ��B",
""
)

Scene(8)
Chara.brow(FEATORIA, 2)
SimpleMassage(
name_("���̃L�m�R"),
"���������̂��O�I",
"",
""
)

Scene(9)
Chara.isBack(IORIKO,false)
Chara.isBack(FEATORIA,true)
Chara.mouth(IORIKO, 1)
Massage.setBoxL()
SimpleMassage(
name_("����"),
"���H���H",
"",
""
)

Scene(10)
Chara.isBack(IORIKO,true)
Chara.isBack(FEATORIA,false)
Chara.mouth(IORIKO, 0)
Massage.setBoxR()
SimpleMassage(
name_("���̃L�m�R"),
"���A���̋������E�B���X���T���ꂽ��",
"�Ȃ���΁A���B��|���ĒD���Ă݂�I",
""
)

Scene(11)
Chara.isBack(IORIKO,true)
Chara.isBack(FEATORIA,true)
Chara.spawn(AYANO, 0, 470, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.mouth(AYANO, 1)
Massage.setBoxL()
SimpleMassage(
name_("���T"),
"��΂��A�������ɃA������������A",
"�ς����邩������Ȃ�",
""
)

Scene(12)
Chara.isBack(IORIKO,false)
Chara.isBack(AYANO,true)
Chara.brow(IORIKO, 2)
Chara.mouth(IORIKO, 1)
Chara.mouth(AYANO, 0)
SimpleMassage(
name_("����"),
"����͂܂����ˁE�E�E�B",
"���႟��邵������������",
""
)

Scene(13)
Chara.isBack(IORIKO,true)
Chara.isBack(FEATORIA,false)
Chara.mouth(IORIKO, 0)
Massage.setBoxR()
SimpleMassage(
name_("���̃L�m�R"),
"�Ԉ���Ă�",
"���������̂���񂶂�Ȃ����H",
""
)

Scene(14)
Chara.mouth(FEATORIA, 1)
Massage.setBoxR()
SimpleMassage(
name_("����"),
"����E�E�E�B����΂�I",
"",
""
)

Scene(15)
SimpleMassage(
name_("����"),
"�s����I�}�c�~",
"",
""
)

Scene(16)
Chara.isBack(FEATORIA,true)
Chara.mouth(FEATORIA, 0)
Chara.spawn(MATUMI, 5, 1200, 600, 0.31)--�L�����̗����G��ǉ�
Chara.mouth(MATUMI, 1)
SimpleMassage(
name_("�}�c�~"),
"�͂��́`����",
"",
""
)

Scene(17)
PlayBGM(9)
WaitAndSkip(1)

end

--@EndScript