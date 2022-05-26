dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(1)
	Boss.set(Time(32), HP(6000))
	Boss.noDelMinion(true)
end

function BossShot()
	bTime = shot_time % 280

	if(shot_time < 70)then Boss.setSerifBox(Boss.getX(),Boss.getY()-200,1,"えいっ！") end
	if(shot_time==0)then 
		boss_spawn(1,Boss.getX(), Boss.getY()+200,N01_MATUMI,6100,LifeUP) 
		Minion.setMotion(0)
	end
	if(shot_time>0)then Boss.setHP(Minion.getHP(1)-100) end
	if(bTime == 0)then 
		Boss.Motion(0) 
		Boss.charge()
	end
	if(bTime == 10)then boss_SE(LAZER01)
		Boss.Motion(1)
		num=diff(3,4,6,0)
		rd_dist=diff(9,15,18,0)
		et_lc.nwayAt(Boss.getX()+100,Boss.getY()+100,70, num, 0, CL.PINK, 10, PI/rd_dist, PI, 0)--曲がるレーザー
		et_lc.nwayAt(Boss.getX()-100,Boss.getY()+100,70, num, 0, CL.PINK, 10, PI/rd_dist, 0, 1)--曲がるレーザー
	end
	if(bTime == 100)then Boss.Motion(0) end
	if(shot_time > 1 and bTime % diff(12,9,6,0) == 0)then boss_SE(BULLET01)
		dist = diff(60, 70, 90,0)
		speed = diff(6,6,7,0) + rand(2)
		angle = rd_h.Boss_Player()
		Shot.Create(Minion.getX(1) + rand(dist), Minion.getY(1) + rand(dist), IMG.AMMO, CL.BLUE, speed, angle, 0)
		angle = rd_h.Boss_Player()+PI/3
		Shot.Create(Minion.getX(1) + rand(dist), Minion.getY(1) + rand(dist), IMG.AMMO, CL.BLUE, speed, angle, 0)
		angle = rd_h.Boss_Player()-PI/3
		Shot.Create(Minion.getX(1) + rand(dist), Minion.getY(1) + rand(dist), IMG.AMMO, CL.BLUE, speed, angle, 0)
		Minion.setMotion(1)
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