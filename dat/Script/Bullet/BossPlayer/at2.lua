dofile('./dat/Script/Bullet/Library.lua' )

Boss.cooldown_(1)
Boss.setLast()
Boss.set(Time(32), HP(2500))
Boss.noDamage(true)

function BossShot(bTime)
	who = Player.bossWho()
	who2 = Player.bossNotWho()
	bx, by = Param2(Boss.get_x(), Boss.get_y())
	px, py = Param2(Player.getX_who(who2), Player.getY_who(who2))
	Boss.set_x(Player.getX_who(who))
	Shot_Now1 = 0
	Shot_Now2 = 0
	Shot_Now3 = 0

	for bl_num = 0, SHOT_MAX do
		if(Shot.isFlag(bl_num))then
			if(Shot.getState1(bl_num) == 1)then Shot_Now1 = 1 end
			if(Shot.getState1(bl_num) == 2)then Shot_Now2 = 1 end
			if(Shot.getState1(bl_num) == 3)then Shot_Now3 = 1 end
			if not(Shot.getState1(bl_num) == 0)then
				if (Shot.getBoundCount(bl_num) > 3)then Shot.isNotBound() end
				if not(Shot.getBoundArea(bl_num) == 0)then se_play(KIRAN)
					areaNum = Shot.getBoundArea(bl_num)
					Shot.setBoundArea(0)
					FieldCrush(8, 50)
					for n = 0 , 10 do 
						et_s.rota(true)
						et_s.outside(areaNum, IMG.MINI_STAR, CL.BLUE, sp(3 + rand(1)), rd(0), st(0))
					end
				end
			end
		end
	end

	if(Player.getKeyInput(who, 0) > 0)then
		if(Shot_Now1 == 0)then se_play(BULLET01)
			angle = homing(bx, by, px, py)
			Shot.Create(bx, by, IMG.MOON, false, 7, angle, 1)
			Shot.setSize(2)
			Shot.isRota()
			Shot.isBound()
		end
	end
	if(Player.getKeyInput(who, 1) > 0)then
		if(Shot_Now2 == 0)then se_play(BULLET01)
			angle = PI / 9
			Shot.Create(bx, by, IMG.MOON, false, 10, PI / 2 - angle, 2)
			Shot.setSize(2)
			Shot.isRota()
			Shot.isBound()
			Shot.Create(bx, by, IMG.MOON, false, 10, PI / 2 + angle, 2)
			Shot.setSize(2)
			Shot.isRota()
			Shot.isBound()
		end
	end
	if(Player.getKeyInput(who, 2) > 0)then
		if(Shot_Now3 == 0)then se_play(BULLET01)
			angle = PI / 9
			Shot.Create(bx, by, IMG.MOON, false, 9, -PI / 2 - angle, 3)
			Shot.setSize(2)
			Shot.isRota()
			Shot.isBound()
			Shot.Create(bx, by, IMG.MOON, false, 9, -PI / 2 + angle, 3)
			Shot.setSize(2)
			Shot.isRota()
			Shot.isBound()
		end
	end

end

BossShot(shot_time)

--@EndScript