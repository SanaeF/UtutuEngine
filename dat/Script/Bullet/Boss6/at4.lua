dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.set(Time(9999), HP(8000))
end

function BossShot()
	bTime = shot_time % 280
	if(bTime == 0)then
		Boss.mv_stay()
	end
	per=40
	sp=7
	if(Boss.getHP()<7000)then
		per=32
		sp=8
	end
	if(Boss.getHP()<5000)then
		per=18
		sp=10
	end
	if(Boss.getHP()<3000)then
		per=12
		sp=11
	end
	if(Boss.getHP()<2000)then
		per=8
		sp=12
	end
	if(bTime%per == 0)then boss_SE(BULLET02)
		et_s.ringAt(Boss.getX()-60, Boss.getY()-100, 27, 0, IMG.TRAMP, CL.RED, sp, PI/67*(shot_time/per), 0)
	end
end

--@EndScript