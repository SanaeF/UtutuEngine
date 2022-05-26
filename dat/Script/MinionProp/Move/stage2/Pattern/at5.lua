
function MovePattern5(id)
	time = Minion.getCount(id)
	if (time == 0)then
		Minion.setAngle(-PI/2)
		Minion.setSpeed(1)
	end
end

--@EndScript