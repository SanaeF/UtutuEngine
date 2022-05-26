dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.setBomInvalid()
	Boss.set(Time(60), HP(10000))
	Boss.Motion(1)
end

function BossShot()
	bTime = shot_time % 300
	if(bTime<100 and bTime%15==0)then boss_SE(BULLET01)
		et_s.shine(true)
		et_s.noDelete(true)
		et_s.ringAt(Boss.getX()-15, Boss.getY()-160,13, 0, IMG.MEGA, CL.ORANGE, 5, rd_h.Boss_Player()+rand(PI/13), 1)
	end

	if(bTime>160 and bTime%25==0)then boss_SE(BULLET01)
		Boss.Motion(1)
		et_s.shine(true)
		et_s.ringAt(Boss.getX()-15, Boss.getY()-160,36, 0, IMG.BIG, CL.GREEN, 13, rd_h.Boss_Player(), 1)
	end
	for bl_num = 0 , SHOT_MAX do TransS(bl_num,bTime) end --ステータス変更
end

function TransS(bl_num,bTime)
	if (Shot.isFlag(bl_num)) then
		if(Shot.getState1(bl_num)==1)then
			if(bTime==120)then boss_SE(KIRAN)
				Boss.Motion(0)
				Boss.charge()
				Shot.setSpeed(0)
			end
			if(bTime==140)then boss_SE(EXPLODE)
				crush(10,30)
				sx,sy=Param2(Shot.getX(bl_num), Shot.getY(bl_num))
				Shot.clear()
				et_s.shine(true)
				et_s.rota(true)
				et_s.ringAt(sx,sy,16, 0, IMG.MINI_STAR, CL.RED, 8, rd_h.fShot_p(bl_num)+rand(PI/46), 0)
				et_s.ringAt(sx,sy,8, 0, IMG.NORMAL, CL.YELLOW, 5, rd_h.fShot_p(bl_num)+PI/8+rand(PI/46), 0)
			end
		end
	end
end
--@EndScript