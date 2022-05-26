dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	setWaitTime(3)
	prop(Time(32), HP(3200))
	setSpecialBullet(true)
	setReturnBack(true)
end

function BossShot()
	bTime = shot_time % 300

	if(shot_time < 120)then Boss.setSerifBox(Boss.getX(),Boss.getY()-100,1,"それゆけ!変な奴♪") end
	if(shot_time == 0)then Boss.Motion(0) end
	if(shot_time == 0)then move((FMAX_X - FMIN_X) / 2, 180, 40) end
	if(shot_time == 2)then InitMonster() end
	if(shot_time > 80)then BulletPhase(bTime) end
	if(Minion.getSize(0) < 4)then Minion.setSize(Minion.getSize(0)+ 0.03)
	else 
	Minion.setType(DEV_HACK) 
	end
	for bl_num = 0 , SHOT_MAX do TransS(bl_num) end --ステータス変更
end
function InitMonster()
	Boss.Motion(1)
	boss_SE(GYUUUUUUN)
	if (Player.getItemApple() == 2)then item = Power
	else item = Apple end
	en_spawn((FMAX_X - FMIN_X) / 2, Boss.getY()+160, DEV_ORANGE, 2000, 0, 0)
	en_item(item, 1)
end
function BulletPhase(bTime)
	if(bTime % 100 == 0)then move_rand(FMIN_X + 100, 80, FMAX_X - FMIN_X - 100, 180, 30, 100) end
	ex, ey = Param2(Minion.getX(0), Minion.getY(0))

	if(Minion.isFlag(0))then
		if(between(bTime, 10, 200) and bTime % diff(58,46,32,0) == 0)then boss_SE(BULLET01)
			et_s.size(Minion.getSize(0))
			et_s.nwayAt(ex, ey, 3, 1, 0, IMG.POIFUL , CL.PURPLE, sp_(6,7,8,0), 0, PI/3, rd_h.toPlayer(ex,ey), 0)
		end
	else
		if( bTime % diff(9,7,5,0) == 3)then boss_SE(BULLET01)
			num = diff(5,6,7,0)
			for bl_num = 0 , num do
				Shot.Create(Boss.getX(), Boss.getY(), IMG.RICE, CL.PINK, sp_(6,7,8,0) + rand(2), PI2/ num * bl_num + rand(PI/num), 1)
			end
		end
	end
	if(between(bTime, 50, 250) and bTime % diff(9,7,3,0) == 0)then boss_SE(BULLET01)
		num = diff(5,7,8,0)
		for bl_num = 0 , num do
			Shot.Create(Boss.getX(), Boss.getY(), IMG.DUST , CL.RED, sp_(4,4,8,0) + rand(2), PI2/ num * bl_num + rand(PI/num), 1)
		end
	end
end

function TransS(bl_num)
	if (Shot.isFlag(bl_num) and Shot.getCount(bl_num) > 90) then 
		if (Shot.getState1(bl_num) == 1) then Shot.addSpeed(0.16) end
	end
end

--@EndScript