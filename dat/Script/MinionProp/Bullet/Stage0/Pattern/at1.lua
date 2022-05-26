
function Bullet1(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	per=diff(54, 27, 13, 0)
	if (between(time,51,600) and time % per == 0)then se_play(BULLET01)
		angle= PI / 14 * (time / per)
		et_s.ringAt(ex, ey, diff(6, 8, 17, 0), 0, type ,color, sp_(5, 6, 9, 0), angle, 1)
		et_s.ringAt(ex, ey, diff(6, 8, 17, 0), 0, type ,color, sp_(5, 6, 9, 0), -angle, 1)
	end
end
function Trans1(bl_num)
	return
end
--@EndScript