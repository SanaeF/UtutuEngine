dofile( './dat/Script/Library/Talker/Library.lua' )
--5�ʒe����̉�b

function TalkScene()

FEATORIA=0
MATUMI=1
ID_MAX = MATUMI

Scene(0)
Chara.create_ID(ID_MAX)
Chara.spawn(FEATORIA, 9, 1100, 600, 0.4)--�L�����̗����G��ǉ�
Chara.img(tag(FEATORIA), brow(1), eye(2), mouth(2), back(false))
Massage.setBoxR()
SimpleMassage(
name_("�t�F�A�g���A"),
"�E�E�E�B",
"",
""
)

Scene(1)
Chara.spawn(MATUMI, 5, 200, 600, 0.27)--�L�����̗����G��ǉ�
Chara.img(tag(MATUMI), brow(1), eye(2), mouth(2), back(false))
Chara.img(tag(FEATORIA), brow(1), eye(2), mouth(2), back(true))
Massage.setBoxL()
SimpleMassage(
name_("�}�c�~"),
"�E�E�E�B",
"",
""
)

Scene(2)
Chara.img(tag(MATUMI), brow(1), eye(2), mouth(2), back(true))
Chara.img(tag(FEATORIA), brow(1), eye(2), mouth(2), back(false))
Massage.setBoxR()
SimpleMassage(
name_("���̃L�m�R"),
"�Q�Ă邾������B",
"",
""
)

Scene(3)
SimpleMassage(
name_("���̃L�m�R"),
"�_���[�W���Q���^���Ă��Ȃ�����",
"���S���āB",
""
)

Scene(4)
Chara.img(tag(FEATORIA), brow(1), eye(1), mouth(2), back(false))
SimpleMassage(
name_("�t�F�A�g���A"),
"�E�E�E�B",
"",
""
)

Scene(5)
SimpleMassage(
name_("���̃L�m�R"),
"�l�����͋����֌W���B",
"",
""
)

Scene(6)
SimpleMassage(
name_("���̃L�m�R"),
"���݂�����t����������͂Ȃ���B",
"",
""
)

Scene(7)
Chara.img(tag(FEATORIA), brow(1), eye(1), mouth(1), back(false))
SimpleMassage(
name_("�t�F�A�g���A"),
"�����E�E�E���ˁE�E�E�B",
"",
""
)

Scene(8)
Chara.img(tag(FEATORIA), brow(1), eye(1), mouth(0), back(false))
SimpleMassage(
name_("���̃L�m�R"),
"�ق�A��ڂ��I������",
"",
""
)

Scene(9)
SimpleMassage(
name_("���̃L�m�R"),
"�ق�A��ڂ��I������",
"���C�W�߂悤��B",
""
)

Scene(10)
SimpleMassage(
name_("���̃L�m�R"),
"�ˁH",
"",
""
)

end

--@EndScript