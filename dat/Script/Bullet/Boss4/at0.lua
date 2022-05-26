dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.set(Time(60), HP(9000))
	Boss.noDelMinion(true)
	if not(Minion.getBoss(1) and Minion.isFlag(1))then boss_spawn(1,Boss.getX(), Boss.getY()+200,N01_MATUMI,5000,LifeUP) end
	Minion.setMove(Boss.getX(), Boss.getY()+200,60)
	Minion.setMotion(0)
end

function BossShot()
	bTime = shot_time % 240
	half_x=(FMAX_X - FMIN_X)/2

	if(Minion.getHP(1)<=5000)then LifeMatumi(bTime) end--マツミが生きているときの処理
	if(Minion.getHP(1)<100)then LostMatumi() end

	if(bTime == 0)then
		Boss.Motion(0)
		Boss.charge()
	end

	if(bTime%120 == 10)then boss_SE(LAZER01)
		Boss.Motion(1)
		num=diff(3,4,5,0)
		rd_dist=diff(9,15,18,0)
		angle = rd_h.toPlayer(Boss.getX(),Boss.getY()-170)
		et_lc.nwayAt(Boss.getX(),Boss.getY()-170,70, num, 0, CL.BLUE, 10, PI/rd_dist, angle-PI/2, 0)--曲がるレーザー
		angle = rd_h.toPlayer(Boss.getX()-100,Boss.getY()-170)
		et_lc.nwayAt(Boss.getX()-100,Boss.getY()-170,70, num, 0, CL.BLUE, 10, PI/rd_dist, angle+PI/2, 1)--曲がるレーザー
	end
	if(Minion.getHP(1)>5000)then
		if(bTime%diff(85,70,60,0) == 10)then boss_SE(BULLET01)
			num=diff(10,17,25,0)
			et_s.ring(num, 0, IMG.BIG, CL.RED, sp_(5,6,9,0), rd_h.Boss_Player(), 0)
		end
	end
	for bl_num = 0 , T_LAZ_MAX do TransL(bl_num) end --ステータス変更
end
function LifeMatumi(bTime)
	Minion.isFlag(1)
	Minion.setLastHP(Minion.getHP(1)-4)
	if(shot_time>1)then Boss.setHP(Minion.getHP(1)+4000) end
	if(bTime%240==0)then Minion.setMove(half_x+400,Boss.getY()+200,60) end
	if(bTime%240==119)then Minion.setMove(half_x-400,Boss.getY()+200,60) end

	per=diff(7,2,1,0)
	if(shot_time > 1 and bTime % diff(9,6,4,0) == 0)then boss_SE(BULLET01)
		dist = diff(60, 70, 90,0)
		speed = diff(6,6,7,0) + rand(2)
		angle = rd_h.toPlayer(Minion.getX(1),Minion.getY(1))
		Shot.Create(Minion.getX(1) + rand(dist), Minion.getY(1) + rand(dist), IMG.AMMO, CL.BLUE, speed, angle, 0)
		Minion.setMotion(1)
	end
	if(bTime%80 == 40)then Boss.Motion(0) end
end
function LostMatumi()
	Boss.setSerifBox(Boss.getX(),Boss.getY()-200,120,"マツミっ！！")
	boss_spawn(1,Minion.getX(1), Minion.getY(1),N01_MATUMI,99999999,LifeUP) 
	Minion.setNoUI(true)
	Minion.setMove(100,100,180)
	Minion.setMotion(0)
end
function TransL(bl_num)
	if (LazCr.isFlag(bl_num)) then
		et_lc.rd_add(bl_num, t0(0),	t1(100), PI/2/60, 0)
		et_lc.rd_add(bl_num, t0(0),	t1(100), -PI/2/60, 1)
	end
end
--@EndScript