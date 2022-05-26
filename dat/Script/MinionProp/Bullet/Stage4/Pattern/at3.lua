
function Bullet3(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())

	if(time%50==20)then
		angle = homing(ex, ey, px, py)
		et_s.state2(0)
		et_s.shine(true)
		way=diff(3,5,7,0)
		et_s.nwayAt(ex, ey, way, 1, 0, type, color,sp_(5,6,9,0), 0, PI/(way*2), angle, 3)
	end
end
function Trans3(bl_num)
	return
end

--@EndScript