dofile( './dat/Script/MinionProp/Bullet/Library.lua' )

function Bullet()
	time = Enemy.getCount()
	type = Enemy.getBulletType()
	color = Enemy.getBulletColor()
	who = Enemy.getWho()
	ex, ey = Param2(Enemy.getX(), Enemy.getY())
	px, py = Param2(Player.getX_who(who), Player.getY_who(who))
end

Bullet()