
function Bullet1(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())

	num = diff(30, 26, 18, 0)
	if (between(time,60, 140) and time % num == 0)then se_play(BULLET01)
		angle = homing(ex, ey, px, py)
		et_s.shine(true)
		et_s.ringAt(ex, ey, 3, 0, type ,color, sp_(5,7,12,0), angle, 1)
	end
end
function Trans1(bl_num)
	return
end
--@EndScripts