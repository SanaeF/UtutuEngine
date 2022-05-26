
function MovePattern3(id)
	time = Minion.getCount(id)
	if(time==80)then
		Minion.setAngle(-PI/2)
		Minion.setSpeed(4)
	end
end