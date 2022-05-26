dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.set(Time(48), HP(9000))
	Boss.Motion(0)
end

function BossShot()
	bTime = shot_time % 300

	if(bTime%120 == 0)then
		Boss.Motion(1)
		Boss.charge()
		move_rand(FMIN_X + 200, 200, FMAX_X - FMIN_X - 200, 500, 80, 60)
	end
	if(bTime%120 == 60)then Boss.Motion(0) end
	if(bTime%120==0)then boss_SE(BULLET01)
		bx,by=Param2(Boss.getX()+rand(200),Boss.getY()+rand(200))
		angle = rd_h.toPlayer(bx,by)+rand(PI/3)
		et_s.shine(true)
		et_s.size(0.8)
		et_s.ringAt(bx,by, 11, 0, IMG.MEGA, CL.RED, 4, angle, 1)
		et_s.shine(true)
		et_s.size(0.8)
		et_s.ringAt(bx,by, 11, 0, IMG.MEGA, CL.RED, 4, angle, 2)
		et_lc.ringAt(bx,by, 19, 0, 40, CL.ORANGE, 10, rd_h.Boss_Player(), 0)
		et_lc.ringAt(bx,by, 19, 0, 40, CL.ORANGE, 10, rd_h.Boss_Player(), 1)
	end

	for bl_num = 0 , SHOT_MAX do TransS(bl_num) end --ステータス変更
	for bl_num = 0 , T_LAZ_MAX do TransL(bl_num) end --ステータス変更
end

function TransS(bl_num)
	if (Shot.isFlag(bl_num)) then
		if(Shot.getState1(bl_num)==1)then Shot.addAngle(PI/2/250) end
		if(Shot.getState1(bl_num)==2)then Shot.addAngle(-PI/2/250) end
	end
end

function TransL(bl_num)
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