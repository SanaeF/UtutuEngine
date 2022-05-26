
function MovePattern3(id)
	time = Minion.getCount(id)
	if (time == 0) then
		Minion.setAngle(PI/2)
		Minion.setSpeed(5)
	end
end

--@EndScript