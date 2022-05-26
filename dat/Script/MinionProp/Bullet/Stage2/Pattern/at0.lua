
function Bullet0(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())

	if(between(time, 40, 120) and time % diff(25, 18, 11, 0) == 1)then se_play(BULLET01)
		angle = homing(ex, ey, px, py)+rand(PI/24)
		et_s.ringAt(ex, ey, diff(5, 6, 12, 0), 0, type, color, sp_(3,4,6,0), angle, 0)
	end
end

function Trans0(bl_num)
	if(Shot.getCount(bl_num) < 60)then Shot.addSpeed(0.1) end
end
--@EndScript