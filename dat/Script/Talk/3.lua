dofile( './dat/Script/Library/Talker/Library.lua' )
--2�ʒe���I����̉�b

function TalkScene()

AYANO = 0
HIME = 1
EREMIRA = 2
ID_MAX = EREMIRA

Scene(0)
Chara.create_ID(ID_MAX)
Chara.spawn(AYANO, 0, 250, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.eye(AYANO, 1)
Chara.mouth(AYANO, 0)
Chara.isBack(AYANO,true)
Chara.spawn(EREMIRA, 6, 1100, 800, 0.4)--�L�����̗����G��ǉ�
Chara.eye(EREMIRA, 1)
Chara.brow(EREMIRA, 1)
Chara.mouth(EREMIRA, 1)
Chara.body(EREMIRA,1)
Chara.spawnFacial(EREMIRA, BLACK, 250, 480)
Massage.setBoxR()
SimpleMassage(
name_("�G���~��"),
"�����`���E�E�E",
"�������������B",
""
)
Scene(1)
Chara.eye(EREMIRA, 3)
Chara.spawnFacial(EREMIRA, STOP, 0, 0)
SimpleMassage(
name_("�G���~��"),
"���`��˂��",
"",
""
)
Scene(2)
Chara.isBack(EREMIRA,true)
Chara.spawn(HIME, 3, 400, 1070, 0.47)
Chara.eye(HIME, 1)
Chara.brow(HIME, 1)
Chara.mouth(HIME, 1)
Chara.eye(EREMIRA, 1)
Chara.mouth(EREMIRA, 0)
Massage.setBoxL()
SimpleMassage(
name_("�Q"),
"���́E�E�E",
"",
""
)
Scene(3)
Chara.isBack(EREMIRA,false)
SimpleMassage(
name_("�Q"),
"���́E�E�E",
"�ǂ����ŉ�������A����܂����H",
""
)
Scene(4)
Chara.isBack(HIME,true)
Chara.brow(EREMIRA, 1)
Massage.setBoxR()
SimpleMassage(
name_("�G���~��"),
"�E�E�E�B",
"",
""
)
Scene(5)
Chara.mouth(EREMIRA, 1)
Massage.setBoxR()
SimpleMassage(
name_("�G���~��"),
"�E�E�E�B",
"�����s���Ȃ����B",
""
)
Scene(6)
SimpleMassage(
name_("�G���~��"),
"�E�E�E�B",
"�����s���Ȃ����B",
"����������I����Ă��܂�����"
)
Scene(7)
Chara.isBack(EREMIRA,true)
Chara.isBack(AYANO,false)
Chara.mouth(AYANO, 1)
Chara.mouth(EREMIRA, 0)
Massage.setBoxL()
SimpleMassage(
name_("���T"),
"���႟��������",
"",
""
)
Scene(8)
Chara.hide(HIME)
Chara.hide(AYANO)
Chara.isBack(EREMIRA,false)
WaitAndSkip(120)
Massage.setBoxR()
SimpleMassage(
name_("�G���~��"),
"�E�E�E�B",
"",
""
)
Scene(9)
Chara.brow(EREMIRA, 0)
Chara.mouth(EREMIRA, 1)
SimpleMassage(
name_("�G���~��"),
"���႟�ˁB�Q������",
"",
""
)

end

--@EndScript