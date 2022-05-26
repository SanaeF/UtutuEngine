dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.set(Time(45), HP(7000))
end

function BossShot()
	bTime = shot_time % 300

	if(shot_time < 100)then Boss.setSerifBox(Boss.getX(),Boss.getY()-250,1,"チョキ♪チョキ♪") end
	if(bTime==0)then
		Boss.Motion(0)
		Boss.charge()
		move_rand(FMIN_X + 100, 180, FMAX_X - FMIN_X - 100, 500, 80, 60)
	end
	sp=4
	if(bTime==0 or bTime==140)then boss_SE(BULLET02)
		move_rand(FMIN_X + 100, 180, FMAX_X - FMIN_X - 100, 500, 80, 60)
		bx,by=Param2(Boss.getX()-50, Boss.getY()-100)
		num=diff(48,52,56,0)
		et_l.rota_angle(PI/4)
		et_l.size(100, 15)
		et_l.collision(true)
		et_l.noDelete(true)
		et_l.ringAt(bx, by, num, 0, IMG.NORMAL, CL.CYAN, sp, rd_h.toPlayer(bx,by), 3)
		et_l.rota_angle(-PI/4)
		et_l.size(100, 15)
		et_l.collision(true)
		et_l.noDelete(true)
		et_l.ringAt(bx, by, num, 0, IMG.NORMAL, CL.CYAN, sp, rd_h.toPlayer(bx,by), 4)
	end
	if(bTime==70)then
		setRose(sp,1)
	end
	if(bTime==210)then
		setRose(sp,2)
	end

	for l_num = 0 , LAZER_MAX do TransL(l_num,bTime) end
end

function setRose(speed,state)
	boss_SE(KIRAN)
	move_rand(FMIN_X + 100, 180, FMAX_X - FMIN_X - 100, 500, 80, 60)
	bx,by=Param2(Boss.getX()-50, Boss.getY()-100)
	petal_num=6
	for ite=0,petal_num do
		et_l.rota_angle(PI2/petal_num*ite)
		et_l.size(150, 30)
		et_l.collision(true)
		et_l.noDelete(true)
		et_l.standType(IMG.NORMAL)
		et_l.ringAt(bx,by, diff(5,8,12,0), 0, IMG.PETAL, CL.PINK, 4, rd_h.toPlayer(bx,by), state)
	end
end

function TransL(l_num)
	if (Lazer.isFlag(l_num)) then
		if(Lazer.getState1(l_num)==1)then Lazer.setLengthAngle(Lazer.getLengthAngle(l_num)+PI/128) end
		if(Lazer.getState1(l_num)==2)then Lazer.setLengthAngle(Lazer.getLengthAngle(l_num)-PI/128) end
		if(Lazer.getState1(l_num)==3)then 
			Lazer.setRota(10,40,-PI/4)
			Lazer.setRota(50,80,PI/4)
			if(Lazer.getCount(l_num)==90)then Lazer.setCount(10) end
		end
		if(Lazer.getState1(l_num)==4)then 
			Lazer.setRota(10,40,PI/4)
			Lazer.setRota(50,80,-PI/4)
			if(Lazer.getCount(l_num)==90)then Lazer.setCount(10) end
		end
	end
end
--@EndScript