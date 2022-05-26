dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.set(Time(45), HP(5500))
end

function BossShot()
	bTime = shot_time % 350

	if(bTime == 0)then
		Boss.Motion(0)
		Boss.charge()
	end
	if(bTime == 0)then 
		Lazer.Create(Boss.getX(), Boss.getY(), IMG.POIFUL, CL.YELLOW, 0, rd_h.set(), 0)
		Lazer.setType(IMG.BIG)
		Lazer.setLength(2500)
		Lazer.setThick(1)
		Lazer.isNotCollision()
	end
	if(between(bTime, 10, 200) and bTime % diff(21,16,10,0)  == 0)then boss_SE(BULLET02)
		et_s.ring(diff(17,21,47,0), 0, IMG.TRAMP , CL.RED, sp_(5,7,10,0), rd_h.set()+rand(PI/3), 0)
	end
	for l_num = 0 , LAZER_MAX do TransL(l_num) end
end

function TransL(l_num)
	if (Lazer.isFlag(l_num)) then
		if(Lazer.getCount(l_num)==100)then 
			boss_SE(GYUUUUUUN)
			Boss.Motion(1)
		end
		if(between(Lazer.getCount(l_num),100,140))then 
			Lazer.isCollision()
			Lazer.addThick(8)
		end
		if(between(Lazer.getCount(l_num),200,240))then 
			Lazer.addThick(-8)
		end
		if(Lazer.getCount(l_num)==240)then 
			Lazer.clear()
			Boss.Motion(0)
		end
	end
end

--@EndScript