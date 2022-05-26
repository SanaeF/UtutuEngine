
function MovePattern2(id)
	time = Minion.getCount(id)
	if (time == 0) then
		Minion.setAngle(PI-PI/6)
		Minion.setSpeed(6)
	end
end

--@EndScript