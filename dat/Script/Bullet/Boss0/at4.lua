dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.setLast()
	Boss.set(Time(40), HP(8000))
end

function BossShot()
	bTime = shot_time % 350

	if(shot_time < 70)then Boss.setSerifBox(Boss.getX(),Boss.getY()-200,1,"疲れちゃった♪") end
	if(shot_time == 0)then move((FMAX_X - FMIN_X) / 2, (FMAX_Y - FMIN_Y) / 2, 40) end
	if(shot_time == 2)then InitMonster() end
	if(shot_time > 160)then BulletPhase(bTime) end
	for e_num = 0 , MINION_MAX do TransE(e_num,bTime) end --使い魔のステータス変更
	for bl_num = 0 , SHOT_MAX do TransS(bl_num) end --ステータス変更
end

function InitMonster()
	se_play(GYUUUUUUN)
	Boss.Motion(1)
	en_spawn(Boss.getX(), Boss.getY(), DEV_ORANGE, 999999, 0, 0)
	en_item(Power, 0)
	Minion.setAngle(-PI/2 + PI/3.4)
	Minion.setSpeed(6)
	en_spawn(Boss.getX(), Boss.getY(), DEV_ORANGE, 999999, 0, 0)
	en_item(Power, 0)
	Minion.setAngle(-PI/2 - PI/3.4)
	Minion.setSpeed(6)
end
function BulletPhase(bTime)
	if(40<bTime and bTime % diff(37,32,28,0)  == 0)then boss_SE(BULLET01)
		et_s.ring(diff(7,14,21,0), 0, IMG.SCALY, CL.PINK, sp_(3,6,4,0), rd_h.Boss_Player(), 1)
		et_s.ring(diff(7,14,21,0), 0, IMG.SCALY, CL.PINK, sp_(3,6,4,0), rd_h.Boss_Player(), 2)
	end
end
function TransE(e_num,bTime)
	if (Minion.isFlag(e_num))then
		ex,ey=Param2(Minion.getX(e_num),Minion.getY(e_num))
		if (shot_time == 70)then Minion.setSpeed(0) end
		if(Minion.getSize(e_num) < 4)then Minion.setSize(Minion.getSize(e_num) + 0.03)
		else Minion.setType(DEV_HACK) end

		if (shot_time > 160 and bTime % diff(55,55,50,0) == 0)then boss_SE(BULLET01)
			angle = rd_h.toPlayer(ex,ey)
			Shot.Create(ex, ey, IMG.AMMO, CL.BLUE, sp_(6,7,9,0), angle, 0)
			Shot.setSize(Minion.getSize(e_num))
		end
	end
end

function TransS(bl_num)
	if (Shot.isFlag(bl_num) and Shot.getCount(bl_num) < 90) then 
		if (Shot.getState1(bl_num) == 1) then Shot.addAngle(PI/6/90) end
		if (Shot.getState1(bl_num) == 2) then Shot.addAngle(-PI/6/90) end
	end
end

--@EndScript