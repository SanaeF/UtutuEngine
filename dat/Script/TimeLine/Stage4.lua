dofile( './dat/Script/Library/Timeline/TimelineSc.lua' )
dofile('./dat/Script/Timeline/ItemMinion/ItemMinion.lua')
dofile( './dat/Script/MinionProp/Bullet/Stage4/MinionBullet.lua' )
dofile( './dat/Script/MinionProp/Move/Stage4/MinionMover.lua' )

resetTime(5000)

function TimeLine()
	if (isTime(90))then TL.setSubTitle() end
	first_boss_time=500
	if (isTime(first_boss_time))then TL.setTalkScene(9) end
	if (isTime(first_boss_time+10))then TL.setTalkScene(10) end
	if (isTimeBetween(first_boss_time+50,2200))then
		X_max = FMAX_X - FMIN_X
		Y_max = FMAX_Y - FMIN_Y
		X_half=X_max/2

		t0=first_boss_time+50

		if(isTime(t0+60))then
			en_spawn(X_half-300, 500, DEV_BONE, 320, 0, 0)
			en_bullet(IMG.OVERLAP, CL.ORANGE)
			en_item(Apple, 3)
		end

		if(isTime(t0+120))then
			en_spawn(X_half+300, 500, DEV_BONE, 320, 1, 1)
			en_bullet(IMG.OVERLAP, CL.ORANGE)
			en_item(Apple, 3)
		end

		if(isTime(t0+240))then
			en_spawn(X_half, 300, DEV_BONE, 720, 2, 2)
			en_bullet(IMG.MEGA, CL.PINK)
			en_item(PowerGhost, 3)
		end

		if(isTime(t0+440))then
			en_spawn(X_half+400, 300, DEV_BONE, 420, 3, 2)
			en_bullet(IMG.BIG, CL.GREEN)
			en_item(PowerGhost, 3)
			en_spawn(X_half-400, 300, DEV_BONE, 420, 3, 2)
			en_bullet(IMG.BIG, CL.GREEN)
			en_item(PowerGhost, 3)
		end

		if(isTime(t0+1100))then
			en_spawn(X_half-450, 300, DEV_BONE, 720, 2, 2)
			en_bullet(IMG.MEGA, CL.YELLOW)
			en_item(PowerGhost, 3)
			en_spawn(X_half+450, 300, DEV_BONE, 720, 2, 2)
			en_bullet(IMG.MEGA, CL.YELLOW)
			en_item(PowerGhost, 3)
		end

		--道中の挙動と特殊演出
		is_spawned_matumi=false
		for i=0,MINION_MAX do
			if(Minion.isFlag(i))then
				MinionBulletUpdate(i)
				MinionMoveUpdate(i)
				is_spawned_matumi=Minion.getBoss(i)
				if(is_spawned_matumi)then matumiTrans(i) end
			end
		end
		if not(is_spawned_matumi)then spawnMatumi() end
		MinionBulletTrans()--弾幕の変化
		ItemMinion()--アイテムballoonの召喚
	end
	enter_boss_time=2200
	if (isTime(enter_boss_time))then TL.setTalkScene(11) end
	if (isTime(enter_boss_time+10))then TL.setTalkScene(12) end
	if (isTime(enter_boss_time+40))then TL.endStage() end
end

function spawnMatumi()
	boss_spawn(1,Player.getX(), 200,N01_MATUMI,9999999,LifeUP)
end

function matumiTrans(id)
	Minion.setNoUI(true)
	if(Minion.getCount(id) % diff(12,10,9,0) == 5)then se_play(BULLET01)
		dist = diff(50, 60, 70,0)
		speed = diff(6,6,7,0) + rand(2)
		angle = PI/2
		Shot.Create(Minion.getX(id) + rand(dist), Minion.getY(id) + rand(dist), IMG.AMMO, CL.RED, speed, angle, 99)
		Shot.setSize(2)
		angle = PI/2+PI/3
		Shot.Create(Minion.getX(id) + rand(dist), Minion.getY(id) + rand(dist), IMG.AMMO, CL.PINK, speed, angle, 99)
		Shot.setSize(2)
		angle = PI/2-PI/3
		Shot.Create(Minion.getX(id) + rand(dist), Minion.getY(id) + rand(dist), IMG.AMMO, CL.RED, speed, angle, 99)
		Shot.setSize(2)
		Minion.setMotion(1)
	end
	if(Minion.getCount(id) % 120 == 0)then Minion.setMove(Player.getX(),200,60)end
end

--@EndScript