
function MovePattern0(id)
	time = Minion.getCount(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())
	if (time == 70) then
		angle = homing(ex, ey, px, py)
		Minion.setAngle(angle)
	end
	if (time > 70) then
		Minion.addSpeed(0.1)
	end
end

--@EndScript