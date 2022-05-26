dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.set(Time(56), HP(5500))
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
	if(bTime == 150)then
		et_lc.ring(diff(5,16,32,0), 200, 60, CL.GREEN, sp_(7,8,10,0), 0, 0)
	end
	for e_num = 0 , MINION_MAX do TransE(e_num) end
	for lc_num = 0 , T_LAZ_MAX do TransLc(lc_num) end
end

function MinionShot(e_num)
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
	en_spawn(Boss.getX(), Boss.getY(), TRAMP_ELEMIRA, 4000, 0, 0)
	en_item(Apple, 1)
	Minion.setAngle(-PI/2)
	Minion.setSpeed(4)
	Minion.setMotion(1)
end
function TransE(e_num)
	if(Minion.isFlag(e_num))then
		if(Minion.getType(e_num)==TRAMP_ELEMIRA and Minion.getCount(e_num)>70)then
			ex,ey=Param2(Minion.getX(e_num),Minion.getY(e_num))
			Minion.kill()
			boss_spawn(1,ex,ey,N03_EREMIRA,10000,LifeUP)
		end
		if(Minion.getType(e_num)==N03_EREMIRA and Minion.getCount(e_num)>100)then
			if(Minion.getY(e_num)<=Boss.getY())then 
				Minion.setMotion(1)
				Minion.setAngle(rd_h.fMinion_p(e_num))
				Minion.setSpeed(7)
				MinionShot(e_num)
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
function TransLc(lc_num)
	if(LazCr.isFlag(lc_num))then
		et_lc.rd_add(lc_num, 0, 30, PI/90, 0)
		et_lc.rd_add(lc_num, 30, 60, -PI/45, 0)
		et_lc.rd_add(lc_num, 60, 90, PI/45, 0)
	end
end

--@EndScript