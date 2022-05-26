
function Bullet0(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())

	if (time == diff(120, 60, 30, 0))then se_play(BULLET01)
		angle = homing(ex, ey, px, py)
		num_way=diff(1, 1, 3, 0)
		et_s.ringAt(ex, ey, diff(0, 6, 26, 0), 0, type ,color, sp_(0, 3, 11, 0), angle, 0)
		et_s.nwayAt(ex, ey, num_way, diff(1, 4, 7, 0), 0, type, color, sp_(4, 4, 3, 0), 1, PI/42, angle, 0)
	end
end
function Trans0(bl_num)
	return
end
--@EndScript