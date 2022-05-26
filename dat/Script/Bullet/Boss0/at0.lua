dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	setWaitTime(2)
	prop(Time(32), HP(2600))
	summon(1,100,100,0,HP(2600))
	resetPosition()
	Boss.setDamageEffect(0,true)
end

function BossShot()
	bTime = shot_time % 400

	if(shot_time < 70)then drawSerifBox(Boss.getX(0),Boss.getY(0)-200,1,"Œ‚‚Á‚¿‚á‚¢‚Ü‚·‚æô") end
	if(bTime == 0)then
		Boss.Motion(0)
		Boss.charge()
		Boss.mv_rand(0,FMIN_X + 100, 180, FMAX_X - FMIN_X - 100, 500, 40, 100)
		Boss.mv_rand(1,FMIN_X + 100, 180, FMAX_X - FMIN_X - 100, 500, 40, 100)
	end
	if(between(bTime, 100, 350) and bTime % diff(37,32,22,0)  == 0)then boss_SE(BULLET01)
		et_s.boss_id(0)
		et_s.ring(diff(7,24,30,0), 0, IMG.NORMAL, CL.PINK, sp_(3,6,8,0), rd_h.Boss_Player(0), 0)
		et_s.boss_id(1)
		et_s.ring(diff(7,24,30,0), 0, IMG.NORMAL, CL.PINK, sp_(3,6,8,0), rd_h.Boss_Player(1), 0)
	end
	if(bTime == 10)then Boss.Motion(1) end
	if(between(bTime, 10, 330) and bTime % diff(9,7,2,0) == 0)then boss_SE(BULLET01)
		dist = diff(40, 70, 150,0)
		speed = diff(6,6,7,0) + rand(2)
		Shot.Create(Boss.getX(0) + rand(dist), Boss.getY(0) + rand(dist), IMG.AMMO, CL.BLUE, speed, rd_h.Boss_Player(), 0)
	end
	if(bTime == 330)then Boss.Motion(0) end
end

--@EndScript