dofile( './dat/Script/Library/Talker/Library.lua' )
--5�ʒe���O�̉�b

function Hime()

HIME = 0
AKAGI = 1
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
Chara.spawn(HIME, 3, 250, 1070, 0.47)--�L�����̗����G��ǉ�
Chara.spawn(FEATORIA, 9, 1100, 600, 0.4)--�L�����̗����G��ǉ�
Chara.isBack(FEATORIA,true)
Chara.mouth(HIME, 1)
Massage.setBoxL()
SimpleMassage(
name_("�Q"),
"����!?�A���ɃL�m�R���E�E�E�B",
"",
""
)

Scene(3)
Chara.isBack(HIME,true)
Chara.isBack(FEATORIA,false)
Chara.mouth(HIME, 0)
Chara.mouth(FEATORIA, 1)
Massage.setBoxR()
SimpleMassage(
name_("����"),
"�͂��B�L�m�R�ł��B",
"",
""
)

Scene(4)
Chara.isBack(HIME,false)
Chara.isBack(FEATORIA,true)
Chara.mouth(HIME, 1)
Chara.mouth(FEATORIA, 0)
Massage.setBoxL()
SimpleMassage(
name_("�Q"),
"���A���v�Ȃ�ł����H",
"",
""
)

Scene(5)
Chara.isBack(HIME,true)
Chara.isBack(FEATORIA,false)
Chara.mouth(HIME, 0)
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
Chara.isBack(HIME,false)
Chara.isBack(FEATORIA,true)
Chara.mouth(HIME, 1)
Massage.setBoxL()
SimpleMassage(
name_("�Q"),
"�ӂ����H",
"",
""
)

Scene(10)
Chara.isBack(HIME,true)
Chara.isBack(FEATORIA,false)
Chara.mouth(HIME, 0)
Massage.setBoxR()
SimpleMassage(
name_("���̃L�m�R"),
"���̋������E�B���X���΂�T���ꂽ��",
"�Ȃ���΁A���B��|���ĒD���Ă݂�I",
""
)

Scene(11)
Chara.isBack(HIME,true)
Chara.isBack(FEATORIA,true)
Chara.spawn(AKAGI, 2, 470, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.mouth(AKAGI, 1)
Massage.setBoxL()
SimpleMassage(
name_("�ԏ�"),
"�������ɃA������������A",
"�ς����邩������Ȃ���",
""
)

Scene(12)
Chara.isBack(HIME,false)
Chara.isBack(AKAGI,true)
Chara.brow(HIME, 2)
Chara.mouth(HIME, 1)
Chara.mouth(AKAGI, 0)
SimpleMassage(
name_("�Q"),
"�Ђ����A����͂܂����悧�`�B",
"��邵���Ȃ��񂾂�ˁE�E�E�B",
""
)

Scene(13)
Chara.isBack(HIME,true)
Chara.isBack(FEATORIA,false)
Chara.mouth(HIME, 0)
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