dofile('./dat/Script/Bullet/Library.lua' )
--大玉をばら撒いて、へにょりレーザー
function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.set(Time(60), HP(10000))
end

function BossShot()
	bTime = shot_time % 300
	if(between(bTime,0,100) and bTime%30==0)then boss_SE(BULLET01)
		et_s.shine(true)
		et_s.noDelete(true)
		et_s.ringAt(Boss.getX()-60, Boss.getY()-100,9, 0, IMG.MEGA, CL.PINK, 7+rand(1), rd_h.toPlayer(Boss.getX()-60, Boss.getY()-100), 1)
	end

	for bl_num = 0 , SHOT_MAX do TransS(bl_num,bTime) end --ステータス変更
	for lc_num = 0 , T_LAZ_MAX do TransLc(lc_num) end
end

function TransS(bl_num,bTime)
	if (Shot.isFlag(bl_num)) then
		if(Shot.getState1(bl_num)==1)then
			if(bTime==110)then boss_SE(KIRAN)
				Boss.charge()
				Shot.setSpeed(0)
			end
			if(bTime==140)then boss_SE(LAZER01)
				sx,sy=Param2(Shot.getX(bl_num), Shot.getY(bl_num))
				Shot.clear()
				et_lc.ringAt(sx,sy,3, 0, 40, CL.PURPLE, 7, rd_h.fShot_b(bl_num), 0)
				et_lc.ringAt(sx,sy,3, 0, 40, CL.CYAN, 7, rd_h.fShot_b(bl_num), 1)
			end
		end
	end
end

function TransLc(lc_num)
	if(LazCr.isFlag(lc_num))then
		et_lc.rd_add(lc_num, 0, 30, PI/90, 0)
		et_lc.rd_add(lc_num, 0, 30, -PI/90, 1)
		if(LazCr.getState1(lc_num)==0)then
			if(between(LazCr.getCount(lc_num)%60,0,30))then LazCr.addAngle(-PI/45) end
			if(between(LazCr.getCount(lc_num)%60,30,60))then LazCr.addAngle(PI/45) end
		end
		if(LazCr.getState1(lc_num)==1)then
			if(between(LazCr.getCount(lc_num)%60,0,30))then LazCr.addAngle(PI/45) end
			if(between(LazCr.getCount(lc_num)%60,30,60))then LazCr.addAngle(-PI/45) end
		end
	end
end

--@EndScript