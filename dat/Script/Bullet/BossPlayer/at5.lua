dofile('./dat/Script/Bullet/Library.lua' )

Boss.cooldown_(1)
Boss.setLast()
Boss.set(Time(38), HP(2500))
Boss.noDamage(true)

function BossShot(bTime)
	who = Player.bossWho()
	who2 = Player.bossNotWho()
	bx, by = Param2(Boss.get_x(), Boss.get_y())
	px, py = Param2(Player.getX_who(who2), Player.getY_who(who2))
	Boss.set_x(Player.getX_who(who))
	LazerShot = 0

	for bl_num = 0 , T_LAZ_MAX do
		if (LazCr.isFlag(bl_num)) then
			LazerShot = 1
			et_lc.rd_add(bl_num, t0(20), t1(60), -PI / 3 / 40, 0)
			et_lc.rd_add(bl_num, t0(60), t1(100), PI / 3 / 40, 0)
		end
	end 
	for bl_num = 0 , SHOT_MAX do
		if (Shot.isFlag(bl_num)) then 
			if (Shot.getCount(bl_num) < 40)then
				if (Shot.getState1(bl_num) == 0) then Shot.addAngle((PI / 3) / 20) end
				if (Shot.getState1(bl_num) == 1) then Shot.addAngle((-PI / 3) / 20) end
				if (Shot.getState1(bl_num) == 2) then
					Shot.setType(IMG.RICE)
					Shot.setColor(CL.CYAN)
				end
			end
		end
	end

	if(Player.getKeyInput(who, 0) > 0)then
		if (bTime % 20 == 10)then se_play(BULLET01)
			angle = homing(bx, by, px, py)
			for n = 0 , 16 do
				rad = angle + PI2 / 17 * n
				Shot.Create(bx, by, IMG.BIG_STAR, CL.RED, 7.3, rad, n % 2)
				Shot.isRota()
				for n2 = 0 , 4 do
					stx, sty = Param2(x_dt(bx, rad, -n2 * 30), y_dt(by, rad, -n2 * 30))
					Shot.Create(stx, sty, IMG.MINI_STAR, CL.RED, 7.3, rad, n % 2)
					Shot.isRota()
				end
			end
		end
	end
	if(Player.getKeyInput(who, 1) > 0)then
		if(LazerShot == 0)then
			et_lc.ring(16, 0, 100, CL.PINK, 7, 0, 0)
		end
	end
	if(Player.getKeyInput(who, 2) > 0)then
		if (bTime % 15 == 10)then
			for n = 0 , 6 do
				stx, sty = Param2(x_dt(px, PI2 / 7 * n, 210), y_dt(py, PI2 / 7 * n, 210))
				angle = homing(stx, sty, px, py)
				Shot.Create(stx, sty, IMG.MINI_STAR, CL.BLUE, 2.5, angle + PI2 / 7, 3)
				Shot.isRota()
			end
		end
	end

end

BossShot(shot_time)

--@EndScript