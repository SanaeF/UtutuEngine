dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.set(Time(60), HP(9000))
end

function BossShot()
	bTime = shot_time % 300

	if(shot_time < 100)then Boss.setSerifBox(Boss.getX(),Boss.getY()-250,1,"H‚×‚â‚·‚¢‚æ‚¤‚Éô") end
	if(bTime==0)then
		Boss.Motion(0)
		Boss.charge()
	end

	sp=4
	if(bTime%60==0)then boss_SE(BULLET02)
		Boss.Motion(1)
		bx,by=Param2(Boss.getX()-50, Boss.getY()-100)
		num=diff(48,52,56,0)
		et_l.rota_angle(PI/5)
		et_l.size(100, 15)
		et_l.collision(true)
		et_l.noDelete(true)
		et_l.ringAt(bx, by, num, 0, IMG.NORMAL, CL.CYAN, sp, rd_h.toPlayer(bx,by), 1)
		et_l.rota_angle(-PI/5)
		et_l.size(100, 15)
		et_l.collision(true)
		et_l.noDelete(true)
		et_l.ringAt(bx, by, num, 0, IMG.NORMAL, CL.CYAN, sp, rd_h.toPlayer(bx,by), 2)
	end

	per=diff(56,42,37,0)
	if(bTime%per == 0)then
		num=diff(5,6,8,0)
		if(Boss.getHP()<3500)then num=num+4 end
		et_s.rota(true)
		et_s.size(1.5)
		et_s.ring(num, 0, IMG.APPLE, 0, 4, rd_h.Boss_Player()+rand(PI/3), 2)
	end

	for l_num = 0 , LAZER_MAX do TransL(l_num) end
end

function TransL(l_num)
	if (Lazer.isFlag(l_num)) then
		if(Lazer.getState1(l_num)==1)then 
			Lazer.setRota(10,40,-PI/5)
			Lazer.setRota(50,80,PI/5)
			if(Lazer.getCount(l_num)==90)then Lazer.setCount(10) end
		end
		if(Lazer.getState1(l_num)==2)then 
			Lazer.setRota(10,40,PI/5)
			Lazer.setRota(50,80,-PI/5)
			if(Lazer.getCount(l_num)==90)then Lazer.setCount(10) end
		end
	end
end

--@EndScript