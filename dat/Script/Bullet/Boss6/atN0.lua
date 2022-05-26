dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.set(Time(60), HP(1000))
end

function BossShot()
	bTime = shot_time % 280

end

--@EndScript