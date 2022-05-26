
function Bullet2(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())

	if(time < 100 and time%80==20)then
		angle = homing(ex, ey, px, py)
		et_s.state2(0)
		et_s.shine(true)
		et_s.ringAt(ex, ey, diff(17,20,25,0), 0, type, color, 6, angle, 2)
		et_s.state2(1)
		et_s.shine(true)
		et_s.ringAt(ex, ey, diff(17,20,25,0), 0, type, color, 6, angle, 2)
	end
end
function Trans2(bl_num)
	if(Shot.getState2(bl_num)==0)then Shot.addAngle(PI/368) end
	if(Shot.getState2(bl_num)==1)then Shot.addAngle(-PI/368) end
end

--@EndScript