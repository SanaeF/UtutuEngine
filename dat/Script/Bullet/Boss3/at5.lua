dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.set(Time(46), HP(9500))
end

function BossShot()
	bTime = shot_time % 300

	if(shot_time < 70)then Boss.setSerifBox(Boss.getX(),Boss.getY()-250,1,"ŠoŒå‚µ‚È‚³‚¢I") end
	if(shot_time == 1)then
		Boss.Motion(0)
		move((FMAX_X - FMIN_X) / 2, (FMAX_Y - FMIN_Y) / 3, 40)
	end
	if(bTime==10 or bTime==160)then boss_SE(BULLET02)
		et_s.shine(true)
		et_s.ring(diff(5,7,14,0), 0, IMG.BIG, CL.ORANGE, sp_(3,4,7,0), rd_h.Boss_Player(), 0)
	end
	if(bTime<100 and bTime%80 == 50)then boss_SE(GYUUUUUUN)
		Boss.Motion(1)
		et_lc.bound(true)
		et_lc.ring(diff(7,14,24,0), 0, 50, CL.YELLOW, 9, rd_h.Boss_Player(), 1)
	end
	if(between(bTime,150,250) and bTime%80 == 50)then boss_SE(GYUUUUUUN)
		et_lc.bound(true)
		et_lc.ring(diff(7,14,24,0), 0, 50, CL.GREEN, 9, rd_h.Boss_Player(), 2)
	end
	for lc_num = 0 , T_LAZ_MAX do TransLc(lc_num) end
end

function TransLc(lc_num)
	if(LazCr.isFlag(lc_num))then
		et_lc.rd_add(lc_num, 0, 100, PI/2/70, 1)
		et_lc.rd_add(lc_num, 100, 200, -PI/2/70, 1)

		et_lc.rd_add(lc_num, 0, 100, -PI/2/70, 2)
		et_lc.rd_add(lc_num, 100, 200, PI/2/70, 2)
		if(LazCr.getState1(lc_num)==1)then
			if(LazCr.getCount(lc_num)%18==8)then LazCr.addAngle(PI/2) end
			if(LazCr.getCount(lc_num)%18==17)then LazCr.addAngle(-PI/2) end
		end
		if(LazCr.getState1(lc_num)==2)then
			if(LazCr.getCount(lc_num)%18==8)then LazCr.addAngle(PI/2) end
			if(LazCr.getCount(lc_num)%18==17)then LazCr.addAngle(-PI/2) end
		end
		if not(LazCr.getState1(lc_num)==0)then
			if(LazCr.getBoundCount(lc_num) == 1)then 
				LazCr.setAngle(rd_h.toPlayer(LazCr.getX(lc_num),LazCr.getY(lc_num)))
				LazCr.setState1(0)
			end
		end
		if(LazCr.getBoundCount(lc_num)==2)then 
			LazCr.isNotBound() 
		end
		if(LazCr.getBoundArea(lc_num)==3)then 
			LazCr.isNotBound() 
			LazCr.setAngle(-PI/2)
		end
		if(LazCr.getBoundArea(lc_num)==4)then 
			LazCr.isNotBound() 
			LazCr.setAngle(PI/2)
		end
		if(LazCr.getY(lc_num)>800)then 
			LazCr.isNotBound() 
		end
	end
end

--@EndScript