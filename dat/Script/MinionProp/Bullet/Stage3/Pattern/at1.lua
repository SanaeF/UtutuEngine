
function Bullet1(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())
	if(time < 180 and time%diff(12,6,3,0)==0)then se_play(KIRAN)
		Shot.Create(ex, ey, type, color, 2+rand(1), rand(PI), 1)
		Shot.isShine()
	end
end
function Trans1(bl_num)
	return
end

--@EndScript