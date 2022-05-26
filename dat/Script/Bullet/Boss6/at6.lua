dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.set(Time(99), HP(13000))
end

function BossShot()
	bTime = shot_time % 270
	if(shot_time==0)then InitPhase1() end
	if(shot_time%90==0)then boss_SE(BULLET02)
		bx,by=Param2(Boss.getX()-60, Boss.getY()-100)
		et_s.ringAt(bx,by, 27, 0, IMG.TRAMP, CL.GREEN, 7, rd_h.toPlayer(bx,by), 0)
	end
	if(Boss.getTime()==42)then--位置移動
		move((FMAX_X - FMIN_X) / 2, (FMAX_Y - FMIN_Y) / 2, 40)
	end
	if(Boss.getTime()>42)then
		Boss.setHP(13000)
	end
	if(Boss.getTime()<42)then
		bx,by=Param2(Boss.getX()-60, Boss.getY()-100)
		if(shot_time%180==65)then boss_SE(LAZER01)
			et_lc.ringAt(bx,by,12, 0, 80, CL.RED, 7, rd_h.toPlayer(bx,by), 0)
			et_lc.ringAt(bx,by,12, 0, 80, CL.RED, 7, rd_h.toPlayer(bx,by), 1)
		end
		if(shot_time%90==45)then boss_SE(BULLET02)
			et_s.ringAt(bx,by, 27, 0, IMG.TRAMP, CL.GREEN, 7, rd_h.toPlayer(bx,by), 0)
		end
	end
	if(Boss.getTime()<20)then
		if(shot_time%60==0)then boss_SE(BULLET02)
			bx,by=Param2(Boss.getX()-60, Boss.getY()-100)
			et_s.ringAt(bx,by, 15, 0, IMG.NORMAL, CL.ORANGE, 8, rd_h.toPlayer(bx,by), 0)
		end
	end
	for e_num = 0 , MINION_MAX do TransE(e_num) end
	for lc_num = 0 , T_LAZ_MAX do TransLc(lc_num) end
	for bl_num = 0 , SHOT_MAX do TransS(bl_num) end --ステータス変更
end

function InitPhase1()
	move_y=650
	move_time=60
	boss_SE(GYUUUUUUN)
	en_spawn(Boss.getX(), Boss.getY(), TRAMP_MATSU, 4000, 0, 0)
	en_item(PowerGhost, 5)
	Minion.setMove(120,move_y,move_time)
	en_spawn(Boss.getX(), Boss.getY(), TRAMP_FEATORIA, 4000, 0, 0)
	en_item(PowerGhost, 5)
	Minion.setMove(F_MAX_X-120,move_y,move_time)
end

function TransE(e_num)
	if(Minion.isFlag(e_num))then
		if(Minion.getCount(e_num)==0)then boss_SE(CHARGE) end
		if(Minion.getCount(e_num)>70)then 
			ex,ey=Param2(Minion.getX(e_num),Minion.getY(e_num))
			if(Minion.getType(e_num)==TRAMP_MATSU)then
				Minion.kill()
				boss_spawn(Minion.searchID(),ex,ey,N03_MATUMI,5000,BomPeace)
				Minion.setNoUI(true)
			end
			if(Minion.getType(e_num)==TRAMP_FEATORIA)then
				Minion.kill()
				boss_spawn(Minion.searchID(),ex,ey,N07_FEATORIA,5000,BomPeace)
				Minion.setNoUI(true)
			end
			if(Boss.getTime()>42)then
				Minion.setLastHP(5000)
			end
			if(between(Boss.getTime(),80,99))then --phase1
				if(Minion.getType(e_num)==N03_MATUMI)then
					ShotPhase1(e_num,0)
				end
				if(Minion.getType(e_num)==N07_FEATORIA)then
					ShotPhase1(e_num,1)
				end
			end
			if(Boss.getTime()==77)then--位置入れ替え
				Minion.setMotion(0)
				move_y=650
				move_time=80
				if(Minion.getType(e_num)==N03_MATUMI)then
					Minion.setMove(F_MAX_X-120,move_y,move_time)
				end
				if(Minion.getType(e_num)==N07_FEATORIA)then
					Minion.setMove(120,move_y,move_time)
				end
			end
			if(between(Boss.getTime(),45,75))then --phase1
				if(Minion.getType(e_num)==N03_MATUMI)then
					ShotPhase2(e_num,IMG.AMMO)
				end
				if(Minion.getType(e_num)==N07_FEATORIA)then
					ShotPhase2(e_num,IMG.MEGA)
				end
			end
			if(Boss.getTime()==42)then--位置移動
				Minion.setNoUI(false)
				Minion.setMotion(0)
				if(Minion.getType(e_num)==N03_MATUMI)then
					Minion.setMove(F_HALF_X,400+150,move_time)
				end
				if(Minion.getType(e_num)==N07_FEATORIA)then
					Minion.setMove(F_HALF_X,400-50,move_time)
				end
			end
			if(between(Boss.getTime(),0,40))then --phase1
				if(Minion.getType(e_num)==N03_MATUMI)then
					ShotPhase3(e_num,IMG.AMMO)
				end
				if(Minion.getType(e_num)==N07_FEATORIA)then
					ShotPhase3(e_num,IMG.MEGA)
				end
			end
		end
	end
end

function ShotPhase1(e_num,state)
	per=160
	if(state==0)then st1,st2=Param2(0,1)end
	if(state==1)then st1,st2=Param2(1,0)end
	if(shot_time%per==0)then boss_SE(LAZER01)
		Minion.setMotion(1)
		sx,sy=Param2(Minion.getX(e_num), Minion.getY(e_num))
		et_lc.ringAt(sx,sy,16, 0, 80, CL.ORANGE, 7, rd_h.toPlayer(sx,sy), st1)
	end
	if(shot_time%per==40)then Minion.setMotion(0) end
	if(shot_time%per==80)then boss_SE(LAZER01)
		Minion.setMotion(1)
		sx,sy=Param2(Minion.getX(e_num), Minion.getY(e_num))
		et_lc.ringAt(sx,sy,16, 0, 70, CL.BLUE, 7, rd_h.toPlayer(sx,sy), st2)
	end
	if(shot_time%per==120)then Minion.setMotion(0) end
end

function ShotPhase2(e_num,type)
	if(shot_time%80==0)then boss_SE(BULLET02)
		Minion.setMotion(1)
		sx,sy=Param2(Minion.getX(e_num), Minion.getY(e_num))
		angle=rand(PI/25)
		if(type==IMG.MEGA)then et_s.size(0.6) end
		if(type==IMG.AMMO)then et_s.size(1.4) end
		et_s.ringAt(sx,sy,18,0,type,CL.PINK,5,angle,1)
		if(type==IMG.MEGA)then et_s.size(0.6) end
		if(type==IMG.AMMO)then et_s.size(1.4) end
		et_s.ringAt(sx,sy,18,0,type,CL.PINK,5,angle,2)
	end
end

function ShotPhase3(e_num,type)
	if(shot_time%160==0)then
		Minion.setRandMove(100, 180, F_MAX_X - 100, 500, 80, 60)
		Minion.setMotion(0)
	end
	if(shot_time%160==100)then boss_SE(BULLET02)
		Minion.setMotion(1)
		sx,sy=Param2(Minion.getX(e_num), Minion.getY(e_num))
		angle=rand(PI/25)
		if(type==IMG.MEGA)then et_s.size(0.6) end
		if(type==IMG.AMMO)then et_s.size(1.4) end
		et_s.ringAt(sx,sy,18,0,type,CL.PINK,5,angle,1)
		if(type==IMG.MEGA)then et_s.size(0.6) end
		if(type==IMG.AMMO)then et_s.size(1.4) end
		et_s.ringAt(sx,sy,18,0,type,CL.PINK,5,angle,2)
	end
end

function TransLc(lc_num)
	if(LazCr.isFlag(lc_num))then
		if(LazCr.getCount(lc_num)<240)then
			if(LazCr.getState1(lc_num)==0)then
				LazCr.addAngle(-PI/240)
			end
			if(LazCr.getState1(lc_num)==1)then
				LazCr.addAngle(PI/240)
			end
		end
	end
end

function TransS(bl_num)
	if (Shot.isFlag(bl_num)) then
		if(Shot.getState1(bl_num)==1)then Shot.addAngle(PI/2/250) end
		if(Shot.getState1(bl_num)==2)then Shot.addAngle(-PI/2/250) end
	end
end
--@EndScript