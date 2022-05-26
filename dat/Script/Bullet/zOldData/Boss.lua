dofile( './dat/Script/Bullet/Shotlib/Library.lua' )

--@Initialize
Boss.cooldown_(25)
Boss.setLast()
Boss.set(Time(30), HP(2500))
--@end

--@BulletLoop
for num = 0 , 10 do--{
	Shot.Create(Boss.get_x(), Boss.get_y(), 0, 6, 5, num * PI2 / 10, 0)
	Shot.isRota()
	Shot.isNotShine()
end
--}
--@end
function Initialize()

end

function BossShot(bTime)

end