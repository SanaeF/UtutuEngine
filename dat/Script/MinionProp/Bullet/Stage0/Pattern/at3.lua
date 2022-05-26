
function Bullet3(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())
	num = diff(21, 13, 5, 0)
	if (time % num == 0)then se_play(BULLET01)
		angle = homing(ex, ey, px, py) + PI/17 * (time/num)
		et_s.ringAt(ex, ey, 4, 0, type ,color, 0, angle, 3)
	end
end
function Trans3(bl_num)
	if(Shot.getCount(bl_num) == 270)then
		Shot.setSpeed(diff(3, 4, 6, 0))
	end
end
--@EndScript