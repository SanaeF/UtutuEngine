dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.set(Time(60), HP(7000))
end

function BossShot()
	bTime = shot_time
	if(Boss.getHP()<3500)then bTime = shot_time % 100
	else bTime = shot_time % 210 end

	if(shot_time < 120)then Boss.setSerifBox(Boss.getX(),Boss.getY()-250,1,"零れ散るも尊く") end
	if(bTime==0)then
		Boss.Motion(0)
		Boss.charge()
		move_rand(FMIN_X + 100, 180, FMAX_X - FMIN_X - 100, 500, 80, 60)
	end

	if(bTime==30)then boss_SE(KIRAN)
		Boss.Motion(1)
		bx,by=Param2(Boss.getX()-50, Boss.getY()-100)
		et_s.rota(true)
		et_s.bound(true)
		et_s.size(2.5)
		et_s.noDelete(true)
		et_s.ringAt(bx,by, diff(7,9,11,0), 0, IMG.PETAL, CL.RED, 5, rd_h.toPlayer(bx,by), 0)
	end

	for bl_num = 0 , SHOT_MAX do TransS(bl_num) end --ステータス変更
end

function TransS(bl_num)
	if (Shot.isFlag(bl_num)) then
		if(Shot.getBoundCount(bl_num)>=1)then
			Shot.setBoundCount(0)
			Shot.isNotBound()
			if(Shot.getBoundArea(bl_num)==4)then Shot.clear() end
			if(Shot.getBoundArea(bl_num)==1 or Shot.getBoundArea(bl_num)==2)then boss_SE(KIRAN)
				angle = rd_h.toPlayer(Shot.getX(bl_num),Shot.getY(bl_num))
				et_s.rota(true)
				et_s.shine(true)
				et_s.ringAt(Shot.getX(bl_num),Shot.getY(bl_num), diff(18,20,24,0), 10, IMG.PETAL, CL.BLUE, 4, angle, 0)
			end
		end
	end
end

--@EndScript