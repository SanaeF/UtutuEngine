--60�J�E���g��A�^���֐i��
function MovePattern0(id)
	time = Minion.getCount(id)
	if (time == 60) then
		Minion.setAngle(PI/2)
		Minion.setSpeed(4)
	end
	if (time > 60) then
		Minion.addSpeed(0.2)
	end
end