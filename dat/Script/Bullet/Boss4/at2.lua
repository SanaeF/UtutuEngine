dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.set(Time(60), HP(9000))
end

function BossShot()
	bTime = shot_time % (280)
	if(bTime%90 == 0)then
		move_rand(FMIN_X + 100, 180, FMAX_X - FMIN_X - 100, 500, 80, 80)
	end
	if(bTime==1)then boss_SE(BULLET01)
		Boss.charge()
		Boss.Motion(1)
		way=diff(3,5,7,0)
		et_l.bound(true)
		et_l.noBoundAngle(true)
		et_l.size(80, 25)
		et_l.standType(IMG.BIG)
		et_l.nway(way, 1, 0, IMG.MEGA, CL.PINK, 7, 0, PI/diff(4,6,7,0), rd_h.Boss_Player(), 1)
	end

	if(bTime == 100)then boss_SE(LAZER01)
		Boss.Motion(0)
		num=diff(3,4,5,0)
		rd_dist=diff(9,15,18,0)
		angle = rd_h.toPlayer(Boss.getX(),Boss.getY()-170)
		et_lc.nwayAt(Boss.getX(),Boss.getY()-170,70, num, 0, CL.ORANGE, 10, PI/rd_dist, angle-PI/2, 0)--曲がるレーザー
		angle = rd_h.toPlayer(Boss.getX()-100,Boss.getY()-170)
		et_lc.nwayAt(Boss.getX()-100,Boss.getY()-170,70, num, 0, CL.ORANGE, 10, PI/rd_dist, angle+PI/2, 1)--曲がるレーザー
	end

	for l_num = 0 , LAZER_MAX do TransL(l_num,bTime) end
	for bl_num = 0 , T_LAZ_MAX do TransLc(bl_num) end --ステータス変更
end

function TransL(bl_num,bTime)
	if(Lazer.isFlag(bl_num))then
		if(Lazer.getBoundCount(bl_num)>0)then
			Lazer.setSpeed(0)
			Lazer.isNotBound()
			Lazer.setState1(2)
		end
		if(bTime==0)then Lazer.clear() end
		if(Lazer.getState1(bl_num)==2)then 
			per=diff(24,17,24,0)
			speed=diff(4,6,8,0)+rand(1)
			if(bTime%per==0)then
				Shot.Create(Lazer.getX(bl_num), Lazer.getY(bl_num), IMG.MEGA, CL.PINK, speed, Lazer.getAngle(bl_num)+PI+rand(PI/4), 0)
				Shot.isShine()
			end
		end
	end
end

function TransLc(bl_num)
	if (LazCr.isFlag(bl_num)) then
		et_lc.rd_add(bl_num, t0(0),	t1(100), PI/2/60, 0)
		et_lc.rd_add(bl_num, t0(0),	t1(100), -PI/2/60, 1)
	end
end

--@EndScript