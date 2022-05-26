dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.set(Time(60), HP(6000))
	Boss.noDelMinion(true)
	Minion.isFlag(1)
	half_x=(FMAX_X - FMIN_X)/2
	Minion.setMove(half_x,200,60)
end

function BossShot()
	bTime = shot_time % 300

	if(shot_time > 1 and bTime % diff(12,7,6,0) == 0)then boss_SE(BULLET01)
		dist = 560
		speed = diff(6,8,9,0) + rand(2)
		angle = rd_h.Boss_Player()+rand(PI/15)
		for ite = 0 , 3 do
			Shot.Create(Minion.getX(1) + rand(560), Minion.getY(100) + rand(dist), IMG.AMMO, CL.ORANGE, speed, angle, 0)
		end
		Minion.setMotion(1)
	end
	if(bTime == 0)then
		Boss.Motion(0)
		Boss.charge()
		move_rand(FMIN_X + 100, 180, FMAX_X - FMIN_X - 100, 500, 70, 100)
		Minion.isFlag(1)
		Minion.setMove(Boss.getX()-60,Boss.getY()-200,60)
	end
	if(bTime == 10)then boss_SE(LAZER01)
		Boss.Motion(1)
		num=diff(3,4,6,0)
		rd_dist=diff(7,10,13,0)
		et_lc.nwayAt(Boss.getX()+100,Boss.getY()+100,70, num, 0, CL.CYAN, 10, PI/rd_dist, PI, 0)--曲がるレーザー
		et_lc.nwayAt(Boss.getX()-100,Boss.getY()+100,70, num, 0, CL.CYAN, 10, PI/rd_dist, 0, 1)--曲がるレーザー
	end
	if(bTime == 100)then 
		Boss.Motion(0) 
		num=diff(3,4,6,0)
		rd_dist=diff(5,7,10,0)
		et_lc.nwayAt(Boss.getX(),Boss.getY(),70, num, 0, CL.CYAN, 10, PI/rd_dist, rd_h.Boss_Player(), 2)--曲がるレーザー
	end

	for bl_num = 0 , T_LAZ_MAX do TransL(bl_num) end --ステータス変更
end

function TransL(bl_num)
	if (LazCr.isFlag(bl_num)) then
		et_lc.rd_add(bl_num, t0(0),	t1(150), (PI*5 / 6) / 90, 0)
		et_lc.rd_add(bl_num, t0(0),	t1(150), -(PI*5 / 6) / 90, 1)
		et_lc.rd_add(bl_num, t0(150), t1(300), PI/3 / 100, 0)
		et_lc.rd_add(bl_num, t0(150), t1(300), -PI/3 / 100, 1)
	end
end

--@EndScript