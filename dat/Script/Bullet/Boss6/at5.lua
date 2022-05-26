dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.set(Time(46), HP(9500))
	move((FMAX_X - FMIN_X) / 2, (FMAX_Y - FMIN_Y) / 2, 40)
end

function BossShot()
	bTime = shot_time % 420
	if(shot_time == 60)then
		et_l.standType(IMG.BIG)
		et_l.size(1400, 4)
		et_l.ringAt(Boss.getX()-60, Boss.getY()-100, 9, 0, IMG.LAZER, CL.ORANGE, 0, 0, 0)
		et_l.standType(IMG.BIG)
		et_l.size(1400, 4)
		et_l.ringAt(Boss.getX()-60, Boss.getY()-100, 9, 0, IMG.LAZER, CL.SKY, 0, 0, 1)
	end
	if(bTime%60 == 0)then boss_SE(BULLET02)
		et_s.rota(true)
		et_s.ring(17, 0, IMG.TRAMP, CL.PINK, 3, 0, 0)
	end
	for l_num = 0 , LAZER_MAX do TransL(l_num) end
end

function TransL(l_num)
	if (Lazer.isFlag(l_num)) then
		if(Lazer.getState1(l_num)==0)then
			Lazer.addLengthAngle(PI/420)
			if(Lazer.getCount(l_num)%420==40)then 
				boss_SE(GYUUUUUUN)
				Boss.charge()
			end
			if(between(Lazer.getCount(l_num)%420,60,120))then
				Lazer.isCollision()
				Lazer.addThick(0.7)
			end
			if(between(Lazer.getCount(l_num)%420,120,180))then
				Lazer.isNotCollision()
				Lazer.addThick(-0.7)
			end
		end
		if(Lazer.getState1(l_num)==1)then
			Lazer.addLengthAngle(-PI/420)
			if(Lazer.getCount(l_num)%420==180)then
				boss_SE(GYUUUUUUN)
				Boss.charge() 
			end
			if(between(Lazer.getCount(l_num)%420,200,260))then
				Lazer.isCollision()
				Lazer.addThick(0.7)
			end
			if(between(Lazer.getCount(l_num)%420,260,320))then
				Lazer.isNotCollision()
				Lazer.addThick(-0.7)
			end
		end
	end
end

--@EndScript