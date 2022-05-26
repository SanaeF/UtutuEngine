dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(3)
	Boss.noDamage(false)
	Boss.set(Time(24), HP(5600))
end

function BossShot()
	bTime = shot_time % 300

	Boss.Motion(1)
	if(shot_time == 1)then boss_SE(GYUUUUUUN)
		Boss.setSerifBox(Boss.getX(),Boss.getY()-250,100,"アクセル全開!!") 
		InitClock()
	end
	if(between(bTime, 40, 100) and bTime % diff(5,4,3,0) == 0)then boss_SE(BULLET02)
		add_rd = PI/diff(68,56,43,0) * (bTime/6 - 40)
		et_s.ringAt(Boss.getX() + 80, Boss.getY() - 120,diff(17,19,24,0), 0, IMG.NORMAL, CL.PINK, sp_(7,7,9,0), add_rd, 0)
	end
	if(between(bTime, 120, 180) and bTime % diff(5,4,3,0) == 0)then boss_SE(BULLET02)
		add_rd = PI/diff(68,56,43,0) * (bTime/6 - 40)
		et_s.ringAt(Boss.getX() + 80, Boss.getY() - 120,diff(17,19,24,0), 0, IMG.NORMAL, CL.PINK, sp_(7,7,9,0), -add_rd, 0)
	end
	if(between(bTime, 180, 280) and bTime % diff(30,30,30,0) == 15)then boss_SE(KIRAN)
		et_s.rota(true)
		et_s.ring(diff(17,19,36,0), 0, IMG.BIG_STAR, CL.RED, sp_(7,7,9,0), rd_h.Boss_Player(), 0)
	end
	for l_num = 0 , LAZER_MAX do TransL(l_num) end
end

function InitClock()
	Lazer.Create(Boss.getX() + 80, Boss.getY() - 120, IMG.CLOCK_LAZ, CL.BLUE, 0, PI2 + PI/2, 0)
	Lazer.setType(IMG.NORMAL)
	Lazer.setThick(1)
	Lazer.setLength(250)
end

function TransL(l_num)
	if (Lazer.isFlag(l_num))then
		Lazer.isCollision()
		if (Lazer.getThick(l_num) < 35)then Lazer.addThick(1) end
		if (Lazer.getState1(l_num) == 0)then 
			Lazer.addAngle(PI/10)
		end
		Lazer.setX(Boss.getX() + 80)
		Lazer.setY(Boss.getY() - 120)
	end
end

--@EndScript