dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.noDamage(false)
	Boss.set(Time(80), HP(25000))
end

function BossShot()
	bTime = shot_time % 280

	if(shot_time==1)then
		Boss.Motion(1)
		setRose()
	end
	if(Boss.getTime()<50 or Boss.getHP()<13000)then 
		if(bTime==0)then boss_SE(BULLET01)
			num=diff(5,7,9,0)
			bx,by=Param2(Boss.getX()-50, Boss.getY()-100)
			et_s.shine(true)
			et_s.noDelete(true)
			et_s.ringAt(bx, by, num, 0, IMG.MEGA, CL.BLUE, 7, rd_h.toPlayer(bx,by), 3)
			et_lc.ringAt(bx, by, num, 0, 100, CL.SKY, 5, rd_h.toPlayer(bx,by)+PI/6, 0)
		end
	end
	if(Boss.getTime()<30 or Boss.getHP()<7000)then 
		if(bTime==140)then boss_SE(BULLET01)
			num=diff(13,20,25,0)
			bx,by=Param2(Boss.getX()-50, Boss.getY()-100)
			et_s.shine(true)
			et_s.noDelete(true)
			et_s.ringAt(bx, by, num, 0, IMG.MEGA, CL.GREEN, 7, rd_h.toPlayer(bx,by), 3)
		end
	end

	for l_num = 0 , LAZER_MAX do TransL(l_num) end --ステータス変更
	for lc_num = 0 , T_LAZ_MAX do TransLc(lc_num) end --ステータス変更
	for bl_num = 0 , SHOT_MAX do TransS(bl_num) end --ステータス変更
end

function setRose()
	boss_SE(KIRAN)
	petal_num=6
	for ite=0,petal_num do
		et_l.rota_angle(PI2/petal_num*ite)
		et_l.size(150, 30)
		et_l.collision(true)
		et_l.noDelete(true)
		et_l.numInState2(true)
		et_l.ring(4, 0, IMG.PETAL, CL.PINK, 7, PI/4, 1)
	end
end

function TransL(l_num)
	if (Lazer.isFlag(l_num)) then
		if(Lazer.getState1(l_num)==1)then 
			if(shot_time==70)then Lazer.setSpeed(0) end
			st2=Lazer.getState2(l_num)
			if(st2==1 or st2==2)then Lazer.setLengthAngle(Lazer.getLengthAngle(l_num)+PI/128) end
			if(st2==3 or st2==4)then Lazer.setLengthAngle(Lazer.getLengthAngle(l_num)-PI/128) end
			if(shot_time>=80 and shot_time%240==0)then
				st2=Lazer.getState2(l_num)
				nway= 3
				angle_way=diff(PI/(nway*8),PI/(nway*7),PI/(nway*5),0)
				add_way=diff(0,1,1,0)
				lx,ly=Param2(Lazer.getX(l_num),Lazer.getY(l_num))
				if(st2==1 or st2==2)then boss_SE(KIRAN) 
					et_s.rota(true)
					et_s.shine(true)
					et_s.size(2)
					et_s.nwayAt(lx, ly, nway+add_way, 1, 0, IMG.PETAL, CL.ORANGE, 5, 0, angle_way, Lazer.getLengthAngle(l_num), 2)
					et_s.rota(true)
					et_s.nwayAt(lx, ly, nway*2, 1, 0, IMG.PETAL, CL.PURPLE, 3, 0, PI/(nway*4), Lazer.getLengthAngle(l_num), 2)
				end
				if(st2==3 or st2==4)then boss_SE(KIRAN) 
					et_s.rota(true)
					et_s.shine(true)
					et_s.size(2)
					et_s.nwayAt(lx, ly, nway+add_way, 1, 0, IMG.PETAL, CL.ORANGE, 5, 0, angle_way, Lazer.getLengthAngle(l_num), 1)
					et_s.rota(true)
					et_s.nwayAt(lx, ly, nway*2, 1, 0, IMG.PETAL, CL.PURPLE, 3, 0, PI/(nway*4), Lazer.getLengthAngle(l_num), 1)
				end
			end
		end
	end
end

function TransS(bl_num)
	if (Shot.isFlag(bl_num))then
		if(Shot.getCount(bl_num)<200)then
			if(Shot.getState1(bl_num)==1)then
				Shot.addAngle(PI/200)
			end
			if(Shot.getState1(bl_num)==2)then
				Shot.addAngle(-PI/200)
			end
		end
	end
end

function TransLc(lc_num)
	if(LazCr.isFlag(lc_num))then
		time_dist=50
		angle = rd_h.toPlayer(LazCr.getX(lc_num),LazCr.getY(lc_num))
		if(between(LazCr.getCount(lc_num),60,140))then
			if(LazCr.getCount(lc_num)%15==0)then LazCr.setAngle(angle) end
		end
		if(LazCr.getCount(lc_num)==140)then LazCr.addAngle(-PI/6) end
		if(LazCr.getCount(lc_num)%10==4)then LazCr.addAngle(-PI/3) end
		if(LazCr.getCount(lc_num)%10==9)then LazCr.addAngle(PI/3) end
	end
end

--@EndScript