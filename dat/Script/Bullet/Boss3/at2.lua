dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(1)
	Boss.set(Time(46), HP(6500))
end

function BossShot()
	bTime = shot_time % 280

	if(shot_time < 70)then Boss.setSerifBox(Boss.getX(),Boss.getY()-250,1,"Œ•‚ðŒ¤‚®‚í‚æI") end
	if(bTime == 0)then
		Boss.charge()
		Boss.Motion(2)
	end
	if(bTime%140 == 0)then
		move_rand(300, 380, (FMAX_X - FMIN_X) - 300, 500, 100, 40) 
	end
	if(bTime == 50)then
		Boss.Motion(1)
		et_s.size(2)
		et_s.numInState2(true)
		et_s.ring(diff(14,20,24,0), 220, IMG.AMMO, CL.RED, 0, 0, 2)
		et_s.size(2)
		et_s.numInState2(true)
		et_s.ring(diff(14,20,24,0), 220, IMG.AMMO, CL.RED, 0, 0, 3)
	end
	per=diff(15,12,10,0)
	if(bTime%per == 0)then boss_SE(BULLET01)
		num=9
		speed=diff(6,7,9,0)
		et_s.ring(num, 0, IMG.SCALY, CL.RED, speed, PI/62*(-bTime/per), 0)
		et_s.ring(num, 0, IMG.SCALY, CL.RED, speed, PI/62*(bTime/per), 0) 
	end
	for bl_num = 0 , SHOT_MAX do Trans(bl_num) end --ƒXƒe[ƒ^ƒX•ÏX
end

function Trans(bl_num)
	if (Shot.isFlag(bl_num)) then
		range=240
		hit_x1=x_dt(Boss.getX(), (shot_time/30), 180)
		hit_y1=y_dt(Boss.getY(), (shot_time/30), 180)
		hit_x2=x_dt(Boss.getX(), PI+(shot_time/30), 180)
		hit_y2=y_dt(Boss.getY(), PI+(shot_time/30), 180)
		if (Shot.getState1(bl_num) == 0) then
			if(hitOutCircle(Shot.getX(bl_num), Shot.getY(bl_num), hit_x1, hit_y1, range)and
				hitOutCircle(Shot.getX(bl_num), Shot.getY(bl_num), hit_x2, hit_y2, range))then
				Shot.addAngle(PI)
				Shot.setState1(1)
			end
		end
		if (Shot.getState1(bl_num) == 1) then
			Shot.isShine()
			Shot.setColor(CL.CYAN)
			Shot.isNotHide()
		end
		if (Shot.getState1(bl_num) == 2)then --‰~Žü‚Å‰ñ“]
			num=diff(10,14,27,0)--bTime=50 ‚Å”­ŽË‚µ‚½’e–‹‚Æ“¯‚¶‚É‚·‚é
			angle=(PI2/num*Shot.getState2(bl_num))+(shot_time/30)
			Shot.setX(x_dt(hit_x1, angle, range))
			Shot.setY(y_dt(hit_y1, angle, range))
			Shot.setAngle(angle)
			if(shot_time% 280==0)then
				Shot.setSpeed(diff(8,9,10,0))
				Shot.setState1(4)
			end
		end
		if (Shot.getState1(bl_num) == 3)then --‰~Žü‚Å‰ñ“]
			num=diff(10,14,27,0)--bTime=50 ‚Å”­ŽË‚µ‚½’e–‹‚Æ“¯‚¶‚É‚·‚é
			angle=(PI2/num*Shot.getState2(bl_num))-(shot_time/30)
			Shot.setX(x_dt(hit_x2, angle, range))
			Shot.setY(y_dt(hit_y2, angle, range))
			Shot.setAngle(angle)
			if(shot_time% 280==0)then
				Shot.setSpeed(diff(8,9,10,0))
				Shot.setState1(5)
			end
		end
		if(Shot.getState1(bl_num)==4)then Shot.addAngle(PI/4/60) end
		if(Shot.getState1(bl_num)==5)then Shot.addAngle(-PI/4/60) end
	end
end

--@EndScript