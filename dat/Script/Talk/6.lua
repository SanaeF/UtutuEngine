dofile( './dat/Script/Library/Talker/Library.lua' )
--3�ʒe���I����̉�b

function TalkScene()

AYANO = 0
HIME = 1
ALICE = 2
ID_MAX = ALICE

Scene(0)
Chara.create_ID(ID_MAX)
Chara.spawn(id_(AYANO), 0, 250, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.isBack(AYANO,true)
Chara.eye(AYANO, 1)
Chara.mouth(AYANO, 0)
Chara.spawn(ALICE, 7, 1100, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.eye(ALICE, 1)
Chara.mouth(ALICE, 1)
Chara.body(ALICE,1)
Massage.setBoxR()
SimpleMassage(
name_("�A���X�E�V���b�g(��)"),
"�Ȃ��Ȃ����˂�",
"",
""
)
Scene(1)
SimpleMassage(
name_("�A���X�E�V���b�g(��)"),
"�Ȃ��Ȃ����˂�",
"�ł��N����������ׂ��ꏊ��",
"�܂��R�R����Ȃ���B"
)
Scene(2)
SimpleMassage(
name_("�A���X�E�V���b�g(��)"),
"���႟��",
"",
""
)

end

--@EndScript