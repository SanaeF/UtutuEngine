--Œv‰ñ‚è‚ÅL‚ª‚Á‚Ä‚¢‚­
function MovePattern0(id)
	time = Minion.getCount(id)
	if(time==0)then
		Minion.setSpeed(9)
	end
	if(time<350)then
		Minion.addAngle((PI*18)/800)
	end
end