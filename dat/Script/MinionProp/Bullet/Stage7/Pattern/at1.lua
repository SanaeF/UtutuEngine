--‰~Œ`’e
function Bullet1(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())
	if (time%50==20)then se_play(BULLET01)
		angle = homing(ex, ey, px, py)
		et_s.ringAt(ex, ey, 25, 0, type, color, 8, angle, 1)
	end
end
function Trans1(bl_num)
	return
end

--@EndScript