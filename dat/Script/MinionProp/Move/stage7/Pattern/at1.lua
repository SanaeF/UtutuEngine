--‚ä‚Á‚­‚è‰º‚ª‚Á‚Ä¶‚Ös‚­
function MovePattern1(id)
	time = Minion.getCount(id)
	if(time==0)then
		Minion.setAngle(PI/2)
		Minion.setSpeed(3)
	end
	if(Minion.getY(id)>F_HALF_Y-400)then
		Minion.addAngle(PI/2/200)
	end
end