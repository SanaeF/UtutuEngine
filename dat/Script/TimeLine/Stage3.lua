dofile( './dat/Script/Library/Timeline/TimelineSc.lua' )
dofile('./dat/Script/Timeline/ItemMinion/ItemMinion.lua')
dofile( './dat/Script/MinionProp/Bullet/Stage3/MinionBullet.lua' )
dofile( './dat/Script/MinionProp/Move/Stage3/MinionMover.lua' )

resetTime(10000)

function TimeLine()
	X_max = FMAX_X - FMIN_X
	Y_max = FMAX_Y - FMIN_Y
	X_half = X_max/2

	if (isTime(40)) then
		en_spawn(X_half-300, 100, OBJ_ONMYOU, 70, 0, 0)
		en_bullet(IMG.BIG, CL.RED)
		en_item(PowerGhost, 3)
		en_spawn(X_half+300, 100, OBJ_ONMYOU, 70, 0, 0)
		en_bullet(IMG.BIG, CL.RED)
		en_item(PowerGhost, 3)
	end

	if (isTime(180))then TL.setSubTitle() end

	rush_time=460
	if (isTime(rush_time+30*0))then firstRush(500) end
	if (isTime(rush_time+30*1))then firstRush(100) end
	if (isTime(rush_time+30*2))then firstRush(300) end
	if (isTime(rush_time+30*3))then firstRush(250) end
	if (isTime(rush_time+30*4))then firstRush(400) end
	if (isTime(rush_time+30*5))then firstRush(150) end
	if (isTime(rush_time+30*6))then firstRush(350) end
	if (isTime(rush_time+30*7))then firstRush(200) end
	if (isTime(rush_time+30*8))then firstRush(450) end
	if (isTime(rush_time+30*9))then firstRush(100) end
	if (isTime(rush_time+30*10))then firstRush(500) end

	if (isTime(1160))then
		en_spawn(0, 200, DEV_ORANGE, 540, 2, 2)
		en_bullet(IMG.BIG, CL.ORANGE)
		en_item(Apple, 1)
		en_spawn(X_max, 200, DEV_ORANGE, 540, 2, 2)
		en_bullet(IMG.BIG, CL.RED)
		en_item(Apple, 1)
	end

	--曲に合わせて出てくる
	rhythmSpawner(1850,12)

	if (isTime(3240))then
		en_spawn(0, 500, DEV_ORANGE, 540, 4, 2)
		en_bullet(IMG.BIG, CL.CYAN)
		en_item(Apple, 1)
		en_spawn(X_max, 500, DEV_ORANGE, 540, 4, 2)
		en_bullet(IMG.BIG, CL.CYAN)
		en_item(Apple, 1)
	end
	if (isTime(3415))then
		en_spawn(0, 300, DEV_ORANGE, 440, 4, 2)
		en_bullet(IMG.BIG, CL.PINK)
		en_item(Apple, 1)
		en_spawn(X_max, 300, DEV_ORANGE, 440, 4, 2)
		en_bullet(IMG.BIG, CL.PINK)
		en_item(Apple, 1)
	end
	if (isTime(3584))then
		en_spawn(0, 100, DEV_ORANGE, 440, 4, 2)
		en_bullet(IMG.BIG, CL.GREEN)
		en_item(Apple, 1)
		en_spawn(X_max, 100, DEV_ORANGE, 440, 4, 2)
		en_bullet(IMG.BIG, CL.GREEN)
		en_item(Apple, 1)
	end
	rush_time=3919
	if (isTime(rush_time+30*0))then firstRush(500) end
	if (isTime(rush_time+30*1))then firstRush(100) end
	if (isTime(rush_time+30*2))then firstRush(300) end
	if (isTime(rush_time+30*3))then firstRush(250) end
	if (isTime(rush_time+30*4))then firstRush(400) end
	if (isTime(rush_time+30*5))then firstRush(150) end
	if (isTime(rush_time+30*6))then firstRush(350) end
	if (isTime(rush_time+30*7))then firstRush(200) end
	if (isTime(rush_time+30*8))then firstRush(450) end
	if (isTime(rush_time+30*9))then firstRush(100) end
	if (isTime(rush_time+30*10))then firstRush(500) end

	if (isTime(4610))then
		en_spawn(X_half-400, 300, OBJ_ONMYOU, 70, 0, 0)
		en_bullet(IMG.BIG, CL.BLUE)
		en_item(Apple, 1)
		en_spawn(X_half+400, 300, OBJ_ONMYOU, 70, 0, 0)
		en_bullet(IMG.BIG, CL.BLUE)
		en_item(Apple, 1)
	end
	if (isTime(4780))then
		en_spawn(X_half-200, 100, OBJ_ONMYOU, 70, 0, 0)
		en_bullet(IMG.BIG, CL.BLUE)
		en_item(Apple, 1)
		en_spawn(X_half+200, 100, OBJ_ONMYOU, 70, 0, 0)
		en_bullet(IMG.BIG, CL.BLUE)
		en_item(Apple, 1)
	end
	if (isTime(4947))then
		en_spawn(X_half, 200, OBJ_ONMYOU, 70, 0, 0)
		en_bullet(IMG.BIG, CL.PURPLE)
		en_item(Apple, 1)
		en_spawn(X_half-300, 100, OBJ_ONMYOU, 70, 0, 0)
		en_bullet(IMG.BIG, CL.BLUE)
		en_item(Apple, 1)
		en_spawn(X_half+300, 100, OBJ_ONMYOU, 70, 0, 0)
		en_bullet(IMG.BIG, CL.BLUE)
		en_item(Apple, 1)
	end

	--曲に合わせて出てくる
	rhythmSpawner(5300,8)

	if (isTime(6220))then TL.setInterBoss(N04_NARSIRU, 1) end--6220

	if (isTime(6400))then
		en_spawn(X_half-400, 300, OBJ_ONMYOU, 70, 0, 0)
		en_bullet(IMG.BIG, CL.BLUE)
		en_item(Apple, 1)
		en_spawn(X_half+400, 300, OBJ_ONMYOU, 70, 0, 0)
		en_bullet(IMG.BIG, CL.BLUE)
		en_item(Apple, 1)
	end
	if (isTime(6580))then
		en_spawn(X_half-200, 100, OBJ_ONMYOU, 70, 0, 0)
		en_bullet(IMG.BIG, CL.BLUE)
		en_item(Apple, 1)
		en_spawn(X_half+200, 100, OBJ_ONMYOU, 70, 0, 0)
		en_bullet(IMG.BIG, CL.BLUE)
		en_item(Apple, 1)
	end
	if (isTime(6760))then
		en_spawn(X_half, 200, OBJ_ONMYOU, 70, 0, 0)
		en_bullet(IMG.BIG, CL.PURPLE)
		en_item(Apple, 1)
		en_spawn(X_half-300, 100, OBJ_ONMYOU, 70, 0, 0)
		en_bullet(IMG.BIG, CL.BLUE)
		en_item(Apple, 1)
		en_spawn(X_half+300, 100, OBJ_ONMYOU, 70, 0, 0)
		en_bullet(IMG.BIG, CL.BLUE)
		en_item(Apple, 1)
	end

	if (isTime(7000))then
		en_spawn(0, 500, DEV_ORANGE, 540, 4, 2)
		en_bullet(IMG.BIG, CL.CYAN)
		en_item(Apple, 1)
		en_spawn(X_max, 500, DEV_ORANGE, 540, 4, 2)
		en_bullet(IMG.BIG, CL.CYAN)
		en_item(Apple, 1)
	end
	if (isTime(7100))then
		en_spawn(0, 300, DEV_ORANGE, 440, 4, 2)
		en_bullet(IMG.BIG, CL.PINK)
		en_item(Apple, 1)
		en_spawn(X_max, 300, DEV_ORANGE, 440, 4, 2)
		en_bullet(IMG.BIG, CL.PINK)
		en_item(Apple, 1)
	end
	if (isTime(7200))then
		en_spawn(0, 100, DEV_ORANGE, 440, 4, 2)
		en_bullet(IMG.BIG, CL.GREEN)
		en_item(Apple, 1)
		en_spawn(X_max, 100, DEV_ORANGE, 440, 4, 2)
		en_bullet(IMG.BIG, CL.GREEN)
		en_item(Apple, 1)
	end

	if (isTime(7500))then
		en_spawn(0, 100, DEV_ORANGE, 440, 4, 2)
		en_bullet(IMG.BIG, CL.ORANGE)
		en_item(Apple, 1)
		en_spawn(X_max, 100, DEV_ORANGE, 440, 4, 2)
		en_bullet(IMG.BIG, CL.ORANGE)
		en_item(Apple, 1)
	end
	if (isTime(7600))then
		en_spawn(0, 100, DEV_ORANGE, 440, 4, 2)
		en_bullet(IMG.BIG, CL.RED)
		en_item(Apple, 1)
		en_spawn(X_max, 100, DEV_ORANGE, 440, 4, 2)
		en_bullet(IMG.BIG, CL.RED)
		en_item(Apple, 1)
	end

	if (isTime(8000)) then
		en_spawn(X_half-300, 100, OBJ_ONMYOU, 70, 0, 0)
		en_bullet(IMG.BIG, CL.PURPLE)
		en_item(Apple, 1)
		en_spawn(X_half+300, 100, OBJ_ONMYOU, 70, 0, 0)
		en_bullet(IMG.BIG, CL.PURPLE)
		en_item(Apple, 1)
	end
	if (isTime(8500)) then
		en_spawn(X_half-100, 200, OBJ_ONMYOU, 70, 0, 0)
		en_bullet(IMG.BIG, CL.PINK)
		en_item(Apple, 1)
		en_spawn(X_half+100, 200, OBJ_ONMYOU, 70, 0, 0)
		en_bullet(IMG.BIG, CL.PINK)
		en_item(Apple, 1)
	end

	--ボス戦会話スタート
	enter_boss_time = 9033
	if (isTime(enter_boss_time))then TL.setTalkScene(7) end--会話シーンへ移行
	if (isTime(enter_boss_time+10))then TL.setTalkScene(8) end--会話シーンへ移行
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

function firstRush(y)
	en_spawn(0, y, DEV_NORMAL, 40, 1, 1)
	en_bullet(IMG.NORMAL, CL.ORANGE)
	en_item(PointGhost, 4)
	en_spawn(X_max, y, DEV_NORMAL, 40, 1, 1)
	en_bullet(IMG.NORMAL, CL.ORANGE)
	en_item(PointGhost, 4)
end

function rhythmSpawner(time,num)--max:12
	hp=100
	if (isTime(time))then
		en_spawn(X_half-300, 400, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half+300, 400, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.SCALY, CL.CYAN)
		en_item(PowerGhost, 5)
	end
	if(num==1)then return end
	if (isTime(time+100))then
		en_spawn(X_half, 300, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half-150, 500, OBJ_ONMYOU, hp, 3, 3)--2
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half+150, 500, OBJ_ONMYOU, hp, 3, 3)--2
		en_bullet(IMG.SCALY, CL.CYAN)
		en_item(PowerGhost, 5)
	end
	if(num==2)then return end
	if (isTime(time+220))then
		en_spawn(X_half-200, 300, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half+200, 300, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.SCALY, CL.CYAN)
		en_item(PowerGhost, 5)
		en_spawn(X_half-200, 600, OBJ_ONMYOU, hp, 3, 3)--2
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half+200, 600, OBJ_ONMYOU, hp, 3, 3)--2
		en_bullet(IMG.SCALY, CL.CYAN)
		en_item(PowerGhost, 5)
	end
	if(num==3)then return end
	if (isTime(time+328))then
		en_spawn(X_half-300, 200, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half+300, 200, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.SCALY, CL.CYAN)
		en_item(PowerGhost, 5)
		en_spawn(X_half, 450, OBJ_ONMYOU, hp, 3, 3)--2
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half-300, 700, OBJ_ONMYOU, hp, 3, 3)--3
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half+300, 700, OBJ_ONMYOU, hp, 3, 3)--3
		en_bullet(IMG.SCALY, CL.CYAN)
		en_item(PowerGhost, 5)
	end
	if(num==4)then return end
	if (isTime(time+464))then
		en_spawn(X_half-300, 200, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half+300, 200, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.SCALY, CL.CYAN)
		en_item(PowerGhost, 5)
		en_spawn(X_half-300, 450, OBJ_ONMYOU, hp, 3, 3)--2
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half+300, 450, OBJ_ONMYOU, hp, 3, 3)--2
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half-300, 700, OBJ_ONMYOU, hp, 3, 3)--3
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half+300, 700, OBJ_ONMYOU, hp, 3, 3)--3
		en_bullet(IMG.SCALY, CL.CYAN)
		en_item(PowerGhost, 5)
	end
	if(num==5)then return end
	if (isTime(time+560))then
		en_spawn(X_half-300, 200, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half+300, 200, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.SCALY, CL.CYAN)
		en_item(PowerGhost, 5)
		en_spawn(X_half, 350, OBJ_ONMYOU, hp, 3, 3)--2
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half-300, 450, OBJ_ONMYOU, hp, 3, 3)--3
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half+300, 450, OBJ_ONMYOU, hp, 3, 3)--3
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half-300, 700, OBJ_ONMYOU, hp, 3, 3)--4
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half+300, 700, OBJ_ONMYOU, hp, 3, 3)--4
		en_bullet(IMG.SCALY, CL.CYAN)
		en_item(PowerGhost, 5)
	end
	if(num==6)then return end
	if (isTime(time+683))then
		en_spawn(X_half-300, 200, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half+300, 200, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.SCALY, CL.CYAN)
		en_item(PowerGhost, 5)
		en_spawn(X_half, 350, OBJ_ONMYOU, hp, 3, 3)--2
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half-300, 450, OBJ_ONMYOU, hp, 3, 3)--3
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half+300, 450, OBJ_ONMYOU, hp, 3, 3)--3
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half, 550, OBJ_ONMYOU, hp, 3, 3)--4
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half-300, 700, OBJ_ONMYOU, hp, 3, 3)--5
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half+300, 700, OBJ_ONMYOU, hp, 3, 3)--5
		en_bullet(IMG.SCALY, CL.CYAN)
		en_item(PowerGhost, 5)
	end
	if(num==7)then return end
	if (isTime(time+790))then
		en_spawn(X_half-300, 200, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 1)
		en_spawn(X_half+300, 200, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.SCALY, CL.CYAN)
		en_item(PowerGhost, 1)
		en_spawn(X_half-300, 400, OBJ_ONMYOU, hp, 3, 3)--2
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 1)
		en_spawn(X_half+300, 400, OBJ_ONMYOU, hp, 3, 3)--2
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 1)
		en_spawn(X_half, 500, OBJ_ONMYOU, hp, 3, 3)--3
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 1)
		en_spawn(X_half-300, 600, OBJ_ONMYOU, hp, 3, 3)--4
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 1)
		en_spawn(X_half+300, 600, OBJ_ONMYOU, hp, 3, 3)--4
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half-300, 800, OBJ_ONMYOU, hp, 3, 3)--5
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 1)
		en_spawn(X_half+300, 800, OBJ_ONMYOU, hp, 3, 3)--5
		en_bullet(IMG.SCALY, CL.CYAN)
		en_item(PowerGhost, 1)
	end
	if(num==8)then return end
	if (isTime(time+930))then
		en_spawn(X_half-300, 200, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half+300, 200, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.SCALY, CL.CYAN)
		en_item(PowerGhost, 5)
		en_spawn(X_half, 300, OBJ_ONMYOU, hp, 3, 3)--2
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half-300, 400, OBJ_ONMYOU, hp, 3, 3)--3
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half+300, 400, OBJ_ONMYOU, hp, 3, 3)--3
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half-300, 600, OBJ_ONMYOU, hp, 3, 3)--4
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half+300, 600, OBJ_ONMYOU, hp, 3, 3)--4
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half, 700, OBJ_ONMYOU, hp, 3, 3)--5
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half-300, 800, OBJ_ONMYOU, hp, 3, 3)--6
		en_bullet(IMG.SCALY, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(X_half+300, 800, OBJ_ONMYOU, hp, 3, 3)--6
		en_bullet(IMG.SCALY, CL.CYAN)
		en_item(PowerGhost, 5)
	end
	if(num==9)then return end
	if (isTime(time+1030))then
		for i=0,11 do
			en_spawn(X_half+rand(300), 500+rand(300), OBJ_ONMYOU, hp, 3, 3)--6
			en_bullet(IMG.SCALY, CL.CYAN)
			en_item(PowerGhost, 5)
		end
	end
	if(num==10)then return end
	if (isTime(time+1156))then
		for i=0,12 do
			en_spawn(X_half+rand(300), 500+rand(300), OBJ_ONMYOU, hp, 3, 3)--6
			en_bullet(IMG.SCALY, CL.PINK)
			en_item(PowerGhost, 5)
		end
	end
	if(num==11)then return end
	if (isTime(time+1268))then
		for i=0,12 do
			en_spawn(X_half+rand(300), 500+rand(300), OBJ_ONMYOU, hp, 3, 3)--6
			en_bullet(IMG.SCALY, CL.GREEN)
			en_item(PowerGhost, 5)
		end
	end
end

--@EndScript