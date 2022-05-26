dofile('./dat/Script/Bullet/Library.lua' )

Boss.cooldown_(1)
Boss.setLast()
Boss.set(Time(42), HP(2500))
Boss.noDamage(true)

function BossShot(bTime)
	who = Player.bossWho()
	who2 = Player.bossNotWho()
	bx, by = Param2(Boss.get_x(), Boss.get_y())
	px, py = Param2(Player.getX_who(who2), Player.getY_who(who2))
	Boss.set_x(Player.getX_who(who))

	if(bTime == 1)then
		et_l.size(2200, 1)
		et_l.startCount(3000)
		et_l.standType(IMG.BIG_STAR)
		et_l.nwayAt(bx + 100, by, 5, 1, 0, IMG.LAZER, CL.ORANGE, 0, 0, -PI / 19, PI / 2 - (PI / 19) * 3, 1)
		et_l.size(2200, 1)
		et_l.startCount(3000)
		et_l.standType(IMG.BIG_STAR)
		et_l.nwayAt(bx - 100, by, 5, 1, 0, IMG.LAZER, CL.ORANGE, 0, 0, PI / 19, PI / 2 + (PI / 19) * 3, 2)
	end

	if(Player.getKeyInput(who, 0) > 0)then
		if (bTime % 5 == 2)then
			angle = PI / 17 * (bTime / 5)
			angle2 = PI2 / 9 * (bTime / 5) + rand(PI / 9)
			Shot.Create(x_dt(bx, PI / 2 + angle, 200), y_dt(by, PI / 2 + angle, 200), IMG.RICE, CL.YELLOW, 1.5, PI / 2 + angle2, 1)
			Shot.isShine()
			Shot.Create(x_dt(bx, PI / 2 - angle, 200), y_dt(by, PI / 2 - angle, 200), IMG.RICE, CL.YELLOW, 1.5, PI / 2 + angle2, 1)
			Shot.isShine()
		end
	end

	for bl_num = 0, LAZER_MAX do 
		if(Lazer.isFlag(bl_num))then
			firstTime = 70
			StayTime = 60
			if(Player.getKeyInput(who, 1) > 0)then
				if (Lazer.getCount(bl_num) > firstTime + StayTime * 3)then
					Lazer.setCount(0)
				end
			end
			if(between(Lazer.getCount(bl_num), firstTime, firstTime + StayTime))then
				Lazer.isCollision()
				Lazer.addThick(0.3)
			end
			if(between(Lazer.getCount(bl_num), firstTime + StayTime * 2, firstTime + StayTime * 3))then
				Lazer.isNotCollision()
				Lazer.addThick(-0.3)
			end
			if(Lazer.getState1(bl_num) == 1)then
				Lazer.setX(bx + 100)
			end
			if(Lazer.getState1(bl_num) == 2)then
				Lazer.setX(bx - 100)
			end
		end
	end

	if(Player.getKeyInput(who, 2) > 0)then
		if (bTime % 45 == 4)then
			angle = rand(PI / 3);
			et_s.rota(true)
			et_s.ring(8, 0, IMG.BIG_STAR, CL.ORANGE, 5, angle, 1)
			et_s.rota(true)
			et_s.ring(8, 0, IMG.BIG_STAR, CL.ORANGE, 5, angle + PI / 19, 2)
		end
	end

	for bl_num = 0, SHOT_MAX do
		if(Shot.isFlag(bl_num))then
			et_s.rd_add(bl_num, 20, 50, PI / 3 / 30, 1)
			et_s.rd_add(bl_num, 50, 100, -PI / 3 / 30, 1)
			et_s.rd_add(bl_num, 20, 50, -PI / 3 / 30, 2)
			et_s.rd_add(bl_num, 50, 100, PI / 3 / 30, 2)
		end
	end

end

BossShot(shot_time)

--@EndScript