--1�ʒe���O�̉�b

function Ayano()

	AYANO = 0
	MATUMI = 1
	ID_MAX = MATUMI

	Scene(0)
	SummonBoss(N01_MATUMI,index(0))--�{�X����
	WaitAndSkip(60)

	Scene(1)
	Chara.create_ID(ID_MAX)
	Massage.setBoxL()
	Chara.spawn(AYANO, 0, 250, 1000, 1)--�L�����̗����G��ǉ�
	Chara.eye(AYANO, 3)
	Chara.mouth(AYANO, 1)
	Chara.spawnFacial(AYANO, HAPPY, 0, 480)
	SimpleMassage(
		name_("���T"),
		"��̍��͋��E����",
		"���R�Ƀ��C�g�A�b�v�����񂾂�",
		""
	)

	Scene(2)
	JoinBullet(0,5)
end

--@EndScript