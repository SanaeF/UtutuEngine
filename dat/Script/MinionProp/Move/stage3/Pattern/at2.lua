--���񂾂��A�������ێ������^�񒆂Ɍ������Đi�߂�悤�Ɋp�x�����߂�
function MovePattern2(id)
	time = Minion.getCount(id)
	if(time==0)then
		ex, ey = Param2(Minion.getX(id), Minion.getY(id))
		angle=homing(ex, ey, (FMAX_X-FMIN_X)/2, ey)
		Minion.setAngle(angle)
		Minion.setSpeed(3)
	end
end