dofile( './dat/Script/Library/Timeline/TimelineSc.lua' )
dofile('./dat/Script/Timeline/ItemMinion/ItemMinion.lua')
dofile( './dat/Script/MinionProp/Bullet/Stage5/MinionBullet.lua' )
dofile( './dat/Script/MinionProp/Move/Stage5/MinionMover.lua' )

resetTime(4000)

function TimeLine()
	if (isTime(60))then 
		--TL.setEnding() 
	end
	if (isTime(90))then TL.setSubTitle() end

	--â~å`éGãõìG
	if (isTime(380))then 
		for ite=0,8 do
			angle=PI2/8*ite;
			ex=x_dt(F_HALF_X, angle, 20)
			ey=y_dt(F_HALF_Y, angle, 20)
			en_spawn(ex, ey, FIRE_FEARY, 270, 0, 0)
			en_bullet(IMG.RICE, CL.YELLOW)
			en_item(PowerGhost, 1)
			Minion.setAngle(angle)
		end
	end
	if (isTime(780))then 
		for ite=0,8 do
			angle=PI2/8*ite;
			ex=x_dt(F_HALF_X, angle, 20)
			ey=y_dt(F_HALF_Y, angle, 20)
			en_spawn(ex, ey, FIRE_FEARY, 270, 0, 1)
			en_bullet(IMG.RICE, CL.GREEN)
			en_item(PowerGhost, 1)
			Minion.setAngle(angle)
		end
	end

	--ÉâÉìÉ_ÉÄ
	if (isTime(1150) or
		isTime(1200) or
		isTime(1250))then 
		en_spawn(F_HALF_X+rand(F_HALF_X), 0, FIRE_FEARY, 170, 1, 2)
		en_bullet(IMG.OVERLAP, CL.PURPLE)
		en_item(PowerGhost, 1)
	end
	if (isTime(1300) or
		isTime(1350) or
		isTime(1400))then 
		en_spawn(F_HALF_X+rand(F_HALF_X), 0, FIRE_FEARY, 170, 1, 2)
		en_bullet(IMG.OVERLAP, CL.CYAN)
		en_item(PowerGhost, 1)
	end
	if (isTime(1450) or
		isTime(1500) or
		isTime(1550))then 
		en_spawn(F_HALF_X+rand(F_HALF_X), 0, FIRE_FEARY, 170, 1, 2)
		en_bullet(IMG.OVERLAP, CL.BLUE)
		en_item(PowerGhost, 1)
	end

	--â~å`éGãõìG
	if (isTime(1900))then 
		for ite=0,8 do
			angle=PI2/8*ite;
			ex=x_dt(F_HALF_X, angle, 20)
			ey=y_dt(F_HALF_Y, angle, 20)
			en_spawn(ex+300, ey-200, FIRE_FEARY, 70, 0, 1)
			en_bullet(IMG.RICE, CL.PINK)
			en_item(PowerGhost, 1)
			Minion.setAngle(angle)
			en_spawn(ex-300, ey-200, FIRE_FEARY, 70, 0, 0)
			en_bullet(IMG.RICE, CL.PINK)
			en_item(PowerGhost, 1)
			Minion.setAngle(angle)
		end
	end
	--â~å`éGãõìG
	if (isTime(2300))then 
		for ite=0,8 do
			angle=PI2/8*ite;
			ex=x_dt(F_HALF_X, angle, 20)
			ey=y_dt(F_HALF_Y, angle, 20)
			en_spawn(ex+200, ey-400, FIRE_FEARY, 70, 0, 0)
			en_bullet(IMG.RICE, CL.RED)
			en_item(PowerGhost, 1)
			Minion.setAngle(angle)
			en_spawn(ex-200, ey-400, FIRE_FEARY, 70, 0, 1)
			en_bullet(IMG.RICE, CL.RED)
			en_item(PowerGhost, 1)
			Minion.setAngle(angle)
		end
	end
	--â~å`éGãõìG
	if (isTime(2680))then 
		for ite=0,8 do
			angle=PI2/8*ite;
			ex=x_dt(F_HALF_X, angle, 20)
			ey=y_dt(F_HALF_Y, angle, 20)
			en_spawn(ex+100, ey-300, FIRE_FEARY, 90, 0, 0)
			en_bullet(IMG.PETAL, CL.PINK)
			en_item(PowerGhost, 1)
			Minion.setAngle(angle)
			en_spawn(ex-100, ey-300, FIRE_FEARY, 90, 0, 1)
			en_bullet(IMG.PETAL, CL.PINK)
			en_item(PowerGhost, 1)
			Minion.setAngle(angle)
		end
	end
	enter_boss_time=3160
	if (isTime(enter_boss_time))then TL.setTalkScene(13) end
	if (isTime(enter_boss_time+60))then 
		if not(IS_ALICE_MODE)then TL.setEnding() 
		else TL.setTalkScene(14) end
	end
	if (IS_ALICE_MODE and isTime(enter_boss_time+80))then TL.endStage() end
	--ìπíÜÇÃãììÆÇ∆ì¡éÍââèo
	for i=0,MINION_MAX do
		if(Minion.isFlag(i))then
			MinionBulletUpdate(i)
			MinionMoveUpdate(i)
		end
	end
	MinionBulletTrans()--íeñãÇÃïœâª
	ItemMinion()--ÉAÉCÉeÉÄballoonÇÃè¢ä´
end

--@EndScript