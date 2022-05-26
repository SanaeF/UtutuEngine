dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.set(Time(80), HP(7600))
end

function BossShot()
	bTime = shot_time % 280

	if(bTime == 0)then
		Boss.charge()
		Boss.Motion(2)
	end
	if(bTime%140 == 0)then
		move_rand(100, 180, (FMAX_X - FMIN_X) - 100, 500, 100, 40) 
	end
	if(bTime == 50)then
		Boss.Motion(1)
		et_s.size(3)
		et_s.numInState2(true)
		et_s.ring(diff(10,14,27,0), 220, IMG.AMMO, CL.ORANGE, 0, 0, 2)
	end
	per=diff(15,12,9,0)
	if(bTime>60 and bTime%per == 0)then boss_SE(BULLET01)
		num=diff(5,7,9,0)
		speed=diff(5,5,7,0)
		et_s.state2(0)
		et_s.ring(num, 0, IMG.RICE, CL.BLUE, speed, PI/42*(-bTime/per), 0)
		et_s.state2(1)
		et_s.ring(num, 0, IMG.RICE, CL.BLUE, speed, PI/42*(bTime/per), 0) 
	end

	for bl_num = 0 , SHOT_MAX do Trans(bl_num) end --ステータス変更
end

function Trans(bl_num)
	if (Shot.isFlag(bl_num)) then
		range=220
		if (Shot.getState1(bl_num) == 0) then
			if(Shot.getState2(bl_num)==0)then Shot.addAngle(PI/3/120) end
			if(Shot.getState2(bl_num)==1)then Shot.addAngle(-PI/3/120) end
			if(hitOutCircle(Shot.getX(bl_num), Shot.getY(bl_num), Boss.getX(), Boss.getY(), range))then
				Shot.addAngle(PI)
				Shot.setState1(1)
			end
		end
		if (Shot.getState1(bl_num) == 1) then
			if(Shot.getState2(bl_num)==0)then Shot.addAngle(PI/4/120) end
			if(Shot.getState2(bl_num)==1)then Shot.addAngle(-PI/4/120) end
			if(hitInCircle(Shot.getX(bl_num), Shot.getY(bl_num), Boss.getX(), Boss.getY(), range))then
				Shot.isHide()
			else
				Shot.isShine()
				Shot.setColor(CL.CYAN)
				Shot.setSize(1.2)
				Shot.isNotHide()
			end
		end
		if (Shot.getState1(bl_num) == 2)then --円周で回転
			num=diff(10,14,27,0)--bTime=50 で発射した弾幕と同じにする
			angle=(PI2/num*Shot.getState2(bl_num))+(shot_time/30)
			Shot.setX(x_dt(Boss.getX(), angle, range))
			Shot.setY(y_dt(Boss.getY(), angle, range))
			Shot.setAngle(angle)
			if(shot_time% 280==0)then
				Shot.setSpeed(diff(6,7,9,0))
				Shot.setState1(3)
			end
		end
	end
end

--@EndScript