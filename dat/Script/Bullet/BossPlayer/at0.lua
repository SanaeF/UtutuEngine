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
	Homing_Now = 0

	for bl_num = 0, LAZER_MAX do 
		if(Lazer.isFlag(bl_num))then
			Lazer_Now = 1
			if(Lazer.getCount(bl_num) < 80)then
				sx, sy = Param2(Lazer.getX(bl_num), Lazer.getY(bl_num))
				angle = homing(sx, sy, px, py)
				Lazer.setAngle(angle)
			end
			if(Lazer.getCount(bl_num) == 130)then se_play(LAZER01) end
			if(between(Lazer.getCount(bl_num), 130, 150))then
				Lazer.addThick(1)
				Lazer.isCollision()
			end
			if(between(Lazer.getCount(bl_num), 200, 220))then
				Lazer.addThick(-1)
				Lazer.isNotCollision()
			end
			if(Lazer.getCount(bl_num) > 220)then
				setBulletState(0)
				Lazer.clear()
			end
		end
	end
	for bl_num = 0, SHOT_MAX do
		if(Shot.isFlag(bl_num))then
			if(Shot.getState1(bl_num) == 1 and Shot.getCount(bl_num) < 160)then
				sx, sy = Param2(Shot.getX(bl_num), Shot.getY(bl_num))
				Homing_Now = 1
				Shot.setAngle(homing(sx, sy, px, py))
			end
		end
	end

	if(Player.getKeyInput(who, 0) > 0)then
		if (bTime % 10 == 3)then se_play(BULLET01)
			angle = homing(bx, by, px, py)
			et_s.rayer(0)
			et_s.rota(true)
			et_s.ring(15, 0, IMG.BIG, CL.ORANGE, 11, angle, 0)
		end
	end
	if(Player.getKeyInput(who, 1) > 0)then
		if (Lazer_Now == 0)then se_play(BULLET01)
			angle = PI / 2
			Lazer.Create(Boss.get_x() + 200, 20, IMG.LAZER, CL.YELLOW, 0, angle, 0)
			Lazer.setType(IMG.NORMAL)
			Lazer.setThick(2)
			Lazer.setLength(3000)
			Lazer.setWho(0)
			Lazer.Create(Boss.get_x() - 200, 20, IMG.LAZER, CL.YELLOW, 0, angle, 0)
			Lazer.setType(IMG.NORMAL)
			Lazer.setThick(2)
			Lazer.setLength(3000)
			Lazer.setWho(0)
		end
	end
	if(Player.getKeyInput(who, 2) > 0)then
		if (Homing_Now == 0)then se_play(BULLET01)
			angle = PI / 2
			Shot.Create(bx, by, IMG.B_FLY, CL.YELLOW, 4.3, angle, 1)
		end
	end
end

BossShot(shot_time)

--@EndScript