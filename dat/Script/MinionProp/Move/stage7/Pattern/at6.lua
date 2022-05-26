--Å‘¬‚Å‰º‚ª‚Á‚Äs‚­
function MovePattern6(id)
	time = Minion.getCount(id)
	speed = Minion.getSpeed(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX_who(who), Player.getY_who(who))
	if(time==0)then
		Minion.setAngle(PI/2)
		Minion.setSpeed(7)
	end
end