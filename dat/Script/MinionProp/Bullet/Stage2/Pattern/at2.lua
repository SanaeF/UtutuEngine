
function Bullet2(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())
	per=diff(25, 18, 12, 0)
	if(between(time, 40, 360) and time % per == 1)then se_play(KIRAN)
		angle = PI/32 * (time/per)
		et_l.standType(type)
		et_l.size(250, 15)
		et_l.collision(true)
		et_l.ringAt(ex, ey, diff(7, 10, 12, 0), 60, type, color, -sp_(5,7,11,0), PI + angle, 2)
	end
end
function Trans2(bl_num)
end
--@EndScript