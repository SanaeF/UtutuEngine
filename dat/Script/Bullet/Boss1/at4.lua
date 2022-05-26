dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.set(Time(45), HP(9800))
end

function BossShot()
	bTime = shot_time % 480

	if(shot_time < 100)then Boss.setSerifBox(Boss.getX(),Boss.getY()-250,1,"‹­‚ß‚Ìs‚­‚æ‚§`ô") end
	if(bTime == 1)then Boss.Motion(0) end
	if(bTime == 10)then boss_SE(LAZER01)
		Boss.Motion(1)
		num = diff(6,10,18,0)
		et_l.standType(IMG.BIG)
		et_l.size(120, 1)
		et_l.ring(num, 250, IMG.CLOCK_LAZ, CL.CYAN, 0, rd_h.Boss_Player(), 1)
	end
	if(bTime % diff(34,28,24,0) == 0)then boss_SE(KIRAN)
		Boss.Motion(0)
		et_s.rota(true)
		et_s.ring(diff(8,12,18,0), 0, IMG.BIG_STAR, CL.GREEN, sp_(4,5,7,0), 0, 0)
	end

	if(bTime == 240)then boss_SE(GYUUUUUUN)
		Boss.Motion(1)
		num = diff(6,10,12,0)
		et_l.standType(IMG.BIG)
		et_l.size(120, 1)
		et_l.ring(num, 250, IMG.CLOCK_LAZ, CL.CYAN, 0, rd_h.Boss_Player(), 2)
	end
	if(bTime == 190)then Boss.Motion(0) end

	for l_num = 0 , LAZER_MAX do TransL(l_num) end
end

function TransL(l_num)
	time_dist = 240
	if (Lazer.isFlag(l_num)) then
		Lazer.isCollision()
		if(Lazer.getCount(l_num) == 0)then Lazer.addAngle(PI) end
		if(Lazer.getState1(l_num) == 1)then 
			if(Lazer.getCount(l_num) < time_dist)then 
				Lazer.addAngle(PI/time_dist)
				Lazer.addThick(30/time_dist)
				Lazer.addLength(700/time_dist)
			end
		end
		if(Lazer.getState1(l_num) == 2)then 
			if(Lazer.getCount(l_num) < time_dist)then 
				Lazer.addAngle(-PI/time_dist)
				Lazer.addThick(40/time_dist)
				Lazer.addLength(700/time_dist)
			end
		end
		if(Lazer.getCount(l_num) == time_dist)then Lazer.clear() end
	end
end

--@EndScript