dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.set(Time(60), HP(7500))
end

function BossShot()
	bTime = shot_time % 250

	if(shot_time == 1)then
		InitTramp()
	end
	if(bTime == 50)then
		Boss.Motion(0)
		Boss.charge()
		move_rand(FMIN_X + 100, 300, FMAX_X - FMIN_X - 100, 500, 100, 100)
	end
	if(between(bTime, 10, 100) and bTime % diff(31,25,18,0)  == 0)then boss_SE(BULLET02)
		if(shot_time > 100)then
			et_s.size(0.5)
			et_s.ring(diff(17,21,30,0), 0, IMG.TRAMP , CL.CYAN, sp_(4,5,7,0), rand(PI/3), 1)
		end
	end
	for e_num = 0 , MINION_MAX do TransE(e_num) end
	for bl_num = 0 , SHOT_MAX do TransS(bl_num) end 
	for lc_num = 0 , T_LAZ_MAX do TransLc(lc_num) end
end
function MatsumiShot(e_num)
	time=Minion.getCount(e_num)
	if(time%diff(45,25,17,0)==0)then
		ex,ey=Param2(Minion.getX(e_num),Minion.getY(e_num))
		et_s.size(0.5)
		et_s.nwayAt(ex,ey,3,3,0,IMG.AMMO,CL.BLUE,sp_(4,6,10,0),1,PI/3, rd_h.fMinion_p(e_num),1)
	end
end
function EremiraShot(e_num)
	ex,ey=Param2(Minion.getX(e_num),Minion.getY(e_num))
	Lazer.Create(ex,ey, IMG.CLOCK_LAZ, CL.YELLOW, Minion.getSpeed(e_num), Minion.getAngle(e_num), 0)
	Lazer.setType(IMG.NORMAL)
	Lazer.setThick(25)
	Lazer.setLength(250)
	Lazer.isCollision()
end

function InitTramp()
	Boss.Motion(1)
	boss_SE(GYUUUUUUN)
	en_spawn(Boss.getX(), Boss.getY(), TRAMP_MATSU, 4000, 0, 0)
	en_item(Apple, 1)
	Minion.setAngle(-PI/2-PI/3)
	Minion.setSpeed(4)
	en_spawn(Boss.getX(), Boss.getY(), TRAMP_ELEMIRA, 4000, 0, 0)
	en_item(Apple, 1)
	Minion.setAngle(-PI/2+PI/3)
	Minion.setSpeed(4)
	Minion.setMotion(1)
end

function TransE(e_num)
	if(Minion.isFlag(e_num))then
		if(Minion.getType(e_num)==TRAMP_MATSU and Minion.getCount(e_num)>70)then
			ex,ey=Param2(Minion.getX(e_num),Minion.getY(e_num))
			Minion.kill()
			boss_spawn(2,ex,ey,N03_MATUMI,2000,LifeUP)
			Minion.setNoUI(true)
		end
		if(Minion.getType(e_num)==TRAMP_ELEMIRA and Minion.getCount(e_num)>70)then
			ex,ey=Param2(Minion.getX(e_num),Minion.getY(e_num))
			Minion.kill()
			boss_spawn(3,ex,ey,N03_EREMIRA,5000,LifeUP)
			Minion.setNoUI(true)
		end
		if(Minion.getType(e_num)==N03_MATUMI and Minion.getCount(e_num)>100)then
			if(Minion.getCount(e_num)%80==0)then 
				Minion.setAngle(rd_h.fMinion_b(e_num))
				Minion.setSpeed(4)
			end
			MatsumiShot(e_num)
		end
		if(Minion.getType(e_num)==N03_EREMIRA and Minion.getCount(e_num)>100)then
			if(Minion.getY(e_num)<=Boss.getY())then 
				Minion.setMotion(1)
				Minion.setAngle(rd_h.fMinion_p(e_num))
				Minion.setSpeed(7)
				EremiraShot(e_num)
			end
			if(Minion.getY(e_num)>Player.getY())then 
				Minion.setMotion(0)
				Minion.setAngle(-PI/2)
				Minion.setSpeed(10)
			end
			if not(between(Minion.getX(e_num),80,FMAX_X-FMIN_X-80))then 
				Minion.setAngle(rd_h.fMinion_b(e_num))
				Minion.setSpeed(10)
			end
		end
	end
end
function TransS(bl_num)
	if(Shot.isFlag(bl_num))then
		if(Shot.getState1(bl_num)==1 and Shot.getSize(bl_num)<=1.7)then
			Shot.setSize(Shot.getSize(bl_num)+0.04)
		end
	end
end
function TransLc(lc_num)
	if(LazCr.isFlag(lc_num))then
		et_lc.rd_add(lc_num, 0, 30, PI/90, 0)
		et_lc.rd_add(lc_num, 30, 60, -PI/45, 0)
		et_lc.rd_add(lc_num, 60, 90, PI/45, 0)
	end
end


--@EndScript