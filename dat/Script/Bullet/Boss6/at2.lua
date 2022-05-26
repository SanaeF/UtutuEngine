dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.set(Time(60), HP(7500))
end

function BossShot()
	bTime = shot_time % 250

	if(bTime == 0)then
		Boss.mv_stay()
		Boss.Motion(0)
		Boss.charge()
	end
	if(bTime == 0)then 
		for ite=0,2 do
			Lazer.Create(Boss.getX()-60, Boss.getY()-100, IMG.POIFUL, CL.YELLOW, 0, PI/2, ite)
			Lazer.setType(IMG.BIG)
			Lazer.setLength(2500)
			Lazer.setThick(1)
			Lazer.isNotCollision()
		end
	end
	if(between(bTime, 10, 150) and bTime % 11 == 0)then boss_SE(BULLET02)
		et_s.ring(25, 0, IMG.TRAMP, CL.CYAN, 9, PI/(25*3)*(bTime/11), 0)
	end

	for l_num = 0 , LAZER_MAX do TransL(l_num) end
end

function TransL(l_num)
	if (Lazer.isFlag(l_num)) then
		if(Lazer.getCount(l_num)<70)then 
			lx,ly=Param2(Lazer.getX(l_num),Lazer.getY(l_num))
			angle=rd_h.toPlayer(lx,ly)-PI/2
			if(Lazer.getState1(l_num)==0)then angle=angle-PI/6 end
			if(Lazer.getState1(l_num)==1)then angle=angle+PI/6 end
			Lazer.setLengthAngle(angle) 
		end
		if(Lazer.getCount(l_num)==100)then 
			crush(10,40)
			boss_SE(GYUUUUUUN)
		end
		if(between(Lazer.getCount(l_num),100,140))then 
			Lazer.isCollision()
			Lazer.addThick(5)
		end
		if(between(Lazer.getCount(l_num),200,240))then 
			Lazer.addThick(-5)
		end
		if(Lazer.getCount(l_num)==240)then 
			Lazer.clear()
		end
	end
end

--@EndScript