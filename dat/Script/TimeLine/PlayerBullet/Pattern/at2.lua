
function bullet2(rayer) se_play(BULLET01)--ê‘èÈíeñã
	n = Shot.Create(Player.getX_who(rayer) + rand(50), 50, IMG.MOON, false, 6, 0, 2)
	angle = homing(Shot.getX(n), Shot.getY(n), Player.getX_who(rayer), Player.getY_who(rayer)) + rand(PI / 2.4)
	Shot.setAngle(angle)
	Shot.isRota()
	Shot.isBound()
	Shot.setWho(rayer)
end

--@EndScript