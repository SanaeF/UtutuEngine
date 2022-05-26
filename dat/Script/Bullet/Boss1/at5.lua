dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.setLast()
	Boss.set(Time(59), HP(12600))
end

function BossShot()
	bTime = shot_time % 360

	if(shot_time < 100)then Boss.setSerifBox(Boss.getX(),Boss.getY()-250,1,"レッツツェ・エーフ!!") end
	if(shot_time == 1)then boss_SE(LAZER01)
		Boss.Motion(1)
		num = diff(12,12,24,0)
		et_l.standType(IMG.BIG)
		et_l.size(1, 1)
		et_l.ring(num, 250, IMG.CLOCK_LAZ, CL.CYAN, 0, PI/2+PI/(num*2), 1)
		et_l.standType(IMG.BIG)
		et_l.size(1, 1)
		et_l.ring(num, 250, IMG.CLOCK_LAZ, CL.CYAN, 0, PI/2-PI/(num*2), 2)
	end
	StarWave(bTime,40,CL.PINK)
	StarWave(bTime,140,CL.ORANGE)
	for l_num = 0 , LAZER_MAX do TransL(l_num, bTime) end
end

function StarWave(b_time,f_time,color)
	if(between(b_time, f_time, f_time + 60) and b_time % diff(25,17,15,0) == 0)then boss_SE(KIRAN)
		Boss.Motion(0)
		add_rd = PI/diff(68,56,43,0) * (b_time/12 - 40)
		et_s.rota(true)
		et_s.ring(diff(10,14,24,0), 0, IMG.BIG_STAR, color, sp_(7,7,9,0), add_rd, 0)
	end
	if(between(b_time, f_time+80, f_time+140) and b_time % diff(25,17,15,0) == 0)then boss_SE(KIRAN)
		Boss.Motion(0)
		add_rd = PI/diff(68,56,43,0) * (b_time/12 - 40)
		et_s.rota(true)
		et_s.ring(diff(10,14,24,0), 0, IMG.BIG_STAR, color, sp_(7,7,9,0), -add_rd, 0)
	end
end

function TransL(l_num, b_time)
	if (Lazer.isFlag(l_num)) then
		Lazer.isCollision()
		if (Lazer.getThick(l_num) < 20)then 
			Lazer.addThick(1)
			Lazer.addLength(10) 
		end
		max_add_l = 700
		max_add_t = 30
		if(Lazer.getState1(l_num) == 1)then 
			if (b_time == 100)then boss_SE(LAZER01) end
			if(between(b_time, 100, 160))then 
				Lazer.addThick(max_add_t/60)
				Lazer.addLength(max_add_l/60)
			end
			if(between(b_time, 160, 220))then 
				Lazer.addThick(-max_add_t/60)
				Lazer.addLength(-max_add_l/60)
			end
		end
		if(Lazer.getState1(l_num) == 2)then 
			if (b_time == 220)then boss_SE(LAZER01) end
			if(between(b_time, 220, 280))then 
				Lazer.addThick(max_add_t/60)
				Lazer.addLength(max_add_l/60)
			end
			if(between(b_time, 280, 340))then 
				Lazer.addThick(-max_add_t/60)
				Lazer.addLength(-max_add_l/60)
			end
		end
	end
end

--@EndScript