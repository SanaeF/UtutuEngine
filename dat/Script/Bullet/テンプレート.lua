dofile('./dat/Script/Bullet/Library.lua' )

Boss.cooldown_(4)
Boss.setLast()
Boss.set(Time(60), HP(1500))

function BossShot(bTime)

end

BossShot(shot_time)