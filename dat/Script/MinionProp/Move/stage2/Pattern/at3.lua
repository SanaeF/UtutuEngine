
function MovePattern3(id)
	time = Minion.getCount(id)

	if (between(time, 30, 5)) then Minion.addSpeed(-0.5) end
	if (time == 50)then Minion.setSpeed(0) end
	if (time > 350)then Minion.setSpeed(-4) end
end

--@EndScript