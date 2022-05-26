
function MovePattern1(id)
	time = Minion.getCount(id)
	if (time == 0) then
		Minion.setAngle(PI/6)
		Minion.setSpeed(6)
	end
end

--@EndScript