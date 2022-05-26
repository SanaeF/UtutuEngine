
function Bullet4(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())

	per=30
	if (time%per==0)then se_play(BULLET01)
		et_s.shine(true)
		et_s.state2(0)
		et_s.ringAt(ex, ey, 22, 0, type, color, 7, PI/45*(time/per), 4)
	end
	if (time%per==per/2)then se_play(BULLET01)
		et_s.shine(true)
		et_s.state2(1)
		et_s.ringAt(ex, ey, 22, 0, type, color, 7, -PI/45*(time/per), 4)
	end
end
function Trans4(bl_num)
	if(Shot.getState2(bl_num)==0)then Shot.addAngle(PI/368) end
	if(Shot.getState2(bl_num)==1)then Shot.addAngle(-PI/368) end
end

--@EndScript