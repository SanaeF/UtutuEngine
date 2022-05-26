function Bullet0(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())

	if (time%diff(25, 20, 10, 0)==0)then se_play(BULLET01)
		angle = Minion.getAngle(id)+PI
		num_way=diff(3, 3, 4, 0)
		et_s.nwayAt(ex, ey, num_way, 1, 0, type, color, sp_(4, 5, 7, 0), 0, PI/62, angle, 0)
	end

end
function Trans0(bl_num)
	return
end
--@EndScript