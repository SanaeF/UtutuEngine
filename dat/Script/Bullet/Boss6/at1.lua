dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.set(Time(60), HP(12000))
	move((FMAX_X - FMIN_X) / 2, (FMAX_Y - FMIN_Y) / 2, 40)
end

function BossShot()
	bTime = shot_time % 1000
	if(shot_time<40)then return end
	per=1
	if(bTime==0)then Boss.charge() end
	if(bTime<500 and bTime%per==0)then boss_SE(BULLET02)
		angle=PI/2 + PI/53*(bTime/per)
		dist=bTime*2
		sx,sy=Param2(x_dt(Boss.getX(), angle, dist),y_dt(Boss.getY(), angle, dist))
		Shot.Create(sx,sy,IMG.POIFUL,CL.BLUE,0,rd_h.toBoss(sx,sy)+PI/57*(bTime/per)+rand(PI/57),0)
		Shot.setSize(0.4)
		angle=PI/2 - PI/53*(bTime/per)
		sx,sy=Param2(x_dt(Boss.getX(), angle, dist),y_dt(Boss.getY(), angle, dist))
		Shot.Create(sx,sy,IMG.POIFUL,CL.BLUE,0,rd_h.toBoss(sx,sy)-PI/57*(bTime/per)+rand(PI/57),0)
		Shot.setSize(0.4)
	end

	for bl_num = 0 , SHOT_MAX do TransS(bl_num,bTime) end 
end

function TransS(bl_num,bTime)
	if (Shot.isFlag(bl_num))then
		if(bTime==500)then boss_SE(KIRAN)
			Shot.setColor(CL.RED)
			Shot.setSpeed(2) 
		end
	end
end

--@EndScript