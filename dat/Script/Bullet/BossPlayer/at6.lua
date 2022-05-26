dofile('./dat/Script/Bullet/Library.lua' )

Boss.cooldown_(1)
Boss.setLast()
Boss.set(Time(80), HP(2500))
Boss.noDamage(true)

function BossShot(bTime)
	who = Player.bossWho()
	who2 = Player.bossNotWho()
	bx, by = Param2(Boss.get_x(), Boss.get_y())
	px, py = Param2(Player.getX_who(who2), Player.getY_who(who2))
	Boss.set_x(Player.getX_who(who))

	for bl_num = 0 , SHOT_MAX do
		if (Shot.isFlag(bl_num)) then 
			if (Shot.getState1(bl_num) == 1) then
				if (Shot.getCount(bl_num) > 40)then Shot.addSpeed(0.03) end
			end
			if (Shot.getState1(bl_num) == 2) then
				if (Shot.getCount(bl_num) >= 90)then Shot.setSpeed(3) end
			end
		end
	end

	if(Player.getKeyInput(who, 0) > 0)then
		if (bTime % 32 == 15)then se_play(BULLET01)
			for n = 0 , 6 do
				rad = PI2 / 7 * n - PI / 15 * (bTime / 32)
				Shot.Create(bx, by, IMG.B_FLY, CL.RED, 5, rad, 1)
				et_s.rota(true)
				et_s.ringVecAt(bx, by, num(9), r_dt(60), IMG.MINI_STAR, (CL.RED - n) % 9, 5, rad, 1)
			end
		end
	end
	if(Player.getKeyInput(who, 1) > 0)then
		if (bTime % 32 == 31)then se_play(BULLET01)
			for n = 0 , 6 do
				rad = PI2 / 7 * n - PI / 15 * (bTime / 32)
				Shot.Create(bx, by, IMG.B_FLY, CL.RED, 5, rad, 1)
				et_s.rota(true)
				et_s.ringVecAt(bx, by, num(20), r_dt(60), IMG.MINI_STAR, (CL.RED - n) % 9, 5, rad, 1)
			end
		end
	end
	if(Player.getKeyInput(who, 2) > 0)then
		if (bTime % 2 == 0)then se_play(BULLET02) se_play(KIRAN)
			for n = 0 , 3 do
				if (n == 0 or n == 1) then
					rd = PI / 2 + PI2 / 3 * n + PI / 80 * (bTime / 2);
				end
				if (n == 2 or n == 3) then
					rd = PI / 2 + PI2 / 3 * n - PI / 80 * (bTime / 2);
				end
				stx, sty = Param2(x_dt(bx, rd, 210), y_dt(by, rd, 210))
				if (n == 0 or n == 1) then
					rd = PI / 2 + PI / 19 * (bTime / 2);
				end
				if (n == 2 or n == 3) then
					rd = PI / 2 + PI / 19 * (bTime / 2);
				end
				Shot.Create(stx, sty, IMG.RICE, n % 9, 0, rd, 2)
				Shot.isShine()
			end
		end
	end

end

BossShot(shot_time)

--@EndScript