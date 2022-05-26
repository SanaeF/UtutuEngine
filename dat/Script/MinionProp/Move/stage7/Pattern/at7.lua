--ç≈ë¨Ç≈â∫Ç™Ç¡ÇƒçsÇ≠
function MovePattern7(id)
	time = Minion.getCount(id)
	speed = Minion.getSpeed(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX_who(who), Player.getY_who(who))
	if(time==0)then
		Minion.setAngle(PI/2)
		Minion.setSpeed(3)
	end
	if(time==120)then
		Minion.setAngle(-PI/2)
		Minion.setSpeed(0)
	end
	if(time==480)then
		Minion.setSpeed(4)
	end
end