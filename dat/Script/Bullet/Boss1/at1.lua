dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.set(Time(60), HP(8300))
end

function BossShot()
	bTime = shot_time % 200

	if(bTime < 70)then Boss.setSerifBox(Boss.getX(),Boss.getY()-250,1,"ƒeƒ“ƒVƒ‡ƒ“ã‚°‚Äô") end
	if(bTime == 1)then Boss.Motion(0) end
	if(bTime == 10)then boss_SE(LAZER01)
		Boss.Motion(1)
		num = diff(6,24,34,0)
		et_l.standType(IMG.BIG)
		et_l.size(120, 1)
		et_l.ring(num, 250, IMG.CLOCK_LAZ, CL.RED, 0, rd_h.Boss_Player() + PI/4-PI/6, 1)
	end
	if(between(bTime, 60, 100) and bTime % diff(18,12,6,0) == 0)then boss_SE(KIRAN)
		Boss.Motion(0)
		et_s.rota(true)
		et_s.ring(diff(30,36,42,0), 0, IMG.MINI_STAR, CL.ORANGE, sp_(5,6,8,0), rd_h.Boss_Player() + rand(PI/7), 0)
	end

	if(bTime == 130)then boss_SE(GYUUUUUUN)
		Boss.Motion(1)
		num = diff(6,24,34,0)
		et_l.standType(IMG.BIG)
		et_l.size(120, 1)
		et_l.ring(num, 250, IMG.CLOCK_LAZ, CL.RED, 0, rd_h.Boss_Player() - PI/4 + PI/6, 2)
	end
	if(bTime == 190)then Boss.Motion(0) end

	for l_num = 0 , LAZER_MAX do TransL(l_num) end
end

function TransL(l_num)
	if (Lazer.isFlag(l_num)) then
		Lazer.isCollision()
		if(Lazer.getCount(l_num) == 0)then Lazer.addAngle(PI) end
		if(Lazer.getState1(l_num) == 1)then 
			if(Lazer.getCount(l_num) < 60)then 
				Lazer.addAngle(PI2/4/60)
				Lazer.addThick(30/60)
				Lazer.addLength(350/60)
			end
		end
		if(Lazer.getState1(l_num) == 2)then 
			if(Lazer.getCount(l_num) < 60)then 
				Lazer.addAngle(-PI2/4/60)
				Lazer.addThick(30/60)
				Lazer.addLength(350/60)
			end
		end
		if(Lazer.getCount(l_num) == 60)then Lazer.setSpeed(7) end
	end
end

--@EndScript