
function Bullet3(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())
	if(time==0)then se_play(BULLET01)
		num = diff(3, 5, 8, 0)
		angle = homing(ex, ey, px, py)
		for ite = 0, diff(5, 6, 8, 0)do
			et_s.state2(ite)
			et_s.shine(true)
			et_s.ringAt(ex, ey,num, 60, type, color, 0, angle, 3)
		end
		for ite = 0, diff(5, 6, 8, 0)do
			et_s.state2(ite)
			et_s.shine(true)
			et_s.ringAt(ex, ey, num, 60, type, color, 0, 0, 3)
		end
	end
end
function Trans3(bl_num)
	if(Shot.getCount(bl_num)==20)then se_play(KIRAN)
		Shot.setSpeed(diff(4, 5, 8, 0)+(Shot.getState2(bl_num)/2))
	end
end

--@EndScript