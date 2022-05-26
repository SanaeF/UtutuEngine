dofile( './dat/Script/Library/Talker/Library.lua' )
--6�ʒe���O�̉�b

function StoryMode()

AYANO=0
SHIENA=1
ID_MAX = SHIENA

Scene(0)
Chara.create_ID(ID_MAX)
SummonBoss(N06_SHIENA, 10)--�{�X����
WaitAndSkip(60)

Scene(1)
Chara.spawn(AYANO, 0, 250, 1000, 0.4)--�L�����̗����G��ǉ�
Chara.img(tag(AYANO), brow(0), eye(1), mouth(0), back(true))
Chara.spawn(SHIENA, 10, 1200, 900, 0.4)--�L�����̗����G��ǉ�
Chara.img(tag(SHIENA), brow(0), eye(1), mouth(1), back(false))
Chara.body(SHIENA,1)
Massage.setBoxR()
SimpleMassage(
name_("�V�G�i"),
"�悤�₭�����܂ŗ��Ă��ꂽ�񂾂ˁB",
"",
""
)

Scene(2)
Chara.img(tag(AYANO), brow(0), eye(1), mouth(1), back(false))
Chara.img(tag(SHIENA), brow(0), eye(1), mouth(2), back(true))
Massage.setBoxL()
SimpleMassage(
name_("���T"),
"���̐l���A���̍����H",
"",
""
)

Scene(3)
Chara.img(tag(AYANO), brow(2), eye(1), mouth(1), back(false))
Chara.spawnFacial(AYANO, ANGRY, 80, 570)
SimpleMassage(
name_("���T"),
"���̐l���A���̍����H",
"�����A���C���~�߂Ă��炨�����I",
""
)

Scene(4)
Chara.img(tag(AYANO), brow(2), eye(1), mouth(0), back(true))
Chara.img(tag(SHIENA), brow(1), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("�V�G�i"),
"���`��A",
"���C�������Ă�͎̂�����Ȃ��񂾁B",
""
)

Scene(5)
Chara.img(tag(AYANO), brow(1), eye(1), mouth(1), back(false))
Chara.img(tag(SHIENA), brow(1), eye(1), mouth(0), back(true))
Chara.spawnFacial(AYANO, STOP, 80, 570)
Massage.setBoxL()
SimpleMassage(
name_("���T"),
"���Ă��O�ꂽ�̂��E�E�E�B�ǂ����悤�B",
"",
""
)

Scene(6)
Chara.body(SHIENA,0)
Chara.img(tag(AYANO), brow(1), eye(1), mouth(0), back(true))
Chara.img(tag(SHIENA), brow(0), eye(2), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("�V�G�i"),
"�ł͉��߂܂��āA",
"",
""
)

Scene(7)
Chara.img(tag(SHIENA), brow(0), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("�V�G�i"),
"�ł͉��߂܂��āA���v���Ԃ�",
"�܂���Ă��ꂵ����B",
""
)

Scene(8)
Chara.img(tag(AYANO), brow(1), eye(1), mouth(1), back(false))
Chara.img(tag(SHIENA), brow(0), eye(1), mouth(0), back(true))
Chara.spawnFacial(AYANO, ACCENT, 150, 680)
Massage.setBoxL()
SimpleMassage(
name_("���T"),
"���H",
"",
""
)

Scene(9)
Chara.img(tag(AYANO), brow(1), eye(1), mouth(0), back(true))
Chara.img(tag(SHIENA), brow(0), eye(3), mouth(1), back(false))
Chara.spawnFacial(AYANO, STOP, 150, 680)
Chara.spawnFacial(SHIENA, HAPPY, -50, 380)
Massage.setBoxR()
SimpleMassage(
name_("�V�G�i"),
"�����ƑO���玄�A",
"���Ȃ��ƒ��ڐ���Ă݂��������́B",
""
)

Scene(10)
Chara.img(tag(AYANO), brow(0), eye(3), mouth(1), back(false))
Chara.img(tag(SHIENA), brow(0), eye(3), mouth(0), back(true))
Chara.spawnFacial(AYANO, SWEAT, 80, 570)
Massage.setBoxL()
SimpleMassage(
name_("���T"),
"����͂ǂ����E�E�E�B",
"",
""
)

Scene(11)
Chara.img(tag(AYANO), brow(0), eye(1), mouth(0), back(true))
Chara.img(tag(SHIENA), brow(1), eye(1), mouth(1), back(false))
Chara.spawnFacial(AYANO, STOP, 150, 680)
Chara.spawnFacial(SHIENA, STOP, -150, 380)
Massage.setBoxR()
SimpleMassage(
name_("�V�G�i"),
"���߂�ˁA",
"",
""
)

Scene(12)
SimpleMassage(
name_("�V�G�i"),
"���߂�ˁA",
"���ׂ̈ɂ킴�킴���E�܂ŌĂ񂶂����",
""
)

Scene(13)
Chara.img(tag(AYANO), brow(0), eye(1), mouth(1), back(false))
Chara.img(tag(SHIENA), brow(1), eye(1), mouth(2), back(true))
Massage.setBoxL()
SimpleMassage(
name_("���T"),
"�������A�ǂ����ŉ�������Ƃ�������H",
"",
""
)

Scene(14)
Chara.img(tag(AYANO), brow(0), eye(1), mouth(0), back(true))
Chara.img(tag(SHIENA), brow(1), eye(1), mouth(1), back(false))
Massage.setBoxR()
SimpleMassage(
name_("�V�G�i"),
"�������A�o���Ă�킯�Ȃ���ˁE�E�E�B",
"",
""
)

Scene(14)
SimpleMassage(
name_("�V�G�i"),
"�������A�o���Ă�킯�Ȃ���ˁE�E�E�B",
"����A���v�B",
""
)

Scene(15)
Chara.img(tag(SHIENA), brow(0), eye(3), mouth(1), back(false))
SimpleMassage(
name_("�V�G�i"),
"�n�߂܂��傤�B",
"���̍l�����e���A�����Ă�����I",
""
)

Scene(16)
PlayBGM(11)
WaitAndSkip(1)

end

--@EndScript