
function MovePattern2(id)
	time = Minion.getCount(id)
	if (time == 0) then
		Minion.setAngle(PI/2)
		Minion.setSpeed(5)
	end
	if (time == 50) then
		Minion.setSpeed(0)
	end
	if (time > 600) then
		Minion.setAngle(-PI/2)
		Minion.setSpeed(4)
	end
end

--@EndScript