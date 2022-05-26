dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.set(Time(24), HP(5600))
end

function BossShot()
	bTime = shot_time % 200

	if(bTime < 70)then Boss.setSerifBox(Boss.getX(),Boss.getY()-250,1,"‚¢‚¥`‚¢!(‚«‚ç‚ñô)") end
	if(bTime == 0)then boss_SE(BULLET01)
		Boss.Motion(1)
		move_rand(FMIN_X + 100, 180, FMAX_X - FMIN_X - 100, 500, 80, 100)
	end
	if(bTime % diff(100,50,25,0)  == 0)then boss_SE(BULLET02)
		et_s.nway(diff(3,5,7,0), 1, 0, IMG.BIG, CL.GREEN, sp_(3,4,7,0), 0, PI / 9, rd_h.Boss_Player(), 0)
	end
	if(between(bTime, 10, 150) and bTime % diff(3,4,6,0)  == 0)then boss_SE(BULLET02)
		way = diff(1,4,6,0)
		rota_rad = bTime-10
		et_s.rota(true)
		et_s.nway(way, 1, 0, IMG.MINI_STAR, CL.PINK, sp_(4,4,4,0), 0, PI / 21, PI + rd_h.Boss_Player() + PI / 47 * rota_rad, 0)
		et_s.rota(true)
		et_s.nway(way, 1, 0, IMG.MINI_STAR, CL.PINK, sp_(4,4,4,0), 0, PI / 21, PI + rd_h.Boss_Player() - PI / 47 * rota_rad, 0)
	end
	if(between(bTime, 30, 170) and bTime % diff(3,4,6,0)  == 0)then boss_SE(BULLET02)
		Boss.Motion(0)
		way = diff(1,4,6,0)
		rota_rad = bTime - 30
		et_s.rota(true)
		et_s.nway(way, 1, 0, IMG.MINI_STAR, CL.BLUE, sp_(4,4,4,0), 0, PI / 21, PI + rd_h.Boss_Player() - PI / 47 * rota_rad, 0)
		et_s.rota(true)
		et_s.nway(way, 1, 0, IMG.MINI_STAR, CL.BLUE, sp_(4,4,4,0), 0, PI / 21, PI + rd_h.Boss_Player() + PI / 47 * rota_rad, 0)
	end
end

--@EndScript