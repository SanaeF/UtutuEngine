--ホーミング3way
function Bullet2(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())
	if(time%30==5)then se_play(KIRAN)
		angle = homing(ex, ey, px, py)
		et_s.size(0.6)
		et_s.shine(true)
		et_s.nwayAt(ex, ey, 3, 7, 0, type, color, 10, 2.5, PI/6, angle, 2)
	end
end
function Trans2(bl_num)
	return
end

--@EndScript