dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.set(Time(60), HP(9000))
	Boss.noDelMinion(true)
	boss_spawn(1,Boss.getX(), Boss.getY()+200,N01_MATUMI,99999999,LifeUP)
	Minion.setMove(Boss.getX(),300,60)
	Minion.setMotion(0)
end

function BossShot()
	bTime = shot_time % 240
	half_x=(FMAX_X - FMIN_X)/2

	if(bTime == 0)then
		Boss.Motion(0)
		Boss.charge()
		move_rand(FMIN_X + 100, 180, FMAX_X - FMIN_X - 100, 500, 40, 100)
	end

	if(bTime%240==0)then Minion.setMove(half_x+400,300,60) end
	if(bTime%240==119)then Minion.setMove(half_x-400,300,60) end

	per=diff(7,2,1,0)
	if(bTime>20 and bTime%per == 0)then boss_SE(BULLET01)
		speed=diff(3,5,7,0)
		et_s.nwayAt(Minion.getX(1), Minion.getY(1), 3, 2, 0, IMG.AMMO, CL.YELLOW, speed, 1, PI/12, PI/13*(shot_time/per), 0)
		Minion.setMotion(1)
	end

	if(bTime%80 == 10)then boss_SE(LAZER01)
		Boss.Motion(1)
		num=diff(3,4,5,0)
		rd_dist=diff(9,15,18,0)
		et_lc.nwayAt(Boss.getX()+100,Boss.getY()+100,70, num, 0, CL.BLUE, 10, PI/rd_dist, PI, 0)--曲がるレーザー
		et_lc.nwayAt(Boss.getX()-100,Boss.getY()+100,70, num, 0, CL.BLUE, 10, PI/rd_dist, 0, 1)--曲がるレーザー
	end
	if(bTime%80 == 40)then Boss.Motion(0) end

	for bl_num = 0 , T_LAZ_MAX do TransL(bl_num) end --ステータス変更
end

function TransL(bl_num)
	if (LazCr.isFlag(bl_num)) then
		et_lc.rd_add(bl_num, t0(0),	t1(150), (PI*5 / 6) / 90, 0)
		et_lc.rd_add(bl_num, t0(0),	t1(150), -(PI*5 / 6) / 90, 1)
		if(between(LazCr.getCount(bl_num),150,175))then
			angle =rd_h.toPlayer(LazCr.getX(bl_num),LazCr.getY(bl_num))
			LazCr.setAngle(angle)
		end
		if(between(LazCr.getCount(bl_num),200,220))then
			angle =rd_h.toPlayer(LazCr.getX(bl_num),LazCr.getY(bl_num))
			LazCr.setAngle(angle)
		end
	end
end

--@EndScript