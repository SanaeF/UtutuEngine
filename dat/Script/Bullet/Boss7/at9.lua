dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.noDamage(true)
	Boss.set(Time(60), HP(99999999))
	move((FMAX_X - FMIN_X) / 2, (FMAX_Y - FMIN_Y) / 2, 40)
	Boss.Motion(1)
end

function BossShot()
	bTime = shot_time % 1500
	if(bTime==20)then boss_SE(LAZER01)
		angle=rand(PI/5)
		et_l.collision(false)
		et_l.size(800, 12)
		et_l.noDelete(true)
		et_l.ring(7, 0, IMG.PETAL, CL.RED, 0, angle, 1)
		et_l.size(300, 1)
		et_l.noDelete(true)
		et_l.ring(11, 0, IMG.PETAL, CL.PINK, 0, angle+PI/5, 2)
	end
	if(bTime==760)then boss_SE(LAZER01)
		et_l.collision(false)
		et_l.size(800, 12)
		et_l.noDelete(true)
		et_l.ring(7, 0, IMG.MEGA, CL.BLUE, 0, rand(PI/5), 2)
		et_l.size(300, 1)
		et_l.noDelete(true)
		et_l.ring(11, 0, IMG.MEGA, CL.CYAN, 0, angle+PI/5, 1)
	end
	if(shot_time>20 and bTime%100==0)then boss_SE(BULLET01)
		et_s.ringAt(Boss.getX()-15, Boss.getY()-160,13, 0, IMG.NORMAL, CL.BLUE, 5, rd_h.toPlayer(Boss.getX()-15, Boss.getY()-160), 1)
	end
	if(Boss.getTime()<40)then
		per=25
		if(Boss.getTime()<20)then per =15 end
		if(bTime%per==0)then boss_SE(KIRAN)
			et_s.rota(true)
			et_s.shine(true)
			et_s.outside(AREA_LEFT, IMG.MINI_STAR, CL.GREEN, 3, 0, 0)
			et_s.rota(true)
			et_s.shine(true)
			et_s.outside(AREA_RIGHT, IMG.MINI_STAR, CL.GREEN, 3, 0, 0)
			et_s.rota(true)
			et_s.shine(true)
			et_s.outside(AREA_UP, IMG.MINI_STAR, CL.GREEN, 3, 0, 0)
			et_s.rota(true)
			et_s.shine(true)
			et_s.outside(AREA_DOWN, IMG.MINI_STAR, CL.GREEN, 3, 0, 0)
		end
	end

	for bl_num = 0 , SHOT_MAX do TransS(bl_num) end --ステータス変更
	for l_num = 0 , LAZER_MAX do TransL(l_num,bTime) end
end

function TransS(bl_num)
	if (Shot.isFlag(bl_num)) then
		if(Shot.getState1(bl_num)==0)then
			if(Shot.getCount(bl_num)<2)then
				Shot.setAngle(rd_h.fShot_b(bl_num))
			end
			if(hitInCircle(Shot.getX(bl_num), Shot.getY(bl_num), Boss.getX(), Boss.getY(), 200))then
				Shot.clear()
			end
		end
	end
end

function TransL(l_num,bTime)
	if (Lazer.isFlag(l_num)) then
		if(Lazer.getCount(l_num)<30)then Lazer.addThick(1) end
		if(Lazer.getCount(l_num)==30)then Lazer.isCollision() end
		if(Lazer.getState1(l_num)==1)then Lazer.setRota(30,710,PI2) end
		if(Lazer.getState1(l_num)==2)then Lazer.setRota(30,710,-PI2) end
		if(Lazer.getCount(l_num)>710)then Lazer.addThick(-1) end
		if(Lazer.getCount(l_num)==740)then Lazer.clear() end
	end
end

--@EndScript