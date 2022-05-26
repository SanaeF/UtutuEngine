dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(1)
	Boss.set(Time(34), HP(5600))
end

function BossShot()
	bTime = shot_time % 200

	if(bTime == 0)then
		Boss.Motion(0)
		Boss.charge()
		move_rand(FMIN_X + 100, 300, FMAX_X - FMIN_X - 100, 500, 100, 100)
	end
	if(between(bTime, 10, 150) and bTime % diff(21,15,9,0)  == 0)then boss_SE(BULLET02)
		num=diff(17,21,35,0)
		et_s.ring(num, 0, IMG.TRAMP , CL.PURPLE, sp_(4,6,7,0), 0, 0)
		et_s.ring(num, 0, IMG.TRAMP , CL.GREEEN, sp_(5,7,8,0), 0, 1)
	end
	for bl_num = 0 , SHOT_MAX do TransS(bl_num) end 
end

function TransS(bl_num)
	if (Shot.isFlag(bl_num)) then 
		t_dist=70
		et_s.rd_add(bl_num, 10, 10+t_dist, PI/2/t_dist, 0)
		et_s.rd_add(bl_num, 10, 10+t_dist, -PI/2/t_dist, 1)
		f_dist=10+t_dist
		et_s.rd_add(bl_num, f_dist, f_dist+t_dist, -PI/2/t_dist, 0)
		et_s.rd_add(bl_num, f_dist, f_dist+t_dist, PI/2/t_dist, 1)
		f_dist=f_dist+t_dist
		et_s.rd_add(bl_num, f_dist, f_dist+t_dist*4, PI/4/t_dist, 0)
		et_s.rd_add(bl_num, f_dist, f_dist+t_dist*4, -PI/4/t_dist, 1)
	end
end

--@EndScript