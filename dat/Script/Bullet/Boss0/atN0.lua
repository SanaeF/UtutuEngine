dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.set(Time(23), HP(3600))
end

function BossShot()
	bTime = shot_time % 280

	if(bTime == 0)then
		Boss.charge()
		move_rand(100, 180, (FMAX_X - FMIN_X) - 100, 500, 200, 100) 
	end

	if(bTime > 80 and bTime % 11 == 0)then boss_SE(BULLET01)
		et_s.ring(diff(7,13,25,0), 0, IMG.NORMAL, CL.PURPLE, sp_(4,5,5), rand(PI/6), 0) end --星弾

	for bl_num = 0 , SHOT_MAX do Trans(bl_num) end --ステータス変更
end

function Trans(bl_num)
	if (Shot.isFlag(bl_num)) then
		if (Shot.getState1(bl_num) == 0 and Shot.getCount(bl_num) == 60) then
			Shot.Create(Shot.getX(bl_num), Shot.getY(bl_num), IMG.NORMAL, CL.PINK, Shot.getSpeed(bl_num)+2, Shot.getAngle(bl_num), 1)
		end
	end
end

--@EndScript