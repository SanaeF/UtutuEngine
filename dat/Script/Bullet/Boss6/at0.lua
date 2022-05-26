dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.set(Time(34), HP(7000))
end

function BossShot()
	bTime = shot_time % 320

	if(bTime == 0)then
		Boss.mv_stay()
		Boss.Motion(0)
		Boss.charge()
	end
	if(bTime == 0)then 
		Lazer.Create(Boss.getX()-60, Boss.getY()-100, IMG.POIFUL, CL.YELLOW, 0, PI/2, 0)
		Lazer.setType(IMG.BIG)
		Lazer.setLength(2500)
		Lazer.setThick(1)
		Lazer.isNotCollision()
	end
	if(between(bTime,0,150) and bTime%8 == 0)then boss_SE(BULLET02)
		et_s.ring(27, 0, IMG.TRAMP, CL.CYAN, 10, PI/27*(bTime/8), 0)
	end

	for l_num = 0 , LAZER_MAX do TransL(l_num) end
end

function TransL(l_num)
	if (Lazer.isFlag(l_num)) then
		if(Lazer.getCount(l_num)<60)then 
			lx,ly=Param2(Lazer.getX(l_num),Lazer.getY(l_num))
			Lazer.setLengthAngle(rd_h.toPlayer(lx,ly)-PI/2) 
		end
		if(Lazer.getCount(l_num)==100)then 
			crush(10,90)
			boss_SE(GYUUUUUUN)
		end
		if(between(Lazer.getCount(l_num),100,190))then 
			Lazer.isCollision()
			Lazer.addThick(4)
		end
		if(between(Lazer.getCount(l_num),200,290))then 
			Lazer.addThick(-4)
		end
		if(Lazer.getCount(l_num)==290)then 
			Lazer.clear()
		end
	end
end

--@EndScript