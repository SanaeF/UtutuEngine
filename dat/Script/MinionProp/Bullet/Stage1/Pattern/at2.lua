
function Bullet2(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())

	if (between(time,70, 450) and time % diff(10, 9, 8, 0) == 0)then se_play(BULLET01)
		angle = Minion.getAngle(id)+rand(PI/3)
		num_way=diff(1, 2, 3, 0)
		et_s.nwayAt(ex, ey, num_way, diff(3, 3, 4, 0), 0, type, color, sp_(2, 3, 3, 0), 1, PI/38, angle, 2)
	end
end
function Trans2(bl_num)
	return
end
--@EndScript