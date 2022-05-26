dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(1)
	Boss.set(Time(60), HP(6000))
end

function BossShot()
	bTime = shot_time % 280
	if(bTime == 0)then
		Boss.Motion(1)
		move_rand(100, 180, (FMAX_X - FMIN_X) - 100, 500, 200, 100) 
	end

	if(bTime % 70 == 0)then boss_SE(GYUUUUUUN)
		num = diff(15,24,34,0)
		et_l.standType(IMG.NORMAL)
		et_l.size(1, 1)
		et_l.ringAt(Boss.getX()+80, Boss.getY(), num, 150, IMG.CLOCK_LAZ, CL.SKY, 0, rand(PI/num), 0)
		et_l.standType(IMG.NORMAL)
		et_l.size(1, 1)
		et_l.ringAt(Boss.getX()-80, Boss.getY(), num, 150, IMG.CLOCK_LAZ, CL.SKY, 0, rand(PI/num), 0)
	end
	if(between(bTime, 60, 200) and bTime % diff(18,16,15,0) == 0)then boss_SE(KIRAN)
		et_s.rota(true)
		et_s.ring(diff(20,24,30,0), 0, IMG.MINI_STAR, CL.RED, sp_(3,4,5,0), rd_h.Boss_Player() + rand(PI/7), 0)
	end

	for l_num = 0 , LAZER_MAX do TransL(l_num) end
end

function TransL(l_num)
	if (Lazer.isFlag(l_num)) then
		Lazer.isCollision()
		if(Lazer.getCount(l_num) < 60)then
			Lazer.addThick(10/60)
			Lazer.addLength(250/60)
		end
		if(Lazer.getCount(l_num) == 60)then Lazer.setSpeed(7) end
	end
end

--@EndScript