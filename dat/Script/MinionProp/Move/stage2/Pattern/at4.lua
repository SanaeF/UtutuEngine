
function MovePattern4(id)
	time = Minion.getCount(id)
	speed = Minion.getSpeed(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX_who(who), Player.getY_who(who))
	f_max = FMAX_X - FMIN_X
	if (time == 0) then
		Minion.setAngle(-PI/2)
	end
	scale = Minion.getSpeed(id)
	scale = 700/scale
	if(ex < f_max/2)then
		Minion.addAngle(PI/3/scale)
	else
		Minion.addAngle(-PI/3/scale)
	end
end

--@EndScript