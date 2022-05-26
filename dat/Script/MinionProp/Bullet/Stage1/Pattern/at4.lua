
function Bullet4(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())

	if (between(time,10, 30) and time % 5 == 0)then se_play(BULLET01)
		num = diff(5, 7, 10, 0)
		angle = homing(ex, ey, px, py)
		et_s.shine(true)
		et_s.state2(0)
		et_s.ringAt(ex, ey, num, 0, type, color, sp_(10,11,12,0), angle, 4)
		et_s.shine(true)
		et_s.state2(1)
		et_s.ringAt(ex, ey, num, 0, type, color, sp_(10,11,12,0), angle, 4)
	end
end

function Trans4(bl_num)
	if(Shot.getCount(bl_num)>10)then 
		Shot.setSpeed(4)
		if(Shot.getState2(bl_num) == 0)then Shot.addAngle(PI/12/60) end
		if(Shot.getState2(bl_num) == 1)then Shot.addAngle(-PI/12/60) end
	end
end

--@EndScript