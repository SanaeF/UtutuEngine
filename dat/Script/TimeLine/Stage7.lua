dofile( './dat/Script/Library/Timeline/TimelineSc.lua' )
dofile('./dat/Script/Timeline/ItemMinion/ItemMinion.lua')
dofile( './dat/Script/MinionProp/Bullet/Stage7/MinionBullet.lua' )
dofile( './dat/Script/MinionProp/Move/Stage7/MinionMover.lua' )

resetTime(10000)

function TimeLine()
	if (isTime(90))then TL.setSubTitle() end

	--左右に分かれる
	first_time=300
	if (isTime(first_time+50*0)or
		isTime(first_time+50*1)or
		isTime(first_time+50*2)or
		isTime(first_time+50*3)or
		isTime(first_time+50*4)or
		isTime(first_time+50*5)) then
		en_spawn(F_HALF_X-400+rand(100), 0, DEV_NORMAL, 80, 0, 0)
		en_bullet(IMG.BIG_STAR, CL.CYAN)
		en_item(PowerGhost, 5)
	end
	first_time=325
	if (isTime(first_time+50*0)or
		isTime(first_time+50*1)or
		isTime(first_time+50*2)or
		isTime(first_time+50*3)or
		isTime(first_time+50*4)or
		isTime(first_time+50*5)) then
		en_spawn(F_HALF_X+400+rand(100), 0, DEV_NORMAL, 80, 0, 1)
		en_bullet(IMG.BIG_STAR, CL.CYAN)
		en_item(PowerGhost, 5)
	end

	if (isTime(850)) then
		en_spawn(F_HALF_X + 300, 0, DEV_ORANGE, 280, 1, 2)
		en_bullet(IMG.BIG, CL.ORANGE)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X - 300, 0, DEV_ORANGE, 280, 1, 2)
		en_bullet(IMG.BIG, CL.ORANGE)
		en_item(PowerGhost, 5)
	end

	if (isTime(1250)) then
		en_spawn(F_HALF_X + 200, 0, DEV_GREEN, 280, 1, 2)
		en_bullet(IMG.BIG, CL.SKY)
		en_item(Apple, 1)
		en_spawn(F_HALF_X - 200, 0, DEV_GREEN, 280, 1, 2)
		en_bullet(IMG.BIG, CL.SKY)
		en_item(Apple, 1)
	end

	rhythmSpawner1()

	first_time=2490
	if (isTime(first_time+30*0))then rush(200,CL.YELLOW) end
	if (isTime(first_time+30*1))then rush(210,CL.YELLOW) end
	if (isTime(first_time+30*2))then rush(220,CL.YELLOW) end
	if (isTime(first_time+30*3))then rush(230,CL.YELLOW) end
	if (isTime(first_time+30*4))then rush(240,CL.YELLOW) end
	if (isTime(first_time+30*5))then rush(250,CL.YELLOW) end
	if (isTime(first_time+30*6))then rush(260,CL.ORANGE) end
	if (isTime(first_time+30*7))then rush(270,CL.ORANGE) end
	if (isTime(first_time+30*8))then rush(280,CL.ORANGE) end
	if (isTime(first_time+30*9))then rush(290,CL.ORANGE) end
	if (isTime(first_time+30*10))then rush(300,CL.ORANGE) end
	if (isTime(first_time+30*11))then rush(310,CL.CYAN) end
	if (isTime(first_time+30*12))then rush(320,CL.CYAN) end
	if (isTime(first_time+30*13))then rush(330,CL.CYAN) end
	if (isTime(first_time+30*14))then rush(340,CL.CYAN) end
	if (isTime(first_time+30*15))then rush(350,CL.CYAN) end

	first_time=3273
	if (isTime(first_time+30*0))then rush2(100,CL.BLUE) end
	if (isTime(first_time+30*1))then rush2(110,CL.BLUE) end
	if (isTime(first_time+30*2))then rush2(120,CL.BLUE) end
	if (isTime(first_time+30*3))then rush2(130,CL.BLUE) end
	if (isTime(first_time+30*4))then rush2(140,CL.BLUE) end
	if (isTime(first_time+30*5))then rush2(150,CL.BLUE) end
	if (isTime(first_time+30*6))then rush2(160,CL.PURPLE) end
	if (isTime(first_time+30*7))then rush2(170,CL.PURPLE) end
	if (isTime(first_time+30*8))then rush2(180,CL.PURPLE) end
	if (isTime(first_time+30*9))then rush2(190,CL.PURPLE) end
	if (isTime(first_time+30*10))then rush2(200,CL.PURPLE) end
	if (isTime(first_time+30*11))then rush2(210,CL.PINK) end
	if (isTime(first_time+30*12))then rush2(220,CL.PINK) end
	if (isTime(first_time+30*13))then rush2(230,CL.PINK) end
	if (isTime(first_time+30*14))then rush2(240,CL.PINK) end
	if (isTime(first_time+30*15))then rush2(250,CL.PINK) end

	if (isTime(4050))then
		en_spawn(F_HALF_X-400+rand(100), 0, DEV_ORANGE, 680, 0, 0)
		en_bullet(IMG.MEGA, CL.RED)
		en_item(Apple, 1)
		en_spawn(F_HALF_X+400+rand(100), 0, DEV_ORANGE, 680, 0, 1)
		en_bullet(IMG.MEGA, CL.RED)
		en_item(Apple, 1)
	end

	if (isTime(4450))then
		en_spawn(F_HALF_X-400+rand(100), 0, DEV_ORANGE, 680, 0, 0)
		en_bullet(IMG.MEGA, CL.ORANGE)
		en_item(Apple, 1)
		en_spawn(F_HALF_X+400+rand(100), 0, DEV_ORANGE, 680, 0, 1)
		en_bullet(IMG.MEGA, CL.ORANGE)
		en_item(Apple, 1)
	end

	if (isTime(4840))then
		en_spawn(F_HALF_X-400+rand(100), 0, DEV_ORANGE, 680, 0, 0)
		en_bullet(IMG.MEGA, CL.YELLOW)
		en_item(Apple, 1)
		en_spawn(F_HALF_X+400+rand(100), 0, DEV_ORANGE, 680, 0, 1)
		en_bullet(IMG.MEGA, CL.YELLOW)
		en_item(Apple, 1)
	end

	if (isTime(5220))then
		en_spawn(F_HALF_X-400+rand(100), 0, DEV_GREEN, 680, 0, 0)
		en_bullet(IMG.MEGA, CL.CYAN)
		en_item(Apple, 1)
		en_spawn(F_HALF_X+400+rand(100), 0, DEV_GREEN, 680, 0, 1)
		en_bullet(IMG.MEGA, CL.CYAN)
		en_item(Apple, 1)
	end

	if (isTime(5560))then
		en_spawn(F_HALF_X+300, 0, DEV_GREEN, 1780, 4, 7)
		en_bullet(IMG.POIFUL, CL.PINK)
		en_item(PowerGhost, 10)
	end

	if (isTime(5957))then
		en_spawn(F_HALF_X-300, 0, DEV_GREEN, 1780, 4, 7)
		en_bullet(IMG.POIFUL, CL.RED)
		en_item(PowerGhost, 10)
	end

	--中ボス
	if (isTime(6408))then TL.setTalkScene(17) end
	enter_boss_time=6706
	if (isTime(enter_boss_time))then TL.setTalkScene(18) end
	if (isTime(enter_boss_time+20))then TL.setTalkScene(19) end
	if (isTime(enter_boss_time+50))then TL.setEnding() end
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

function rhythmSpawner1()
	hp=80
	if (isTime(1670)) then
		en_spawn(F_HALF_X-300, 400, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X+300, 400, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.MEGA, CL.CYAN)
		en_item(PowerGhost, 5)
	end
	if (isTime(1765)) then
		en_spawn(F_HALF_X, 300, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X-150, 500, OBJ_ONMYOU, hp, 3, 3)--2
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X+150, 500, OBJ_ONMYOU, hp, 3, 3)--2
		en_bullet(IMG.MEGA, CL.CYAN)
		en_item(PowerGhost, 5)
	end
	if (isTime(1860)) then
		en_spawn(F_HALF_X-200, 300, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X+200, 300, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.MEGA, CL.CYAN)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X-200, 600, OBJ_ONMYOU, hp, 3, 3)--2
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X+200, 600, OBJ_ONMYOU, hp, 3, 3)--2
		en_bullet(IMG.MEGA, CL.CYAN)
		en_item(PowerGhost, 5)
	end
	if (isTime(1970)) then
		en_spawn(F_HALF_X-300, 200, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X+300, 200, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.MEGA, CL.CYAN)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X, 450, OBJ_ONMYOU, hp, 3, 3)--2
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X-300, 700, OBJ_ONMYOU, hp, 3, 3)--3
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X+300, 700, OBJ_ONMYOU, hp, 3, 3)--3
		en_bullet(IMG.MEGA, CL.CYAN)
		en_item(PowerGhost, 5)
	end
	if (isTime(2060)) then
		en_spawn(F_HALF_X-300, 200, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X+300, 200, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.MEGA, CL.CYAN)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X-300, 450, OBJ_ONMYOU, hp, 3, 3)--2
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X+300, 450, OBJ_ONMYOU, hp, 3, 3)--2
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X-300, 700, OBJ_ONMYOU, hp, 3, 3)--3
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X+300, 700, OBJ_ONMYOU, hp, 3, 3)--3
		en_bullet(IMG.MEGA, CL.CYAN)
		en_item(PowerGhost, 5)
	end
	if (isTime(2160)) then
		en_spawn(F_HALF_X-300, 200, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X+300, 200, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.MEGA, CL.CYAN)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X, 350, OBJ_ONMYOU, hp, 3, 3)--2
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X-300, 450, OBJ_ONMYOU, hp, 3, 3)--3
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X+300, 450, OBJ_ONMYOU, hp, 3, 3)--3
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X-300, 700, OBJ_ONMYOU, hp, 3, 3)--4
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X+300, 700, OBJ_ONMYOU, hp, 3, 3)--4
		en_bullet(IMG.MEGA, CL.CYAN)
		en_item(PowerGhost, 5)
	end
	if (isTime(2265)) then
		en_spawn(F_HALF_X-300, 200, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X+300, 200, OBJ_ONMYOU, hp, 3, 3)--1
		en_bullet(IMG.MEGA, CL.CYAN)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X, 350, OBJ_ONMYOU, hp, 3, 3)--2
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X-300, 450, OBJ_ONMYOU, hp, 3, 3)--3
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X+300, 450, OBJ_ONMYOU, hp, 3, 3)--3
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X, 550, OBJ_ONMYOU, hp, 3, 3)--4
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X-300, 700, OBJ_ONMYOU, hp, 3, 3)--5
		en_bullet(IMG.MEGA, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(F_HALF_X+300, 700, OBJ_ONMYOU, hp, 3, 3)--5
		en_bullet(IMG.MEGA, CL.CYAN)
		en_item(PowerGhost, 5)
	end
end

function rush(y,color)
	en_spawn(0, y, OBJ_ONMYOU, 80, 2, 4)
	en_bullet(IMG.POIFUL, color)
	en_item(PowerGhost, 3)
	en_spawn(F_MAX_X, y, OBJ_ONMYOU, 80, 2, 5)
	en_bullet(IMG.POIFUL, color)
	en_item(PowerGhost, 3)
end

function rush2(x,color)
	en_spawn(0+x, 0, OBJ_ONMYOU, 60, 2, 6)
	en_bullet(IMG.POIFUL, color)
	en_item(PowerGhost, 3)
	en_spawn(F_MAX_X-x, 0, OBJ_ONMYOU, 60, 2, 6)
	en_bullet(IMG.POIFUL, color)
	en_item(PowerGhost, 3)
end

--@EndScript