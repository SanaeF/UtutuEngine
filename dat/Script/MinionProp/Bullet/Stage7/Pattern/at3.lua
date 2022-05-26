--â~å`íeåç∑å^
function Bullet3(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())
	if(time==20)then se_play(KIRAN)
		et_s.state2(0)
		et_s.shine(true)
		et_s.ringAt(ex, ey, 5, 0, IMG.BIG, color, 6.5, 0, 3)
		et_s.state2(1)
		et_s.shine(true)
		et_s.ringAt(ex, ey, 5, 0, IMG.BIG, color, 6.5, 0, 3)
		et_s.state2(2)
		et_s.shine(true)
		et_s.size(0.7)
		et_s.ringAt(ex, ey, 7, 0, type, color, 5, rand(PI/7), 3)
	end
end

function Trans3(bl_num)
	if(Shot.getState2(bl_num)==0)then Shot.addAngle(PI/368) end
	if(Shot.getState2(bl_num)==1)then Shot.addAngle(-PI/368) end
end

--@EndScript