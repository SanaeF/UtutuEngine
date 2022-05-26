function Bullet0(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())

	num=diff(1,3,5,0)
	if(between(time,20,60))then
		et_s.nwayAt(ex, ey, num, 1, 160-2*(time-20), type, color, sp_(4,6,8,0)+4/(time-20), 0, PI/5, -PI/2+PI/30*(time-20), 0)
	end
end
function Trans0(bl_num)
	if(Shot.getCount(bl_num)<30)then
		Shot.addAngle(PI/3/30)
	end
end
--@EndScript