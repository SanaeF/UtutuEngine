dofile( './dat/Script/Library/Talker/Library.lua' )
--5�ʒe���O�̉�b

function TalkScene()

FEATORIA=0
MATUMI=1
ID_MAX = MATUMI

Scene(0)
Chara.create_ID(ID_MAX)
Chara.spawn(FEATORIA, 9, 350, 800, 0.4)--�L�����̗����G��ǉ�
Chara.body(FEATORIA, 1)
Chara.eye(FEATORIA, 4)
Chara.brow(FEATORIA, 1)
Chara.mouth(FEATORIA, 2)
Massage.setBoxL()
SimpleMassage(
name_("����"),
"�ɂ��������I�I",
"",
""
)

Scene(1)
Chara.hide(FEATORIA)
Chara.spawn(MATUMI, 5, 1100, 600, 0.27)--�L�����̗����G��ǉ�
Chara.spawnFacial(MATUMI, SWEAT, -80, -280)
Chara.brow(MATUMI, 1)
Chara.mouth(MATUMI, 2)
Massage.setBoxR()
SimpleMassage(
name_("�}�c�~"),
"�t�F�A�g���A�o���܁H",
"",
""
)

Scene(2)
Chara.spawnFacial(MATUMI, STOP, -80, -280)
SimpleMassage(
name_("�}�c�~"),
"�E�E�E",
"",
""
)

end

--@EndScript