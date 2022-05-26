
function MovePattern1(id)
	time = Minion.getCount(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())
	if (time < 360) then
		Minion.addAngle(PI2/90)
		Minion.setSpeed(20)
	end
end

--@EndScript