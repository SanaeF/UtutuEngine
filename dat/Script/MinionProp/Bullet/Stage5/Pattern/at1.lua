
function Bullet1(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())

	if (time==60)then se_play(BULLET01)
		angle = homing(ex, ey, px, py)
		et_s.ringAt(ex, ey, diff(9,15,27,0), 0, type, color, sp_(5,7,9,0), angle, 1)
	end
	if (time<120 and time%diff(25, 18, 10, 0)==0)then se_play(BULLET01)
		Shot.Create(ex, ey, type, color, Minion.getSpeed(id)+3+rand(2), Minion.getAngle(id)+rand(PI/15), 1)
		Shot.setState2(1)
		Shot.Create(ex, ey, type, color, Minion.getSpeed(id)+3+rand(2), Minion.getAngle(id)+PI/5+rand(PI/15), 1)
		Shot.setState2(1)
		Shot.Create(ex, ey, type, color, Minion.getSpeed(id)+3+rand(2), Minion.getAngle(id)-PI/5+rand(PI/15), 1)
		Shot.setState2(1)
	end
end
function Trans1(bl_num)
	if(Shot.getState2(bl_num)==1)then
		if(between(Shot.getCount(bl_num),60,70))then Shot.addSpeed(-2/10) end
	end
end

--@EndScript