function Bullet0(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())
	if(time%60==0)then se_play(BULLET01)
		rd_num = diff(12, 17, 23, 0)
		angle = homing(ex, ey, px, py)+rand(PI/(rd_num*6))
		for ite = 0, diff(2, 4, 6, 0)do
			et_s.shine(true)
			et_s.ringAt(ex, ey, rd_num, 80, type, color, sp_(3,4,6,0)+ite, angle, 0)
		end
	end
end
function Trans0(bl_num)
	return
end
--@EndScript