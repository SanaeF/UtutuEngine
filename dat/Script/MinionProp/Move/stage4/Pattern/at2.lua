--ã‚Éã‚ª‚Á‚Ä‚¢‚­
function MovePattern2(id)
	time = Minion.getCount(id)
	if(time>100)then
		Minion.setAngle(-PI/2)
		Minion.setSpeed(4)
	end
end