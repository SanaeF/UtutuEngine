dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.set(Time(100), HP(9000))
end

function BossShot()
	bTime = shot_time % 600

	if(shot_time < 100)then Boss.setSerifBox(Boss.getX(),Boss.getY()-250,1,"こんなに大きく育ったよ!") end
	if(bTime%120 == 0)then
		Boss.Motion(0)
		Boss.charge()
		move_rand(FMIN_X + 100, 180, FMAX_X - FMIN_X - 100, 500, 80, 60)
	end
	if(bTime==30)then boss_SE(LAZER01)
		Boss.Motion(1)
		set_top(CL.PINK,200,1)
		set_top(CL.PINK,200,2)
		if(diff(false,true,true,0))then set_top(CL.GREEN,400,3) end
		if(diff(false,true,true,0))then set_top(CL.GREEN,400,4) end

		set_right(CL.BLUE,200,1)
		set_right(CL.BLUE,200,2)

		set_left(CL.BLUE,200,1)
		set_left(CL.BLUE,200,2)
	end

	per=diff(20,18,12,0)
	if(bTime>80 and bTime%per == 0)then boss_SE(BULLET01)
		sp = sp_(5,6,8,0)
		et_s.rota(true)
		et_s.shine(true)
		et_s.size(1.5+rand(0.8))
		et_s.ringAt(Boss.getX()-50, Boss.getY()-100, 2, 0, IMG.PETAL, CL.PINK, sp-1, PI/48*(bTime/12), 0)
		et_s.rota(true)
		et_s.size(1.5+rand(0.8))
		et_s.ringAt(Boss.getX()-50, Boss.getY()-100, 2, 0, IMG.PETAL, CL.PURPLE, sp, PI/2+PI/48*(bTime/12)+rand(PI/12), 1)
	end

	if(Boss.getHP()<4000)then
		if(bTime>80 and bTime%per == 0)then boss_SE(BULLET01)
			sp = sp_(5,6,8,0)
			et_s.rota(true)
			et_s.shine(true)
			et_s.size(1.2+rand(0.7))
			et_s.ringAt(Boss.getX()-50, Boss.getY()-100, 2, 0, IMG.PETAL, CL.PINK, sp-1, -PI/48*(bTime/12), 0)
			et_s.rota(true)
			et_s.size(1.2+rand(0.7))
			et_s.ringAt(Boss.getX()-50, Boss.getY()-100, 2, 0, IMG.PETAL, CL.PURPLE, sp, PI/2-PI/48*(bTime/12)+rand(PI/12), 1)
		end
	end

	for bl_num = 0 , SHOT_MAX do TransS(bl_num) end --ステータス変更
	for lc_num = 0 , T_LAZ_MAX do TransLc(lc_num) end --ステータス変更
end

function set_top(color,dist,state)
	px = Player.getX()+rand(dist)
	if(px < 0)then px = px+dist end
	LazCr.Create(px,0, 250, color, 5, PI/2+PI/4, state)--上方向
end

function set_right(color,dist,state)
	py = Player.getY()+rand(dist)
	if(py < 0)then py = py+dist end
	LazCr.Create(F_MAX_X,py, 250, color, 6, PI+PI/4, state)--上方向
end

function set_left(color,dist,state)
	py = Player.getY()+rand(dist)
	if(py < 0)then py = py+dist end
	LazCr.Create(0,py, 250, color, 6, 0+PI/4, state)--上方向
end

function TransS(bl_num)
	if (Shot.isFlag(bl_num)) then
		if(Shot.getState1(bl_num)==1)then
			if(between(Shot.getCount(bl_num),60,120))then Shot.addSpeed(-(sp_(5,6,8,0)-2)/60) end
		end
	end
end

function TransLc(lc_num)
	if(LazCr.isFlag(lc_num))then
		if(LazCr.getState1(lc_num)==1)then deltaC(lc_num,200,PI/2/70) end
		if(LazCr.getState1(lc_num)==2)then deltaC(lc_num,200,-PI/2/70) end
		if(LazCr.getState1(lc_num)==3)then deltaC(lc_num,200,PI/2/90) end
		if(LazCr.getState1(lc_num)==4)then deltaC(lc_num,200,-PI/2/90) end
		if(LazCr.getCount(lc_num)%10==4)then LazCr.addAngle(-PI/2) end
		if(LazCr.getCount(lc_num)%10==9)then LazCr.addAngle(PI/2) end
	end
end

function deltaC(lc_num,time_dist,rd)
	if(between(LazCr.getCount(lc_num),0,time_dist/2))then LazCr.addAngle(-rd/2) end
	if(between(LazCr.getCount(lc_num)%time_dist,0,time_dist/2))then LazCr.addAngle(rd) end
	if(between(LazCr.getCount(lc_num)%time_dist,time_dist/2,time_dist))then LazCr.addAngle(-rd) end
end

--@EndScript