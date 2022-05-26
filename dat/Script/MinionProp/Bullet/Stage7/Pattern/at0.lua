--¯‚ğƒ‰ƒ“ƒ_ƒ€ŠgUŒ^‚Ì‰~Œ`’e‚Æƒz[ƒ~ƒ“ƒO˜AË
function Bullet0(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())
	if (time%50==20)then se_play(KIRAN)
		et_s.rota(true)
		et_s.state2(0)
		et_s.ringAt(ex, ey, 35, 0, IMG.MINI_STAR, color, 7, rand(PI/2), 0)
	end
	if (time%25==10)then se_play(KIRAN)
		angle = homing(ex, ey, px, py)
		Shot.Create(ex, ey, type, color, 8, angle , 0)
		Shot.isShine()
		Shot.isRota()
		Shot.setState2(1)
	end
end
function Trans0(bl_num)
	if(Shot.getCount(bl_num) == 30 and Shot.getState2(bl_num)==0)then Shot.addAngle(rand(PI/75)) end
end
--@EndScript