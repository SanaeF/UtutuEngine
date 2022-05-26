
function Bullet5(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())

	if(time > 40 and time % diff(26, 23, 11, 0) == 1)then se_play(BULLET01)
		angle = homing(ex, ey, px, py)+rand(PI/24)
		et_s.ringAt(ex, ey, diff(12, 13, 15, 0), 0, type, color, sp_(4,5,8,0), angle, 0)
	end
end

function Trans5(bl_num)
	if(Shot.getCount(bl_num) < 60)then Shot.addSpeed(0.1) end
end
--@EndScript