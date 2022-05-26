dofile('./dat/Script/Bullet/Library.lua' )

Boss.cooldown_(1)
Boss.setLast()
Boss.set(Time(20), HP(2500))
Boss.noDamage(true)

function BossShot(bTime)
	who = Player.bossWho()
	who2 = Player.bossNotWho()
	bx, by = Param2(Boss.get_x(), Boss.get_y())
	px, py = Param2(Player.getX_who(who2), Player.getY_who(who2))
	Boss.set_x(Player.getX_who(who))
	ang = 17
	Lazer_Now = 0

	for bl_num = 0, LAZER_MAX do
		if(Lazer.isFlag(bl_num))then
			sx, sy = Param2(Lazer.getX(bl_num), Lazer.getY(bl_num))
			if(Lazer.getCount(bl_num) < 140)then
				angle = homing(sx, sy, px, py)+ PI2 / ang * Lazer.getState1(bl_num)
				Lazer.setAngle(angle)
				Lazer_Now = 1
			end
			if(between(Lazer.getCount(bl_num), 250, 260))then Lazer.addThick(0.8) end
			if(between(Lazer.getCount(bl_num), 285, 295))then Lazer.addThick(-0.8) end
			if(Lazer.getCount(bl_num) == 320)then Lazer.clear() end
		end
	end
	for bl_num = 0, SHOT_MAX do
		if(Shot.isFlag(bl_num) and Shot.getState1(bl_num) == 3)then
			if(Shot.getCount(bl_num) > 160)then Shot.setSpeed(4) end
		end
	end

	if(Player.getKeyInput(who, 0) > 0)then
		if (bTime % 7 == 3)then se_play(BULLET02)
			speed = 2 + rand(1)
			et_s.shine(true)
			n = et_s.outside(AREA_LEFT, IMG.OVERLAP , CL.RED, sp(speed), rd(0), st(1))
				Shot.setAngle(homing(Shot.getX(n), Shot.getY(n), bx, by))
			et_s.shine(true)
			n = et_s.outside(AREA_RIGHT, IMG.OVERLAP , CL.RED, sp(speed), rd(0), st(1))
				Shot.setAngle(homing(Shot.getX(n), Shot.getY(n), bx, by))
			et_s.shine(true)
			n = et_s.outside(AREA_UP, IMG.OVERLAP , CL.BLUE, sp(speed), rd(0), st(1))
				Shot.setAngle(homing(Shot.getX(n), Shot.getY(n), bx, by))
			et_s.shine(true)
			n = et_s.outside(AREA_DOWN, IMG.OVERLAP , CL.ORANGE, sp(speed), rd(0), st(1))
				Shot.setAngle(homing(Shot.getX(n), Shot.getY(n), bx, by))
		end
	end
	if(Player.getKeyInput(who, 1) > 0)then
		if (Lazer_Now == 0)then
			for n = 0 , ang - 1 do
				angle = PI2 / ang * n
				Lazer.Create(FMAX_X - FMIN_X, 0, IMG.NORMAL, CL.GREEN, sp(0), rd(angle), st(n))
				Lazer.setThick(2) Lazer.setLength(2000)
				Lazer.Create(0, 0, IMG.NORMAL, CL.GREEN, sp(0), rd(angle), st(n))
				Lazer.setThick(2) Lazer.setLength(2000)
				Lazer.Create(0, FMAX_Y - FMIN_Y, IMG.NORMAL, CL.GREEN, sp(0), rd(angle), st(n))
				Lazer.setThick(2) Lazer.setLength(2000)
				Lazer.Create(FMAX_X - FMIN_X, FMAX_Y - FMIN_Y, IMG.NORMAL, CL.GREEN, sp(0), rd(angle), st(n))
				Lazer.setThick(2) Lazer.setLength(2000)
			end
		end
	end
	if(Player.getKeyInput(who, 2) > 0)then
		for bl_num = 0, SHOT_MAX do
			if(Shot.isFlag(bl_num) and Shot.getState1(bl_num) == 1)then
				Range = 150
				Xdist = bx - Shot.getX(bl_num);
				Ydist = by - Shot.getY(bl_num);
				if ((sqrt(Xdist * Xdist) < Range) and sqrt(Ydist * Ydist) < Range)then
					Shot.setSpeed(0)
					Shot.setColor(CL.SKY)
					Shot.setCount(10)
					Shot.setState1(3)
				end
			end
		end
	end
end

BossShot(shot_time)

--@EndScript