dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.set(Time(34), HP(4500))
end

function BossShot()
	bTime = shot_time % 250

	if(bTime == 0)then
		Boss.mv_stay()
		Boss.Motion(0)
		Boss.charge()
	end
	if(bTime == 0)then 
		Lazer.Create(Boss.getX(), Boss.getY(), IMG.POIFUL, CL.YELLOW, 0, PI/2, 0)
		Lazer.setType(IMG.BIG)
		Lazer.setLength(2500)
		Lazer.setThick(1)
		Lazer.isNotCollision()
	end
	if(between(bTime, 10, 150) and bTime % diff(32,23,16,0)  == 0)then boss_SE(BULLET02)
		et_s.ring(diff(17,26,35,0), 0, IMG.TRAMP , CL.RED, sp_(4,5,7,0), rand(PI/3), 0)
	end
	for l_num = 0 , LAZER_MAX do TransL(l_num) end
	for bl_num = 0 , SHOT_MAX do TransS(bl_num) end 
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
function TransS(bl_num)
	if (Shot.isFlag(bl_num)) then 
		x_half=(FMAX_X-FMIN_X)/2
		if (between(Shot.getX(bl_num), x_half-100, x_half+100) and Shot.getY(bl_num) > Boss.getY()+200)then 
			Shot.setColor(CL.BLUE)
			Shot.setAngle(rd_h.fShot_p(bl_num))
			Shot.addSpeed(0.03)
			Shot.setSize(1.5)
		end
	end
end

--@EndScript