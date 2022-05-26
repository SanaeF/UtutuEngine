dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(1)
	Boss.set(Time(32), HP(2500))
end

function BossShot()
	bTime = shot_time % 400

	if(shot_time < 70)then Boss.setSerifBox(Boss.getX(),Boss.getY()-200,1,"‚»`‚êô‚»‚êô") end
	if(shot_time == 0)then move((FMAX_X - FMIN_X) / 2, 280, 40) end
	if(bTime == 0)then
		Boss.Motion(0)
		Boss.charge()
		move_rand(FMIN_X + 100, 180, FMAX_X - FMIN_X - 100, 500, 40, 100)
	end
	if(between(bTime, 100, 350) and bTime % diff(37,32,22,0)  == 0)then boss_SE(BULLET01)
		et_s.ring(diff(7,24,30,0), 0, IMG.NORMAL, CL.PINK, sp_(3,6,8,0), rd_h.Boss_Player(), 0)
	end
	if(bTime == 10)then 
		Boss.Motion(1)
	end
	if(bTime % 100  == 0)then boss_SE(BULLET01)
		for bl_num = 0 , diff(40, 70, 70,0) do
			dist = diff(40, 70, 140,0)
			speed = diff(6,6,7,0) + rand(2) + (bl_num/10)
			Shot.Create(Boss.getX() + rand(dist), Boss.getY() + rand(dist), IMG.AMMO, CL.RED, speed, rd_h.Boss_Player(), 0)
		end
	end
	if(bTime == 330)then Boss.Motion(0) end
end

function TransS(bl_num)
	if (Shot.isFlag(bl_num)) then 
	end
end

--@EndScript