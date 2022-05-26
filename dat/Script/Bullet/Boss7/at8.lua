dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.set(Time(48), HP(9000))
end

function BossShot()
	bTime = shot_time % 300

	if(bTime%120 == 0)then
		Boss.Motion(1)
		Boss.charge()
		move_rand(FMIN_X + 200, 200, FMAX_X - FMIN_X - 200, 500, 80, 60)
	end
	if(bTime%120 == 60)then Boss.Motion(0) end
	if(bTime%90==0)then boss_SE(BULLET01)
		bx,by=Param2(Boss.getX()+rand(200),Boss.getY()+rand(200))
		angle = rd_h.toPlayer(bx,by)+rand(PI/3)
		et_s.shine(true)
		et_s.size(0.8)
		et_s.ringAt(bx,by, 22, 0, IMG.MEGA, CL.RED, 4, angle, 1)
		et_s.shine(true)
		et_s.size(0.8)
		et_s.ringAt(bx,by, 22, 0, IMG.MEGA, CL.RED, 4, angle, 2)
	end

	for bl_num = 0 , SHOT_MAX do TransS(bl_num) end --ステータス変更
end

function TransS(bl_num)
	if (Shot.isFlag(bl_num)) then
		if(Shot.getState1(bl_num)==1)then Shot.addAngle(PI/2/250) end
		if(Shot.getState1(bl_num)==2)then Shot.addAngle(-PI/2/250) end
	end
end

--@EndScript