
function Bullet3(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())
	
	per=diff(8, 4, 2, 0)
	if (between(time,60, 450) and time % per == 0)then se_play(BULLET01)
		angle = PI/diff(57, 67, 74, 0) * (time-60)
		et_s.shine(true)
		et_s.nwayAt(ex-120, ey, 3, diff(3, 3, 4, 0), 0, type, color, sp_(3, 4, 5, 0), 0.3, PI/3, PI/2+angle, 3)
		et_s.shine(true)
		et_s.nwayAt(ex+120, ey, 3, diff(3, 3, 4, 0), 0, type, color, sp_(3, 4, 5, 0), 0.3, PI/3, -PI/2-angle, 3)
	end
end

function Trans3(bl_num)
	return
end

--@EndScript