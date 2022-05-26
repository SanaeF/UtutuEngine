dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.setBomInvalid()
	Boss.set(Time(58), HP(15000))
end

function BossShot()
	bTime = shot_time % 600
	if(shot_time == 0)then
		move((FMAX_X - FMIN_X) / 2, (FMAX_Y - FMIN_Y) / 2, 40)
	end
	bx,by = Param2(Boss.getX()-15, Boss.getY()-160)
	if(bTime==50)then boss_SE(LAZER01)
		Boss.charge()
		Boss.Motion(1)
		et_lc.bound(true)
		et_lc.ringAt(bx, by,28, 0, 40, CL.PURPLE, 10, rd_h.Boss_Player(), 0)
		et_l.collision(true)
		et_l.size(400, 20)
		et_l.noDelete(true)
		et_l.nwayAt(Boss.getX(), Boss.getY()-600, 41, 1, 0, IMG.BIG, CL.BLUE, 0, 0, PI/36, PI/2, 0)
	end
	if(bTime == 110)then Boss.Motion(0) end
	if(bTime==250)then boss_SE(LAZER01)
		Boss.charge()
		Boss.Motion(1)
		et_lc.bound(true)
		et_lc.ringAt(bx, by,28, 0, 40, CL.PURPLE, 10, rd_h.Boss_Player(), 1)
	end
	if(bTime==450)then boss_SE(LAZER01)
		Boss.charge()
		Boss.Motion(0)
		crush(10,30)
		et_lc.ring(28, 0, 40, CL.ORANGE, 10, rd_h.Boss_Player(), 0)
		et_lc.ring(28, 0, 40, CL.ORANGE, 10, rd_h.Boss_Player(), 1)
	end

	for l_num = 0 , LAZER_MAX do TransL(l_num,bTime) end
	for bl_num = 0 , T_LAZ_MAX do TransLc(bl_num) end --ステータス変更
end

function TransL(l_num,bTime)
	if (Lazer.isFlag(l_num)) then
		if(bTime<430)then 
			Lazer.setLengthAngle(rd_h.toPlayer(Lazer.getX(l_num),Lazer.getY(l_num))-PI/2)
		end
		if(between(bTime,450,500))then Lazer.addLength(20) end
		if(between(bTime,500,550))then Lazer.addLength(-20) end
		if(bTime==580)then Lazer.clear() end
	end
end
function TransLc(bl_num)
	if (LazCr.isFlag(bl_num)) then
		if(LazCr.getBoundCount(bl_num)>0)then LazCr.isNotBound() end
		et_lc.rd_add(bl_num, t0(0), t1(30), PI/2/60, 0)
		et_lc.rd_add(bl_num, t0(0), t1(30), -PI/2/60, 1)
		et_lc.rd_add(bl_num, t0(30), t1(160), -PI/2/70, 0)
		et_lc.rd_add(bl_num, t0(30), t1(160), PI/2/70, 1)
	end
end

--@EndScript