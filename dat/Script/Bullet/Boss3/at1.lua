dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(3)
	Boss.setMainBullet()
	Boss.set(Time(58), HP(8000))
end

function BossShot()
	bTime = shot_time % 600

	if(shot_time < 70)then Boss.setSerifBox(Boss.getX(),Boss.getY()-250,1,"?V?????a!") end
	if(shot_time == 1)then
		Boss.Motion(0)
		LazCr.Create(Boss.getX(), Boss.getY()-500, 60, CL.GREEN, 16, PI/2, -1)
		move((FMAX_X - FMIN_X) / 2, (FMAX_Y - FMIN_Y) / 2, 40)
	end
	if(shot_time>10 and bTime==1)then 
		Boss.Motion(0)
		LazCr.Create(Boss.getX(), Boss.getY()-700, 60, CL.GREEN, 16, PI/2, -1) 
	end
	if(bTime<200 and bTime%80 == 50)then boss_SE(GYUUUUUUN)
		Boss.Motion(1)
		et_lc.ring(diff(15,20,25,0), 0, 50, CL.YELLOW, 8, PI/45*(bTime/60), 1)
	end
	if(between(bTime,250,450) and bTime%80 == 50)then boss_SE(GYUUUUUUN)
		et_lc.ring(diff(15,20,25,0), 0, 50, CL.GREEN, 8, PI/45*(bTime/60), 2)
	end
	for lc_num = 0 , T_LAZ_MAX do TransLc(lc_num) end
end

function TransLc(lc_num)
	if(LazCr.isFlag(lc_num))then
		if(LazCr.getState1(lc_num)==-1)then
			if(LazCr.getCount(lc_num)>=42)then LazCr.setSpeed(0) end
			if(LazCr.getCount(lc_num)>=70)then LazCr.clear() end
		end
		if(LazCr.getState1(lc_num)==1)then
			if(LazCr.getCount(lc_num)%20==9)then LazCr.addAngle(PI/2) end
			if(LazCr.getCount(lc_num)%20==19)then LazCr.addAngle(-PI/2) end
		end
		if(LazCr.getState1(lc_num)==2)then
			if(LazCr.getCount(lc_num)%20==9)then LazCr.addAngle(-PI/2) end
			if(LazCr.getCount(lc_num)%20==19)then LazCr.addAngle(PI/2) end
		end
	end
end

--@EndScript