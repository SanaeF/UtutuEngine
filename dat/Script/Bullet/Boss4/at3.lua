dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setLast()
	Boss.setMainBullet()
	Boss.set(Time(60), HP(12000))
end

function BossShot()
	bTime = shot_time % 560

	if(bTime==0)then Boss.charge() end

	if(bTime==10)then boss_SE(BULLET01)
		Boss.Motion(1)
		num=diff(8,10,14,0)
		et_s.shine(true)
		et_s.state2(1)
		et_s.ring(num, 0, IMG.MEGA, CL.BLUE, 4, rd_h.Boss_Player(), 1)
		et_s.shine(true)
		et_s.state2(1)
		et_s.ring(num, 0, IMG.MEGA, CL.BLUE, 4, rd_h.Boss_Player(), 2)
	end

	if(bTime==100)then 
		Boss.Motion(0)
		move_rand(FMIN_X + 100, 180, FMAX_X - FMIN_X - 100, 500, 80, 80)
	end
	per=120
	if(Boss.getHP()<7500)then per=70 end
	if(bTime>150 and bTime%per==0)then boss_SE(BULLET01)
		Boss.Motion(1)
		num=diff(16,20,24,0)
		et_s.shine(true)
		et_s.ring(num, 0, IMG.MEGA, CL.ORANGE, 4, rd_h.Boss_Player(), 1)
		et_s.shine(true)
		et_s.ring(num, 0, IMG.MEGA, CL.ORANGE, 4, rd_h.Boss_Player(), 2)
	end

	for s_num = 0 , SHOT_MAX do TransS(s_num) end --ステータス変更
end

function TransS(s_num)
	if(Shot.isFlag(s_num))then
		if(Shot.getState1(s_num)==1)then Shot.addAngle(PI/568) end
		if(Shot.getState1(s_num)==2)then Shot.addAngle(-PI/568) end
		if(Shot.getState2(s_num)==1)then
			per=diff(30,28,25,0)
			if(Shot.getCount(s_num)%per==0)then
				Shot.Create(Shot.getX(s_num), Shot.getY(s_num), IMG.OVERLAP, CL.PURPLE, 2, Shot.getAngle(s_num), 0)
				Shot.isShine()
			end
		end
	end
end

--@EndScript