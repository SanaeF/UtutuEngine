
function Bullet4(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())
	if(time % 60==0)then se_play(BULLET01)
		num = diff(6, 8, 10, 0)
		angle = homing(ex, ey, px, py)+(PI/(num*2))
		et_s.state2(0)
		et_s.shine(true)
		et_s.ringAt(ex, ey, num, 80, type, color, sp_(3,4,6,0), angle, 4)
		et_s.state2(1)
		et_s.shine(true)
		et_s.ringAt(ex, ey,num, 80, type, color, sp_(3,4,6,0), angle, 4)
	end
end
function Trans4(bl_num)
	if(between(Shot.getCount(bl_num),20,200))then
		if(Shot.getState2(bl_num)==0)then Shot.addAngle(PI/3/180) end
		if(Shot.getState2(bl_num)==1)then Shot.addAngle(-PI/3/180) end
	end
end

--@EndScript