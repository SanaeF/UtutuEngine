dofile('./dat/Script/Bullet/Library.lua' )

Boss.cooldown_(4)
Boss.setLast()
Boss.set(Time(36), HP(12000))

function BossShot(bTime)
	t= bTime % 180
	if(isNotStart())then 
		boss_spawn(id(0), Boss.get_x() + 350, Boss.get_y() + 500, 2, HP(100), 0) 
	end
	if(bTime % 180 == 0) then 
		move_rand(100, 180, (FMAX_X - FMIN_X) - 100, 500, 200, 100) 
		Boss.charge()
	end
	if(bTime % 600 == 0) then
		for n = 0 , 50 do et_s.outside(AREA_LEFT, IMG.NORMAL ,CL.GREEN, sp_(3,7,8,11), 0, 0) end
		et_s.ring(diff(8,50,32,50), r_dt(10), IMG.NORMAL, CL.GREEN, sp_(3,7,8,11), rand(PI/3), 0)
		et_lc.ring(diff(8,50,32,50), r_dt(50), length(90), CL.PINK, sp_(3,10,9,11), rd_h.set(), st_(0)) 
		FieldCrush(10, 10)
		se_play(BULLET01)
	end
	if(bTime % 600 == 250) then
		et_lc.ring(diff(8,50,32,50), r_dt(50), length(90), CL.BLUE, sp_(3,10,9,11), rd_h.set(), st_(1)) 
		se_play(BULLET01)
	end
	if(bTime % 600 == 550)then 
		boss_spawn(id(1), Boss.get_x(), Boss.get_y(), 3, HP(100), 0) 
	end
	for bl_num = 0 , T_LAZ_MAX do Trans(bl_num) end
end

function Trans(bl_num)
	if (LazCr.isFlag(bl_num)) then 
		for st_num = 0 , 2 do
			if (st_num == 0) then mulv = -1 end
			if (st_num == 1) then mulv = 1 end
			et_lc.rd_add(bl_num, t0(20),  t1(40),  rd( mulv / 10), st_num)
			et_lc.rd_add(bl_num, t0(50),  t1(70),  rd(-mulv / 10), st_num)
			et_lc.rd_add(bl_num, t0(120), t1(170), rd( mulv / 10), st_num)
			et_lc.rd_add(bl_num, t0(170), t1(190), rd(-mulv / 10), st_num)
		end 
	end
end

BossShot(shot_time)