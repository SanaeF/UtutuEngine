
function MovePattern0(id)
	time = Minion.getCount(id)
	if (time == 0) then
		Minion.setAngle(PI/2+PI/17)
		Minion.addSpeed(5)
	end
	if (between(time, 20, 80)) then
		Minion.addAngle(PI/3/60)
	end
end

--@EndScript