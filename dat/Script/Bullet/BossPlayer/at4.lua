dofile('./dat/Script/Bullet/Library.lua' )

Boss.cooldown_(1)
Boss.setLast()
Boss.set(Time(32), HP(2500))
Boss.noDamage(true)

function BossShot(bTime)
	who = Player.bossWho()
	who2 = Player.bossNotWho()
	bx, by = Param2(Boss.get_x(), Boss.get_y())
	px, py = Param2(Player.getX_who(who2), Player.getY_who(who2))
	Boss.set_x(Player.getX_who(who))
	Lazer_Now = 0
	Enemy_Now = 0

	for bl_num = 0, LAZER_MAX do
		if(Lazer.isFlag(bl_num))then
			Lazer_Now = 1
			if(between(Lazer.getCount(bl_num), 30, 40))then Lazer.addThick(1) end
			if(Lazer.getCount(bl_num) == 40)then Lazer.isCollision() end
			if(between(Lazer.getCount(bl_num), 200, 210))then
				Lazer.addThick(-1)
				Lazer.isNotCollision()
			end
			if(Lazer.getCount(bl_num) >= 210)then Lazer.clear() end

			if(Lazer.getColor(bl_num)==CL.ORANGE)then 
				Lazer.addAngle(PI / 83)
				Lazer.setX(x_dt(px, PI2 / 3 * Lazer.getState1(bl_num) + (PI / 600 * Lazer.getCount(bl_num)), 580))
				Lazer.setY(y_dt(by, PI2 / 3 * Lazer.getState1(bl_num) + (PI / 600 * Lazer.getCount(bl_num)), 580))
			end
			if(Lazer.getColor(bl_num)==CL.GREEN)then 
				Lazer.addAngle(-PI / 83)
				Lazer.setX(x_dt(px, PI2 / 3 * Lazer.getState1(bl_num) + (-PI / 600 * Lazer.getCount(bl_num)), 260))
				Lazer.setY(y_dt(by, PI2 / 3 * Lazer.getState1(bl_num) + (-PI / 600 * Lazer.getCount(bl_num)), 260))
			end
		end
	end
	for e_num = 0, MINION_MAX do
		if (Minion.isFlag(e_num))then
			Enemy_Now = 1
			Minion.setSize(Minion.getSize(e_num) + 0.01)
			if (Minion.getCount(e_num) % 34 == 30)then se_play(BULLET01)
				ex, ey = Param2(Minion.getX(e_num), Minion.getY(e_num))
				et_s.shine(true)
				et_s.ringAt(ex, ey, 15, 0, IMG.NORMAL, CL.YELLOW, 4, 0, 0)
			end
		end
	end

	if(Player.getKeyInput(who, 0) > 0)then
		if (bTime % 19 == 8)then se_play(BULLET02)
			et_s.shine(true)
			et_s.ring(15, 0, IMG.POIFUL, CL.SKY, 10, 0, 0)
		end
	end
	if(Player.getKeyInput(who, 1) > 0)then
		if(Lazer_Now == 0)then
			for n = 0, 5 do
				for n2 = 0, 3 do
					Lazer.Create(x_dt(bx, PI2 / 3 * n, 580), y_dt(by, PI2 / 3 * n, 580), IMG.OVERLAP, CL.ORANGE, 0, PI / 2 * n2, n)
					Lazer.setThick(2)
					Lazer.setLength(220)
					Lazer.setState2(n2)
				end
			end
			for n = 0, 5 do
				for n2 = 0, 3 do
					Lazer.Create(x_dt(bx, PI2 / 3 * n, 260), y_dt(by, PI2 / 3 * n, 260), IMG.OVERLAP, CL.GREEN, 0, PI / 2 * n2, n)
					Lazer.setThick(1)
					Lazer.setLength(120)
					Lazer.setState2(n2)
				end
			end
		end
	end
	if(Player.getKeyInput(who, 2) > 0)then
		if (Enemy_Now == 0)then
			en_spawn(px + rand(80), by + rand(80), OBJ_ONMYOU, 20, -1, -1, 0)
			Minion.setAngle(PI / 2)
			Minion.setSpeed(5)
		end
	end

end

BossShot(shot_time)

--@EndScript