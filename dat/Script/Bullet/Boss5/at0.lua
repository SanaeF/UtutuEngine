dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.set(Time(45), HP(7000))
	Boss.Motion(0)
end

function BossShot()
	bTime = shot_time % 280

	if(shot_time < 70)then Boss.setSerifBox(Boss.getX(),Boss.getY()-250,1,"‚¨ˆê‚Â‚¢‚©‚ªH") end
	if(shot_time == 1)then
		Boss.charge()
		Boss.Motion(1)
	end
	per=diff(56,42,37,0)
	if(bTime%per == 0)then boss_SE(BULLET01)
		num=diff(8,12,16,0)
		et_s.rota(true)
		et_s.shine(true)
		if(Boss.getHP()<3500)then et_s.size(2)
		else et_s.size(1.5+rand(1)) end
		et_s.ring(num, 0, IMG.APPLE, 0, 4, rd_h.Boss_Player()+rand(PI/3), 2)
	end

end

--@EndScript