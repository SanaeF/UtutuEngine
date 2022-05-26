dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.setBomInvalid()
	Boss.set(Time(60), HP(8000))
	Boss.Motion(0)
end

function BossShot()
	bTime = shot_time % 360

	if(bTime%15==0)then boss_SE(KIRAN)
		et_s.bound(true)
		et_s.rota(true)
		et_s.shine(true)
		et_s.nway(5, 1, 0, IMG.MINI_STAR, CL.YELLOW, 7+rand(2), 0, PI/6, -PI/2+rand(PI/6), 0)
	end
	if(bTime==0)then Boss.charge() end
	if(bTime==10)then boss_SE(BOOOOM)
		Boss.Motion(1)
		Lazer.Create(Boss.getX()-15, Boss.getY()-160, IMG.LAZER, CL.PINK, 0, PI/2+PI/3, 1)
		Lazer.setType(IMG.BIG)
		Lazer.isNotCollision()
		Lazer.setLength(2000)
		Lazer.setThick(1)
		Lazer.isNoDelete()
	end
	if(bTime==90)then
		Boss.Motion(0)
		crush(10,30)
		for ite = 0 , 9 do boss_SE(EXPLODE)
			et_s.shine(true)
			et_s.ringAt(F_HALF_X+rand(F_HALF_X), F_MAX_Y, 5, 50, IMG.BIG, CL.ORANGE, 4, -PI/2+rand(PI/7), 0)
			et_s.shine(true)
			et_s.ringAt(F_HALF_X+rand(F_HALF_X), F_MAX_Y, 7, 50, IMG.DAST, CL.YELLOW, 4, -PI/2+rand(PI/7), 0)
		end
	end
	if(bTime==180)then Boss.charge() end
	if(bTime==190)then boss_SE(BOOOOM)
		Boss.Motion(1)
		Lazer.Create(Boss.getX()-15, Boss.getY()-160, IMG.LAZER, CL.PINK, 0, PI/2-PI/3, 2)
		Lazer.setType(IMG.BIG)
		Lazer.isNotCollision()
		Lazer.setLength(2000)
		Lazer.setThick(1)
		Lazer.isNoDelete()
	end
	if(bTime==270)then
		Boss.Motion(0)
		crush(10,30)
		for ite = 0 , 9 do boss_SE(EXPLODE)
			et_s.shine(true)
			et_s.ringAt(F_HALF_X+rand(F_HALF_X), F_MAX_Y, 5, 50, IMG.BIG, CL.ORANGE, 4, -PI/2+rand(PI/7), 0)
			et_s.shine(true)
			et_s.ringAt(F_HALF_X+rand(F_HALF_X), F_MAX_Y, 7, 50, IMG.DAST, CL.YELLOW, 4, -PI/2+rand(PI/7), 0)
		end
	end

	for bl_num = 0 , SHOT_MAX do TransS(bl_num) end --ステータス変更
	for l_num = 0 , LAZER_MAX do TransL(l_num,bTime) end
end

function TransS(bl_num)
	if (Shot.isFlag(bl_num)) then
		if(Shot.getBoundCount(bl_num)>=1)then
			Shot.setBoundCount(0)
			Shot.isNotBound()
		end
	end
end
function TransL(l_num,bTime)
	if (Lazer.isFlag(l_num)) then
		if(Lazer.getState1(l_num)==1)then 
			Lazer.setRota(0,60,-PI/2) 
		end
		if(Lazer.getState1(l_num)==2)then 
			Lazer.setRota(0,60,PI/2) 
		end
		if(between(Lazer.getCount(l_num),0,15))then Lazer.addThick(1) end
		if(between(Lazer.getCount(l_num),45,60))then Lazer.addThick(-1) end
		if(Lazer.getCount(l_num)==60)then Lazer.clear() end
	end
end

--@EndScript