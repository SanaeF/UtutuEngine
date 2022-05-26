dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(1)
	Boss.set(Time(40), HP(5000))
end

function BossShot()
	bTime = shot_time % 280

	if(shot_time < 70)then Boss.setSerifBox(Boss.getX(),Boss.getY()-250,1,"Ç≥ÇüÅAÇ¢Ç≠ÇÌÇÊ!") end
	if(bTime == 0)then
		Boss.charge()
		Boss.Motion(2)
	end
	if(bTime%140 == 0)then
		move_rand(100, 180, (FMAX_X - FMIN_X) - 100, 500, 100, 40) 
	end
	if(bTime == 50)then
		Boss.Motion(1)
		et_s.size(2)
		et_s.numInState2(true)
		et_s.ring(diff(14,24,27,0), 220, IMG.AMMO, CL.ORANGE, 0, 0, 2)
		et_s.size(2)
		et_s.numInState2(true)
		et_s.ring(diff(14,24,27,0), 220, IMG.AMMO, CL.ORANGE, 0, 0, 3)
	end
	per=diff(15,12,9,0)
	if(bTime>60 and bTime%per == 0)then boss_SE(BULLET01)
		num=9
		speed=diff(5,5,7,0)
		et_s.ring(num, 0, IMG.SCALY, CL.RED, speed, PI/62*(-bTime/per), 0)
		et_s.ring(num, 0, IMG.SCALY, CL.RED, speed, PI/62*(bTime/per), 0) 
	end

	for bl_num = 0 , SHOT_MAX do Trans(bl_num) end --ÉXÉeÅ[É^ÉXïœçX
end

function Trans(bl_num)
	if (Shot.isFlag(bl_num)) then
		range=220
		if (Shot.getState1(bl_num) == 0) then
			if(hitOutCircle(Shot.getX(bl_num), Shot.getY(bl_num), Boss.getX(), Boss.getY(), range))then
				Shot.addAngle(PI)
				Shot.setState1(1)
			end
		end
		if (Shot.getState1(bl_num) == 1) then
			if(hitInCircle(Shot.getX(bl_num), Shot.getY(bl_num), Boss.getX(), Boss.getY(), range))then
				Shot.isHide()
			else
				Shot.isShine()
				Shot.setColor(CL.CYAN)
				Shot.isNotHide()
			end
		end
		if (Shot.getState1(bl_num) == 2)then --â~é¸Ç≈âÒì]
			num=diff(10,14,27,0)--bTime=50 Ç≈î≠éÀÇµÇΩíeñãÇ∆ìØÇ∂Ç…Ç∑ÇÈ
			angle=(PI2/num*Shot.getState2(bl_num))+(shot_time/30)
			Shot.setX(x_dt(Boss.getX(), angle, range+60))
			Shot.setY(y_dt(Boss.getY(), angle, range+60))
			Shot.setAngle(angle)
			if(shot_time% 280==0)then
				Shot.setSpeed(diff(8,9,10,0))
				Shot.setState1(4)
			end
		end
		if (Shot.getState1(bl_num) == 3)then --â~é¸Ç≈âÒì]
			num=diff(14,24,27,0)--bTime=50 Ç≈î≠éÀÇµÇΩíeñãÇ∆ìØÇ∂Ç…Ç∑ÇÈ
			angle=(PI2/num*Shot.getState2(bl_num))-(shot_time/30)
			Shot.setX(x_dt(Boss.getX(), angle, range))
			Shot.setY(y_dt(Boss.getY(), angle, range))
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