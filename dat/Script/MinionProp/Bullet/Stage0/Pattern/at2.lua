
function Bullet2(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())

	if (time == 30)then se_play(BULLET01)
		angle = homing(ex, ey, px, py)
		num_way = diff(5, 8, 11, 0)
		et_s.nwayAt(ex, ey, num_way, diff(2, 2, 3, 0), 0, type, color, sp_(5, 7, 12, 0), 1, PI/diff(12, 16, 23, 0), angle, 2)
	end
end

function Trans2(bl_num)
	if(Shot.getCount(bl_num) > 60)then Shot.setSpeed(diff(3, 4, 6, 0)) end
end

--@EndScript