dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.noDamage(true)
	Boss.set(Time(60), HP(99999999))
	move(F_MAX_X+400, -400, 60)
end

function BossShot()
	if(Boss.getTime()>30)then 
		Phase1()
	else 
		Phase2() 
	end

	for bl_num = 0 , SHOT_MAX do TransS(bl_num) end --ステータス変更
end

function TransS(bl_num)
	if (Shot.isFlag(bl_num)) then
		if(Shot.getState1(bl_num)==1)then
			if(Shot.getCount(bl_num)>30)then boss_SE(KIRAN)
				num=diff(5,7,9,0)
				angle=homing(Shot.getX(bl_num),Shot.getY(bl_num), F_HALF_X, F_HALF_Y)
				et_s.ringAt(Shot.getX(bl_num),Shot.getY(bl_num),num, 0, IMG.PETAL, CL.ORANGE, 2, angle, 0)
				Shot.isFlag(bl_num)
				Shot.clear()
			end
		end
		if(Shot.getState1(bl_num)==2)then
			if(Shot.getCount(bl_num)>30)then boss_SE(KIRAN)
				angle=-PI/32*shot_time
				et_s.ringAt(Shot.getX(bl_num),Shot.getY(bl_num),3, 0, IMG.PETAL, CL.PINK, 3, angle, 0)
				Shot.isFlag(bl_num)
				Shot.clear()
			end
		end
	end
end

function Phase1()
	bTime = shot_time % 500
	per=40
	if(bTime%per==0)then boss_SE(BULLET02)
		et_s.ringAt(F_HALF_X, F_HALF_Y, 5, 500-bTime, IMG.APPLE, 0, 0, PI/15*(shot_time/per), 1)
	end
end

function Phase2()
	bTime = shot_time
	per=diff(25,25,20,0)
	if(bTime%per==0)then boss_SE(BULLET02)
		et_s.ringAt(F_HALF_X, F_HALF_Y, 5, 500, IMG.APPLE, 0, 0, -PI/30*(shot_time/per), 2)
	end
end

--@EndScript