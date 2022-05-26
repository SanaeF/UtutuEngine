--1面弾幕前の会話

function Ayano()

	AYANO = 0
	MATUMI = 1
	ID_MAX = MATUMI

	Scene(0)
	SummonBoss(N01_MATUMI,index(0))--ボス召喚
	WaitAndSkip(60)

	Scene(1)
	Chara.create_ID(ID_MAX)
	Massage.setBoxL()
	Chara.spawn(AYANO, 0, 250, 1000, 1)--キャラの立ち絵を追加
	Chara.eye(AYANO, 3)
	Chara.mouth(AYANO, 1)
	Chara.spawnFacial(AYANO, HAPPY, 0, 480)
	SimpleMassage(
		name_("綾乃"),
		"夜の桜は虚界だと",
		"自然にライトアップされるんだね",
		""
	)

	Scene(2)
	JoinBullet(0,5)
end

--@EndScript