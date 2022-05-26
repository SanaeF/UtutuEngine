dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.set(Time(99999), HP(30000))
end

function BossShot()
	bTime = shot_time % 280
	if(Boss.getHP()<23000)then 
		if(shot_time%120==0)then boss_SE(BULLET01)
			num=diff(5,6,7,0)
			et_s.rota(true)
			et_s.bound(true)
			et_s.ring(num, 0, IMG.APPLE, 0, 4, rd_h.Boss_Player(), 0)
		end
	end
	if(Boss.getHP()<15000)then 
		if(shot_time%120==60)then boss_SE(BULLET01)
			num=5
			et_s.shine(true)
			et_s.ringAt(Boss.getX()+200,Boss.getY(),num, 0, IMG.MEGA, CL.BLUE, 4, PI/2, 1)
			et_s.shine(true)
			et_s.ringAt(Boss.getX()-200,Boss.getY(),num, 0, IMG.MEGA, CL.BLUE, 4, PI/2, 2)
		end
	end
	if(Boss.getHP()<8000)then bTime = shot_time % 180 end

	if(bTime==0)then boss_SE(KIRAN)
		ringGroup(CL.PURLE,rd_h.set()+PI/90,3,200,1)
		ringGroup(CL.PURLE,rd_h.set(),3,200,1)
		ringGroup(CL.PURLE,rd_h.set()-PI/90,3,200,1)
	end
	if(bTime==45)then boss_SE(KIRAN)
		ringGroup(CL.SKY,rd_h.set()+PI/3+PI/90,3,400,2)
		ringGroup(CL.SKY,rd_h.set()+PI/3,3,400,2)
		ringGroup(CL.SKY,rd_h.set()+PI/3-PI/90,3,400,2)
	end

	for bl_num = 0 , SHOT_MAX do TransS(bl_num) end --ステータス変更
end

function ringGroup(color,angle,ring_num,dist,state)
	for ite=1,ring_num do
		num=diff(9,12,16,0)
		x = x_dt(Boss.getX(),PI2/ring_num*ite+angle,dist)
		y = y_dt(Boss.getY(),PI2/ring_num*ite+angle,dist)
		et_s.rota(true)
		et_s.ringAt(x,y,num, 0, IMG.PETAL, color, 4, rd_h.toBoss(x,y), state)
	end
end

function TransS(bl_num)
	if (Shot.isFlag(bl_num))then
		if(Shot.getCount(bl_num)<200)then
			if(Shot.getState1(bl_num)==1)then
				Shot.addAngle(PI/300)
			end
			if(Shot.getState1(bl_num)==2)then
				Shot.addAngle(-PI/300)
			end
		end
		if(Shot.getBoundCount(bl_num)==1)then Shot.isNotBound() end
		if(Shot.getBoundArea(bl_num)==3 or Shot.getBoundArea(bl_num)==4)then 
			Shot.setBoundArea(0)
			Shot.clear() 
		end
	end
end
--@EndScript