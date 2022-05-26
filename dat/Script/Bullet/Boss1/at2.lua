dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(1)
	Boss.noDamage(true)
	Boss.setMainBullet()
	Boss.set(Time(36), HP(66666))
end

function BossShot()
	bTime = shot_time % 100

	if(shot_time < 180)then Boss.setSerifBox(Boss.getX(),Boss.getY()-250,1,"‚ß!—ë‚Ìƒ[ƒc") end
	if(shot_time == 1)then boss_SE(LAZER01)
		InitClock()
		move((FMAX_X - FMIN_X) / 2, (FMAX_Y - FMIN_Y) / 2, 40)
	end
	if(shot_time > 50 and bTime % diff(77,79,67,0) == 0)then boss_SE(BULLET01)
		Boss.Motion(1)
		et_s.ring(diff(7,10,15,0), 180, IMG.OVERLAP, CL.PINK, -sp_(2,2,3,0), rd_h.Boss_Player() + rand(PI/7), 0)
	end
	for l_num = 0 , LAZER_MAX do TransL(l_num) end
end

function InitClock()
	Lazer.Create(Boss.getX(), Boss.getY(), IMG.CLOCK_LAZ, CL.BLUE, 0, -PI, 0)
	Lazer.setType(IMG.NORMAL)
	Lazer.setThick(10)
	Lazer.setLength(720)
	Lazer.Create(Boss.getX(), Boss.getY(), IMG.CLOCK_LAZ, CL.BLUE, 0, PI2 + PI/2, 1)
	Lazer.setType(IMG.NORMAL)
	Lazer.setThick(1)
	Lazer.setLength(150)
end

function TransL(l_num)
	if (Lazer.isFlag(l_num))then
		Lazer.isCollision()
		if (Lazer.getCount(l_num) < 20)then Lazer.addThick(1) end

		if (Lazer.getState1(l_num) == 0)then 
			add_rd = (PI2/(12 * 60)) * shot_time - PI/2
			Lazer.setX(x_dt(Boss.getX(), add_rd, 180))
			Lazer.setY(y_dt(Boss.getY(), add_rd, 180))
			Lazer.setAngle(add_rd)
		end
		if (Lazer.getState1(l_num) == 1)then 
			add_rd = (PI2/(12 * 360)) * shot_time + PI/2
			Lazer.setX(x_dt(Boss.getX(), add_rd, 180))
			Lazer.setY(y_dt(Boss.getY(), add_rd, 180))
			Lazer.setAngle(add_rd)
		end
	end
end

--@EndScript