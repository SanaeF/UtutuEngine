--左上に上がっていく
function MovePattern0(id)
	time = Minion.getCount(id)
	if(time>100)then
		Minion.setAngle(-PI/2+PI/3)
		Minion.setSpeed(4)
	end
end