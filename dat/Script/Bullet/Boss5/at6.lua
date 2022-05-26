dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(3)
	Boss.set(Time(60), HP(6000))
end

function BossShot()
	bTime = shot_time % 280

	if(shot_time < 120)then Boss.setSerifBox(Boss.getX(),Boss.getY()-250,1,"体力キツイなぁ・・・") end
	if(shot_time == 1)then
		Boss.charge()
		Boss.Motion(1)
	end
	per=diff(78,62,56,0)
	if(bTime%per == 0)then boss_SE(BULLET02)
		num=diff(14,16,18,0)
		et_s.rota(true)
		et_s.size(1.5)
		et_s.ring(num, 0, IMG.APPLE, 0, 4, rd_h.Boss_Player(), 0)
		et_s.shine(true)
		et_s.size(2)
		et_s.ring(num*2, 0, IMG.PETAL, CL.GREEN, 4, rd_h.Boss_Player()+rand(PI/3), 0)
	end
end

--@EndScript