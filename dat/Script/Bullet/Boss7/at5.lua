dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.setBomInvalid()
	Boss.set(Time(60), HP(14000))
	Boss.Motion(0)
end

function BossShot()
	t_laz_first=20
	t_laz_dist=350
	bTime = shot_time % (t_laz_first+t_laz_dist+t_laz_dist)
	if(bTime==t_laz_first)then
		for ite = 0 , 10 do
			LazCr.Create(0+(130*ite),0, 150, CL.BLUE, 9, PI/2+PI/4, 1)
		end
	end
	if(bTime==t_laz_first+t_laz_dist)then boss_SE(LAZER01)
		Boss.Motion(1)
		for ite = 0 , 10 do
			LazCr.Create(50+(130*ite), F_MAX_Y, 150, CL.BLUE, 9, -PI/2+PI/4, 1)
		end
	end
	if(bTime%120==0)then
		Boss.Motion(1) 
		Boss.charge()
		move_rand(FMIN_X + 200, 200, FMAX_X - FMIN_X - 200, 500, 80, 60)
	end
	if(bTime%120==10)then boss_SE(BULLET01)
		et_s.shine(true)
		et_s.bound(true)
		et_s.rota(true)
		et_s.noDelete(true)
		et_s.ringAt(Boss.getX()-15, Boss.getY()-160,4, 0, IMG.MEGA, CL.PURPLE, 5, rd_h.Boss_Player(), 1)
	end
	if(bTime%120==60)then Boss.Motion(0) end

	for bl_num = 0 , SHOT_MAX do TransS(bl_num) end --ステータス変更
	for lc_num = 0 , T_LAZ_MAX do TransLc(lc_num) end --ステータス変更
end
function TransLc(lc_num)
	if(LazCr.isFlag(lc_num))then
		if(LazCr.getCount(lc_num)%8==3)then LazCr.addAngle(-PI/2) end
		if(LazCr.getCount(lc_num)%8==7)then LazCr.addAngle(PI/2) end
	end
end

function TransS(bl_num)
	if (Shot.isFlag(bl_num)) then
		if(Shot.getBoundCount(bl_num)>=1)then boss_SE(KIRAN)
			sx,sy=Param2(Shot.getX(bl_num), Shot.getY(bl_num))
			Shot.clear()
			et_s.rota(true)
			et_s.ringAt(sx,sy,25, 0, IMG.MINI_STAR, CL.PINK, 2, rd_h.fShot_p(bl_num), 0)
		end
	end
end
--@EndScript