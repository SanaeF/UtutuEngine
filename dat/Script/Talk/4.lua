dofile( './dat/Script/Library/Talker/Library.lua' )
--3�ʒ��{�X�̉�b

function TalkScene()

AYANO = 0
HIME = 1
ID_MAX = HIME

Scene(0)
SummonInterBoss(N03_EREMIRA, 1)
Chara.create_ID(ID_MAX)
Massage.setBoxL()
Chara.spawn(HIME, 3, 200, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.eye(HIME, 1)
Chara.mouth(HIME, 1)
Chara.spawnFacial(HIME, ACCENT, 80, 670)
SimpleMassage(
name_("�Q"),
"�܂������p�ł����H",
"",
""
)
Scene(1)
Chara.spawnFacial(HIME, STOP, 0, 0)
Chara.brow(HIME, 1)
Chara.eye(HIME, 1)
Chara.mouth(HIME, 0)
SimpleMassage(
name_("�Q"),
"�E�E�E�H",
"",
""
)
Scene(2)
Chara.isBack(HIME, true)
Chara.spawn(AYANO, 0, 400, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.brow(AYANO, 1)
Chara.eye(AYANO, 3)
Chara.mouth(AYANO, 1)
Chara.spawnFacial(AYANO, SWEAT, -100, 600)
SimpleMassage(
name_("���T"),
"�A���H�������ĂȂ��̂��ȁH",
"",
""
)

end

--@EndScript