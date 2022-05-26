dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.setLast()
	Boss.set(Time(60), HP(5500))
end

function BossShot()
	bTime = shot_time % 250

	if(bTime%50 == 10)then InitTramp(-PI/2+PI/6*(bTime/20)) end
	if(bTime == 60)then
		et_lc.ring(diff(6,16,27,0), 200, 60, CL.PINK, sp_(7,8,10,0), 0, 0)
		et_lc.ring(diff(6,16,27,0), 200, 60, CL.PINK, sp_(7,8,10,0), 0, 1)
	end
	if((bTime<60 or bTime>100) and bTime % diff(31,25,25,0)  == 0)then boss_SE(BULLET02)
		if(shot_time > 100)then
			et_s.ring(diff(13,18,23,0), 0, IMG.TRAMP , CL.CYAN, sp_(4,5,7,0), rand(PI/3), 1)
		end
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

function InitTramp(angle)
	if(Minion.searchID()>5)then return end
	Boss.Motion(1)
	boss_SE(GYUUUUUUN)
	en_spawn(Boss.getX(), Boss.getY(), TRAMP_ELEMIRA, 4000, 0, 0)
	en_item(Apple, 1)
	Minion.setAngle(angle)
	Minion.setSpeed(4)
	Minion.setMotion(1)
end
function TransE(e_num)
	if(Minion.isFlag(e_num))then
		if(Minion.getType(e_num)==TRAMP_ELEMIRA and Minion.getCount(e_num)>70)then
			ex,ey=Param2(Minion.getX(e_num),Minion.getY(e_num))
			Minion.kill()
			boss_spawn(Minion.searchID(),ex,ey,N03_EREMIRA,10000,BomPeace)
			Minion.setNoUI(true)
		end
		if(Minion.getType(e_num)==N03_EREMIRA and Minion.getCount(e_num)==100)then
			Minion.setMotion(1)
			Minion.setAngle(rd_h.fMinion_p(e_num))
			Minion.setSpeed(7)
			MinionShot(e_num)
		end
	end
end
function TransLc(lc_num)
	if(LazCr.isFlag(lc_num))then
		et_lc.rd_add(lc_num, 0, 30, PI/90, 0)
		et_lc.rd_add(lc_num, 30, 60, -PI/45, 0)
		et_lc.rd_add(lc_num, 60, 90, PI/45, 0)

		et_lc.rd_add(lc_num, 0, 30, -PI/90, 1)
		et_lc.rd_add(lc_num, 30, 60, PI/45, 1)
		et_lc.rd_add(lc_num, 60, 90, -PI/45, 1)
	end
end

--@EndScript