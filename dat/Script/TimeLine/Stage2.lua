dofile('./dat/Script/Library/Timeline/TimelineSc.lua' )
dofile('./dat/Script/Timeline/ItemMinion/ItemMinion.lua')
dofile('./dat/Script/MinionProp/Bullet/Stage2/MinionBullet.lua')
dofile('./dat/Script/MinionProp/Move/Stage2/MinionMover.lua')

resetTime(6000)

function TimeLine()
	X_max = FMAX_X - FMIN_X
	Y_max = FMAX_Y - FMIN_Y
	--一列からのホーミング
	if (isTime(50)) then
		x=80
		for i=0,7 do
			en_spawn(x+i*80, 100, OBJ_ONMYOU, 70, 0, 0)
			en_bullet(IMG.OVERLAP, CL.BLUE)
			en_item(PointGhost, 2)
		end
	end
	if (isTime(150)) then
		x=X_max
		for i=0,7 do
			en_spawn(x-i*80, 400, OBJ_ONMYOU, 70, 0, 0)
			en_bullet(IMG.OVERLAP, CL.BLUE)
			en_item(PointGhost, 2)
		end
	end
	if (isTime(250)) then
		for i=0,5 do
			en_spawn(80+i*80, 600, OBJ_ONMYOU, 20, 0, 0)
			en_bullet(IMG.OVERLAP, CL.BLUE)
			en_item(PowerGhost, 3)
			en_spawn(X_max-i*80, 600, OBJ_ONMYOU, 20, 0, 0)
			en_bullet(IMG.OVERLAP, CL.BLUE)
			en_item(PowerGhost, 2)
		end
	end

	if (isTime(450))then TL.setSubTitle() end

	if (isTime(650)) then
		en_spawn(0, 100, DEV_NORMAL, 160, 1, 1)
		en_bullet(IMG.RICE, CL.BLUE)
		en_item(PowerGhost, 1)
	end
	if (isTime(700)) then
		en_spawn(0, 500, DEV_NORMAL, 160, 1, 1)
		en_bullet(IMG.RICE, CL.BLUE)
		en_item(PowerGhost, 1)
	end
	if (isTime(750)) then
		en_spawn(0, 250, DEV_NORMAL, 40, 1, 1)
		en_bullet(IMG.RICE, CL.BLUE)
		en_item(GoldenApple, 1)
	end

	if (isTime(750)) then
		en_spawn(X_max, 100, DEV_NORMAL, 160, 1, 2)
		en_bullet(IMG.RICE, CL.GREEN)
		en_item(PowerGhost, 1)
	end
	if (isTime(800)) then
		en_spawn(X_max, 500, DEV_NORMAL, 160, 1, 2)
		en_bullet(IMG.RICE, CL.GREEN)
		en_item(PowerGhost, 1)
	end
	if (isTime(850)) then
		en_spawn(X_max, 250, DEV_NORMAL, 40, 1, 2)
		en_bullet(IMG.RICE, CL.GREEN)
		en_item(GoldenApple, 1)
	end

	if (isTime(1000)) then
		en_spawn(X_max/2, 500, DEV_GREEN, 960, 2, 3)
		en_bullet(IMG.RICE, CL.PINK)
		en_item(Apple, 1)
	end
	if (isTime(1200)) then
		en_spawn(X_max/2+200, 500, DEV_ORANGE, 420, 3, 3)
		en_bullet(IMG.RICE, CL.CYAN)
		en_item(PowerGhost, 2)
		en_spawn(X_max/2-200, 500, DEV_ORANGE, 420, 2, 3)
		en_bullet(IMG.RICE, CL.CYAN)
		en_item(PowerGhost, 2)
	end
	first_time = 1400
	if (isTime(first_time)or
		isTime(first_time+20)or
		isTime(first_time+40)or
		isTime(first_time+60)or
		isTime(first_time+80)or
		isTime(first_time+100)or
		isTime(first_time+120)or
		isTime(first_time+140)) then
		en_spawn(0, 100, DEV_NORMAL, 20, 4, 1)
		en_bullet(IMG.POIFUL, CL.SKY)
		en_item(PowerGhost, 1)
	end
	first_time = 1540
	if (isTime(first_time)or
		isTime(first_time+20)or
		isTime(first_time+40)or
		isTime(first_time+60)or
		isTime(first_time+80)or
		isTime(first_time+100)or
		isTime(first_time+120)or
		isTime(first_time+140)) then
		en_spawn(X_max, 100, DEV_NORMAL, 60, 4, 2)
		en_bullet(IMG.POIFUL, CL.SKY)
		en_item(PowerGhost, 1)
	end
	first_time = 1740
	if (isTime(first_time)or
		isTime(first_time+20)or
		isTime(first_time+40)or
		isTime(first_time+60)or
		isTime(first_time+80)or
		isTime(first_time+100)or
		isTime(first_time+120)or
		isTime(first_time+140)) then
		en_spawn(40, Y_max, OBJ_ONMYOU, 60, 4, 4)
		en_bullet(IMG.POIFUL, CL.GREEN)
		en_item(PowerGhost, 2)
		Minion.setSpeed(8)
		en_spawn(X_max-40, Y_max, OBJ_ONMYOU, 60, 4, 4)
		en_bullet(IMG.POIFUL, CL.GREEN)
		en_item(PowerGhost, 2)
		Minion.setSpeed(8)
	end

	first_time = 2200
	if (isTime(first_time)or
		isTime(first_time+20)or
		isTime(first_time+40)or
		isTime(first_time+60)or
		isTime(first_time+80)or
		isTime(first_time+100)or
		isTime(first_time+120)or
		isTime(first_time+140)) then
		en_spawn(0, 100, DEV_NORMAL, 80, 4, 1)
		en_bullet(IMG.POIFUL, CL.PINK)
		en_item(PowerGhost, 1)
	end
	first_time = 2400
	if (isTime(first_time)or
		isTime(first_time+20)or
		isTime(first_time+40)or
		isTime(first_time+60)or
		isTime(first_time+80)or
		isTime(first_time+100)or
		isTime(first_time+120)or
		isTime(first_time+140)) then
		en_spawn(X_max, 100, DEV_NORMAL, 80, 4, 2)
		en_bullet(IMG.POIFUL, CL.PINK)
		en_item(PowerGhost, 1)
	end

	--中ボス
	if (isTime(2900))then TL.setTalkScene(4) end
	--下から湧き出るレーザー集団
	first_time = 3000
	if (isTime(first_time)or
		isTime(first_time+40)or
		isTime(first_time+80)or
		isTime(first_time+120)or
		isTime(first_time+160)) then
		en_spawn(40, Y_max*2/3, OBJ_ONMYOU, 50, 3, 4)
		en_bullet(IMG.RICE, CL.RED)
		en_item(PowerGhost, 1)
		Minion.setSpeed(8)
		en_spawn(X_max-40, Y_max*2/3, OBJ_ONMYOU, 50, 2, 4)
		en_bullet(IMG.RICE, CL.RED)
		en_item(PowerGhost, 1)
		Minion.setSpeed(8)
	end
	--タッグで仕掛けてくる
	if (isTime(3400)) then
		en_spawn(X_max/2+200, 200, DEV_ORANGE, 520, 5, 3)
		en_bullet(IMG.POIFUL, CL.RED)
		en_item(Apple, 1)
		en_spawn(X_max/2-200, 200, DEV_ORANGE, 520, 5, 3)
		en_bullet(IMG.POIFUL, CL.RED)
		en_item(Apple, 1)
	end
	if (isTime(3700)) then
		en_spawn(X_max/2+200, Y_max/2, DEV_ORANGE, 720, 5, 5)
		en_bullet(IMG.POIFUL, CL.RED)
		en_item(PowerGhost, 5)
		en_spawn(X_max/2-200, Y_max/2, DEV_ORANGE, 720, 5, 5)
		en_bullet(IMG.POIFUL, CL.RED)
		en_item(PowerGhost, 5)
	end
	--レーザー撃ちながら上昇
	first_time = 4200
	if (isTime(first_time)) then
		en_spawn(200, 300, DEV_GREEN, 520, 2, 5)
		en_bullet(IMG.RICE, CL.ORANGE)
		en_item(Apple, 1)
		en_spawn(X_max-200, 300, DEV_GREEN, 520, 3, 5)
		en_bullet(IMG.RICE, CL.ORANGE)
		en_item(Apple, 1)
	end
	--同時にサイドから
	if (isTime(first_time)or
		isTime(first_time+20)or
		isTime(first_time+40)or
		isTime(first_time+60)or
		isTime(first_time+80)or
		isTime(first_time+100)or
		isTime(first_time+120)or
		isTime(first_time+140)) then
		en_spawn(0, 100, DEV_NORMAL, 20, 4, 1)
		en_bullet(IMG.POIFUL, CL.ORANGE)
		en_item(PowerGhost, 1)
		en_spawn(X_max, 100, DEV_NORMAL, 60, 4, 2)
		en_bullet(IMG.POIFUL, CL.ORANGE)
		en_item(PowerGhost, 1)
	end
	--ボス戦会話スタート
	enter_boss_time = 5000
	if (isTime(enter_boss_time))then TL.setTalkScene(5) end--会話シーンへ移行
	if (isTime(enter_boss_time+10))then TL.setTalkScene(6) end--会話シーンへ移行
	if (isTime(enter_boss_time+40))then TL.endStage() end

	--道中の挙動と特殊演出
	for i=0,MINION_MAX do
		if(Minion.isFlag(i))then
			MinionBulletUpdate(i)
			MinionMoveUpdate(i)
		end
	end
	MinionBulletTrans()--弾幕の変化
	ItemMinion()--アイテムballoonの召喚
end

--@EndScript