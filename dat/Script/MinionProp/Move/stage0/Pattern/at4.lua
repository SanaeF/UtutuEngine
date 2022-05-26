
function MovePattern4(id)--âEÇ©ÇÁèoÇÈÇÊÇ§
	time = Minion.getCount(id)
	if (time == 0)then Minion.setSpeed(5) end
	if (time == 50)then 
		Minion.setSpeed(0)
		Minion.setAngle(PI)
	end
	if (time == 110)then Minion.setSpeed(6) end
	if (time == 150)then 
		Minion.setSpeed(0) 
		Minion.setAngle(PI/4)
	end
	if (time == 200)then Minion.setSpeed(7) end
	if (time == 250)then 
		Minion.setSpeed(0)
		Minion.setAngle(-PI/2)
	end
	if (time == 290)then 
		Minion.setSpeed(5) 
	end
end

--@EndScript