function Bullet(id)
	time = Minion.getCount(id)
	type = Minion.getBulletObjType(id)
	color = Minion.getBulletObjColor(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	if (between(time, 0, 210))then bullet_type = 0 end
	if (between(time, 210, 450))then bullet_type = 1 end
	if (between(time, 450, 680))then bullet_type = 2 end
	if (between(time, 680, 950))then bullet_type = 3 end
	if (time >= 950)then bullet_type = 4 end


	angle_h = homing(ex,ey,Player.getX(),Player.getY())
	if (bullet_type == 0)then
		if (20 < time and time % 23 == 0)then se_play(BULLET02)
			et_s.ringAt(ex, ey, diff(2, 4, 6, 4), 25, IMG.SCALY, CL.RED, 4+rand(1), angle_h + rand(PI/4), 99)
		end
	end
	if (bullet_type == 1)then
		if (between(time, 210, 275) and time % 6 == 0)then se_play(BULLET02)
			add = (time - 210) / 6
			et_s.ringAt(ex, ey, diff(3, 4, 6, 4), 25, IMG.NORMAL, CL.GREEN, 5, cos_(PI/13 * add), 99)
		end
		if (between(time, 280, 345) and time % 6 == 0)then se_play(BULLET02)
			add = (time - 280) / 6
			et_s.ringAt(ex, ey, diff(3, 4, 6, 4), 25, IMG.NORMAL, CL.GREEN, 5, -cos_(PI/13 * add), 99)
		end
	end
	if (bullet_type == 2)then
		per=diff(12, 10, 6, 10)
		if (10 < time and time % per == 0)then se_play(BULLET02)
			add = (time) / per
			et_s.ringAt(ex, ey, 7, 15, IMG.RICE, CL.BLUE, sp_(4, 4, 5, 4), cos_(PI/25 * add), 99)
		end
	end
	if (bullet_type == 3)then
		per=diff(12, 10, 6, 10)
		if (10 < time and time % per == 0)then se_play(BULLET02)
			add = (time) / per
			et_s.ringAt(ex, ey, 7, 15, IMG.RICE, CL.YELLOW, sp_(5, 5, 6, 5), cos_(PI/32 * add), 99)
		end
	end
	if (bullet_type == 4)then
		per=diff(13, 23, 13, 24)
		if (10 < time and time % per == 0)then se_play(BULLET02)
			add = (time) / per
			et_s.ringAt(ex, ey, diff(14, 23, 47, 24), 15, IMG.OVERLAP, CL.PURPLE, 5, cos_(PI/diff(8, 8, 25, 11) * add)/7, 99)
		end
	end
end
function MovePattern(id)

end
function ItemMinion()
	if (Player.getItemApple() == 3) then
		NONE = 99
		en_spawn(Player.getX(), 200, DEV_ITEMBALLOON, 800, NONE, NONE)
		en_item(8, 1)
		Player.setItemApple(0)
	end
	for i=0,MINION_MAX do
		if (Minion.isFlag(i) and 
			Minion.getMoverID(i) == NONE and 
			Minion.getBulletID(i) == NONE)then 
			Bullet(i)
			MovePattern(i)
		end
	end
end

--@EndScripts