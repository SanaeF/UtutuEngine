--ç∂Ç÷
function MovePattern5(id)
	time = Minion.getCount(id)
	speed = Minion.getSpeed(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX_who(who), Player.getY_who(who))
	if(time==0)then
		Minion.setAngle(PI)
		Minion.setSpeed(5)
	end
end