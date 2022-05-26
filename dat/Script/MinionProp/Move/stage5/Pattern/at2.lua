--自機へホーミング
function MovePattern2(id)
	time = Minion.getCount(id)
	ex, ey = Param2(Minion.getX(id), Minion.getY(id))
	px, py = Param2(Player.getX(), Player.getY())
	if (time == 0) then
		Minion.addSpeed(2)
		angle = homing(ex, ey, px, py)
		Minion.setAngle(angle)
	end
	if (time < 140) then
		Minion.addSpeed(0.06)
	end
end