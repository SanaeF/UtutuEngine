dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.set(Time(28), HP(3900))
end

function BossShot()
	bTime = shot_time % 210
	
	if(bTime == 160)then
		Boss.charge()
		move_rand(100, 180, (FMAX_X - FMIN_X) - 100, 500, 200, 100) end

	if(bTime == 10) then boss_SE(LAZER01)
		et_lc.bound(true)
		et_lc.nway(70, 6, 0, CL.PINK, 10, PI/6, rd_h.Boss_Player() + PI, 0)--曲がるレーザー
	end
	if(bTime == 80) then boss_SE(LAZER01)
		et_lc.bound(true)
		et_lc.nway(70, 6, 0, CL.PINK, 10, PI/6, rd_h.Boss_Player() + PI, 1)--曲がるレーザー
	end

	for bl_num = 0 , T_LAZ_MAX do TransL(bl_num) end --ステータス変更
end

function TransL(bl_num)
	if (LazCr.isFlag(bl_num)) then
		if(LazCr.getBoundCount(bl_num) > 0)then 
			LazCr.isNotBound() 
			if not(LazCr.getState1(bl_num)==2)then boss_SE(KIRAN)
				diff_param=diff(5,9,17,0)
				for ite = 0 ,diff_param do
					Shot.Create(LazCr.getX(bl_num), LazCr.getY(bl_num), IMG.RICE, CL.BLUE, 2+rand(1.5),PI2 / diff_param*ite+rand(PI/17), 0)
				end
			end
			LazCr.setState1(2)
			LazCr.isNotBound() 
		end
		for st_num = 0 , 2 do
			if (st_num == 0) then mulv = -1 end	
			if (st_num == 1) then mulv = 1 end
			et_lc.rd_add(bl_num, t0(0),	t1(60), mulv * PI / 3 / 15, st_num)
			et_lc.rd_add(bl_num, t0(50), t1(250), mulv * PI / 3 / 90, st_num) end
	end
end

--@EndScript