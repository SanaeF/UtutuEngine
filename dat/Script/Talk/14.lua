dofile( './dat/Script/Library/Talker/Library.lua' )
--6�ʒe����(�A���X���[�h)�̉�b

function TalkScene()
Massage.reset()
SHIENA=0
ID_MAX = SHIENA

Scene(0)
Chara.create_ID(ID_MAX)
Chara.spawn(SHIENA, 10, 1200, 900, 0.4)--�L�����̗����G��ǉ�
Chara.img(tag(SHIENA), brow(0), eye(1), mouth(1), back(false))
Chara.body(SHIENA,1)
Massage.setBoxR()
SimpleMassage(
name_("�V�G�i"),
"�y���������B",
"",
""
)

Scene(1)
Chara.img(tag(SHIENA), brow(0), eye(1), mouth(1), back(false))
SimpleMassage(
name_("�V�G�i"),
"�܂����ł����ėǂ�����ˁH",
"",
""
)

end

--@EndScript