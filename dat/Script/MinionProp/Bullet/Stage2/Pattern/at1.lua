
function Bullet1(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())

	if(between(time, 40, 180) and time % diff(32, 30, 25, 0) == 1)then se_play(KIRAN)
		angle = homing(ex, ey, px, py)
		et_l.standType(type)
		et_l.size(250, 15)
		et_l.collision(true)
		et_l.ringAt(ex, ey, diff(6, 10, 12, 0), 60, type, color, -sp_(3,4,6,0), PI + angle, 1)
	end
end
function Trans1(bl_num)
	return;
end

--@EndScript