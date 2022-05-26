dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.set(Time(48), HP(4000))
end

function BossShot()
	bTime = shot_time % 280

	if(bTime%120 == 0)then
		Boss.Motion(1)
		Boss.charge()
		move_rand(FMIN_X + 100, 180, FMAX_X - FMIN_X - 100, 500, 80, 60)
	end
	if(bTime%120 == 60)then Boss.Motion(0) end
	if(bTime%10==0)then boss_SE(BULLET01)
		bx,by=Param2(Boss.getX()+rand(200),Boss.getY()+rand(200))
		angle = rd_h.toPlayer(bx,by)+rand(PI/3)
		et_s.shine(true)
		et_s.ringAt(bx,by, 7, 50, IMG.MEGA, CL.PINK, 10, angle, 0)
		et_s.shine(true)
		et_s.size(0.8)
		et_s.ringAt(bx,by, 14, 50, IMG.POIFUL, CL.PINK, 10, angle, 0)
	end
end

--@EndScript