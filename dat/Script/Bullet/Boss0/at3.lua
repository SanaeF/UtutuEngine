dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.set(Time(50), HP(8000))
end

function BossShot()
	bTime = shot_time % 350

	if(shot_time < 70)then Boss.setSerifBox(Boss.getX(),Boss.getY()-200,1,"しぶといですねぇ") end
	if(bTime == 10)then Boss.Motion(1) end
	if(bTime == 180)then Boss.Motion(0) end
	if(bTime % diff(15,12,7,0) == 0)then boss_SE(BULLET01)
		dist = diff(40, 70, 100,0)
		speed = diff(6,6,7,0) + rand(2)
		angle = rd_h.Boss_Player() + PI/2
		Shot.Create(Boss.getX() + rand(dist), Boss.getY() + rand(dist), IMG.SCALY, CL.RED, speed, angle, 1)
		Shot.isBound()
		angle = rd_h.Boss_Player() + PI/2+PI
		Shot.Create(Boss.getX() + rand(dist), Boss.getY() + rand(dist), IMG.SCALY, CL.RED, speed, angle, 1)
		Shot.isBound()
	end
	for bl_num = 0 , SHOT_MAX do TransS(bl_num) end --ステータス変更
end
function TransS(bl_num)
	if (Shot.isFlag(bl_num)) then 
		if (Shot.getState1(bl_num) == 1) then 
			if (Shot.getBoundCount(bl_num) > 0)then
				Shot.setType(IMG.AMMO)
				Shot.setColor(CL.CYAN)
				Shot.setSpeed(diff(4,6,8,0))
				Shot.setAngle(rd_h.toPlayer(Shot.getX(bl_num),Shot.getY(bl_num)) + rand(PI/25))
				Shot.isNotBound()
				Shot.setState1(0)
			end
		end
	end
end

--@EndScript