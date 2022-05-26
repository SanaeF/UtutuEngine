dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.noDelMinion(true)
	Boss.set(Time(60), HP(7000))
end

function BossShot()
	bTime = shot_time % 600
	if(bTime%100 == 20)then
		move_rand(FMIN_X + 100, 180, FMAX_X - FMIN_X - 100, 500, 80, 100)
	end
	num=diff(12,18,32,0)
	if(bTime==0)then boss_SE(LAZER01)
		Boss.charge()
		Boss.Motion(1)
		et_lc.ring(num, 0, 40, CL.PURPLE, 10, rd_h.Boss_Player(), 0)
	end
	if(bTime==200)then boss_SE(LAZER01)
		Boss.charge()
		Boss.Motion(1)
		et_lc.ring(num, 0, 40, CL.PURPLE, 10, rd_h.Boss_Player(), 1)
	end
	if(bTime==400)then boss_SE(LAZER01)
		Boss.charge()
		Boss.Motion(1)
		et_lc.ring(num, 0, 40, CL.PURPLE, 10, rd_h.Boss_Player(), 0)
		et_lc.ring(num, 0, 40, CL.PURPLE, 10, rd_h.Boss_Player(), 1)
	end

	if(bTime%200==50)then boss_SE(BULLET01)
		Boss.Motion(0)
		num=diff(5,7,9,0)
		et_s.shine(true)
		et_s.ring(num, 0, IMG.MEGA, CL.PURPLE, 8, rd_h.Boss_Player(), 1)
	end

	for bl_num = 0 , T_LAZ_MAX do TransL(bl_num) end --ステータス変更
	for bl_num = 0 , SHOT_MAX do TransS(bl_num) end --ステータス変更
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

function TransS(bl_num)
	if (Shot.isFlag(bl_num)) then
		if(Shot.getState1(bl_num)==1)then
			if(between(Shot.getCount(bl_num),60,80))then Shot.setAngle(rd_h.fShot_p(bl_num)) end
		end
	end
end

--@EndScript