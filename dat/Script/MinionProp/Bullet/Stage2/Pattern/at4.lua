
function Bullet4(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())

	if(between(time, 30, 360) and time % diff(25, 18, 11, 0) == 1)then se_play(BULLET01)
		angle = homing(ex, ey, px, py)
		et_s.size(0.5)
		et_s.ringAt(ex, ey, diff(3, 3, 3, 0), 0, type, color, sp_(4,5,6,0), angle, 0)
	end
end
function Trans4(bl_num)
	return
end
--@EndScript