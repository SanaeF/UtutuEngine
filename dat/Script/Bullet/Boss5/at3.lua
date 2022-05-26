dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.set(Time(60), HP(9000))
end

function BossShot()
	bTime = shot_time % 320

	if(shot_time < 100)then Boss.setSerifBox(Boss.getX(),Boss.getY()-250,1,"スプラッシュローズ♪") end
	BossAction(bTime)
	if(bTime == 40)then boss_SE(LAZER01)
		num = diff(3,5,7,0)
		bx,by=Param2(Boss.getX()-50, Boss.getY()-100)
		et_l.rota_angle(PI/4)
		et_l.size(100, 15)
		et_l.bound(true)
		et_l.collision(true)
		et_l.noDelete(true)
		et_l.nwayAt(bx,by, num , 1, 0, IMG.NORMAL, CL.CYAN, 5, 0, PI/(num*2), rd_h.toPlayer(bx,by), 0)
		et_l.rota_angle(-PI/4)
		et_l.size(100, 15)
		et_l.bound(true)
		et_l.collision(true)
		et_l.noDelete(true)
		et_l.nwayAt(bx,by, num , 1, 0, IMG.NORMAL, CL.CYAN, 5, 0, PI/(num*2), rd_h.toPlayer(bx,by), 1)
	end

	for l_num = 0 , LAZER_MAX do TransL(l_num,bTime) end
end

function BossAction(bTime)
	if(shot_time==0)then 
		Boss.Motion(0)
		move(F_HALF_X, F_HALF_Y, 30)
	end
	if(bTime==0)then Boss.Motion(0)	end

	if(bTime==80)then 
		move(F_MAX_X-100, F_MAX_Y-100, 20)
	end
	if(bTime==110)then 
		move(100, F_MAX_Y-100, 20)
		setRose()
	end
	if(bTime==140)then 
		move(F_MAX_X-100, 200, 20)
		setRose()
	end
	if(bTime==170)then 
		move(100, 200, 20)
		setRose()
	end
	if(bTime==200)then 
		move(F_HALF_X, F_HALF_Y, 30)
		setRose()
	end
	if(bTime==270)then 
		Boss.Motion(1)
		Boss.charge()
	end
end

function setRose()
	boss_SE(KIRAN)
	bx,by=Param2(Boss.getX()-50, Boss.getY()-100)
	petal_num=7
	num = diff(6,7,9,0)
	for ite=0,petal_num do
		et_l.rota_angle(PI2/petal_num*ite)
		et_l.size(80, 25)
		et_l.collision(true)
		et_l.noDelete(true)
		et_l.standType(IMG.NORMAL)
		et_l.ringAt(bx,by, num, 0, IMG.POIFUL, CL.RED, 3, rd_h.toPlayer(bx,by), 2)
		et_l.rota_angle(PI2/petal_num*ite+PI/petal_num)
		et_l.size(60, 15)
		et_l.collision(true)
		et_l.noDelete(true)
		et_l.standType(IMG.NORMAL)
		et_l.ringAt(bx,by, num, 0, IMG.PETAL, CL.PINK, 3, rd_h.toPlayer(bx,by), 3)
	end
end

function TransL(l_num,bTime)
	if (Lazer.isFlag(l_num)) then
		if(Lazer.getBoundCount(l_num)>1)then Lazer.isNotBound() end
		if(Lazer.getState1(l_num)==0)then 
			Lazer.setRota(10,40,-PI/4)
			Lazer.setRota(50,80,PI/4)
			if(Lazer.getCount(l_num)==90)then Lazer.setCount(10) end
		end
		if(Lazer.getState1(l_num)==1)then 
			Lazer.setRota(10,40,PI/4)
			Lazer.setRota(50,80,-PI/4)
			if(Lazer.getCount(l_num)==90)then Lazer.setCount(10) end
		end
		if(Lazer.getState1(l_num)==2)then Lazer.setLengthAngle(Lazer.getLengthAngle(l_num)+PI/128) end
		if(Lazer.getState1(l_num)==3)then Lazer.setLengthAngle(Lazer.getLengthAngle(l_num)-PI/128) end
		if(bTime==0)then
			num = diff(5,6,7,0)
			if(Lazer.getState1(l_num)==2)then boss_SE(KIRAN)
				lx,ly=Param2(Lazer.getX(l_num),Lazer.getY(l_num))
				Shot.Create(lx,ly, IMG.PETAL, CL.PURPLE, -4, Lazer.getLengthAngle(l_num), 0)
				Lazer.clear()
			end
			if(Lazer.getState1(l_num)==3)then boss_SE(KIRAN)
				lx,ly=Param2(Lazer.getX(l_num),Lazer.getY(l_num))
				Shot.Create(lx,ly, IMG.PETAL, CL.PINK, -3, Lazer.getLengthAngle(l_num), 0)
				Lazer.clear()
			end
		end
	end
end

--@EndScript