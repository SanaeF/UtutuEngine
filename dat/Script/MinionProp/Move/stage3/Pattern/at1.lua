--���񂾂��A�^�񒆂Ɍ������Đi�߂�悤�Ɋp�x�����߂�
function MovePattern1(id)
	time = Minion.getCount(id)
	if(time==0)then
		ex, ey = Param2(Minion.getX(id), Minion.getY(id))
		angle=homing(ex, ey, (FMAX_X-FMIN_X)/2, (FMAX_Y-FMIN_Y)/2)
		Minion.setAngle(angle)
		Minion.setSpeed(4)
	end
end