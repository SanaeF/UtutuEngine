dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.noDamage(false)
	Boss.setBomInvalid()
	Boss.setMainBullet()
	Boss.set(Time(9999), HP(35000))
	Boss.Motion(0)
end

function BossShot()
	bTime = shot_time % 360
	if(shot_time==20)then Boss.Motion(1) end
	if(shot_time<20)then return end

	if(bTime%30==0)then boss_SE(BULLET01)
		bx,by=Param2(Boss.getX()+rand(200),Boss.getY()+rand(200))
		angle = rd_h.toPlayer(bx,by)+rand(PI/3)
		et_s.size(0.5)
		et_s.ringAt(bx,by, 11, 50, IMG.POIFUL, CL.RED, 6, angle, 1)
	end

	if(Boss.getHP()<30000)then
		if(bTime%120==100)then boss_SE(KIRAN)
		et_s.rota(true)
		et_s.ring(25, 0, IMG.PETAL, CL.CYAN, 7, rd_h.Boss_Player(), 1)
		et_s.rota(true)
		et_s.size(1.5)
		et_s.ring(25, 0, IMG.PETAL, CL.PURPLE, 8, rd_h.Boss_Player(), 1)
		end
	end
	if(Boss.getHP()<24000)then
		if(bTime%120==0)then boss_SE(LAZER01)
			bx,by=Param2(Boss.getX()-15, Boss.getY()-160)
			angle = rd_h.toPlayer(bx,by)+rand(PI/3)
			et_lc.ringAt(bx,by, 19, 0, 40, CL.PINK, 10, angle, 0)
			et_lc.ringAt(bx,by, 19, 0, 40, CL.PINK, 10, angle, 1)
		end
	end
	if(Boss.getHP()<18000)then
		if(bTime==0)then boss_SE(BULLET01)
			bx,by=Param2(Boss.getX()-15, Boss.getY()-160)
			angle = rd_h.toPlayer(bx,by)
			et_s.shine(true)
			et_s.size(0.8)
			et_s.ringAt(bx,by, 11, 0, IMG.MEGA, CL.PINK, 4, angle, 2)
			et_s.shine(true)
			et_s.size(0.8)
			et_s.ringAt(bx,by, 11, 0, IMG.MEGA, CL.PINK, 4, angle, 3)
		end
	end
	if(Boss.getHP()<12000)then
		if(bTime==180)then boss_SE(BULLET01)
			bx,by=Param2(Boss.getX()-15, Boss.getY()-160)
			angle = rd_h.toPlayer(bx,by)
			et_s.shine(true)
			et_s.size(0.8)
			et_s.ringAt(bx,by, 11, 0, IMG.MEGA, CL.PINK, 4, angle, 2)
			et_s.shine(true)
			et_s.size(0.8)
			et_s.ringAt(bx,by, 11, 0, IMG.MEGA, CL.PINK, 4, angle, 3)
		end
	end
	if(Boss.getHP()<7000)then
		if(bTime==90 or bTime==270)then boss_SE(BULLET01)
			bx,by=Param2(Boss.getX()-15, Boss.getY()-160)
			angle = rd_h.toPlayer(bx,by)
			et_s.shine(true)
			et_s.size(0.9)
			et_s.ringAt(bx,by, 11, 0, IMG.MEGA, CL.GREEN, 6, angle, 4)
		end
	end
	for bl_num = 0 , SHOT_MAX do TransS(bl_num) end --?X?e?[?^?X???X
	for bl_num = 0 , T_LAZ_MAX do TransLc(bl_num) end --?X?e?[?^?X???X
end

function TransS(bl_num)
	if (Shot.isFlag(bl_num)) then
		if(Shot.getState1(bl_num)==1)then
			if(Shot.getCount(bl_num)<120)then
				Shot.setSize(Shot.getSize(bl_num)+0.004)
			end
		end
		if(Shot.getState1(bl_num)==2)then Shot.addAngle(PI/2/250) end
		if(Shot.getState1(bl_num)==3)then Shot.addAngle(-PI/2/250) end
	end
end

function TransLc(bl_num)
	if (LazCr.isFlag(bl_num)) then
		et_lc.rd_add(bl_num, t0(0), t1(30), PI/2/60, 0)
		et_lc.rd_add(bl_num, t0(0), t1(30), -PI/2/60, 1)
		if(LazCr.getCount(bl_num)==30)then LazCr.setSpeed(0) end
		if(LazCr.getCount(bl_num)==90)then LazCr.setSpeed(9) end
		et_lc.rd_add(bl_num, t0(90), t1(160), -PI/2/70, 0)
		et_lc.rd_add(bl_num, t0(90), t1(160), PI/2/70, 1)
	end
end

--@EndScript