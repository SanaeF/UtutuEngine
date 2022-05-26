
function Bullet0(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())

	if (time == 50)then se_play(BULLET01)
		angle = homing(ex, ey, px, py)
		et_s.ringAt(ex, ey, diff(5, 10, 26, 0), 0, IMG.BIG, color, 10, angle, 0)
	end
	num = diff(8, 7, 2, 0)
	if (between(time,40, 140) and time % num == 0)then se_play(KIRAN)
		angle = PI/17 * (time/num)
		et_s.rota(true)
		et_s.ringAt(ex, ey, 3, 0, type ,color, 1, angle, 3)
	end
end
function Trans0(bl_num)
	time = Shot.getCount(bl_num)
	if(between(time,10, 30))then Shot.addSpeed(-7/20) end
end
--@EndScript