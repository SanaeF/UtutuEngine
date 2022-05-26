dofile( './dat/Script/Bullet/Shotlib/ShotScriptProp/Helper.lua' )
dofile( './dat/Script/Bullet/Shotlib/ShotScriptProp/Boss/BossSc.lua' )
dofile( './dat/Script/Bullet/Shotlib/ShotScriptProp/Shot/ShotSc.lua' )
dofile( './dat/Script/Bullet/Shotlib/ShotScriptProp/Lazer/LazerSc.lua' )
dofile( './dat/Script/Bullet/Shotlib/ShotScriptProp/Player/PlayerSc.lua' )
dofile( './dat/Script/Bullet/Shotlib/ShotScriptProp/TurnLazer/TurnLazerSc.lua' )
dofile( './dat/Script/Bullet/Shotlib/ShotScriptProp/ShotColor.lua' )
dofile( './dat/Script/Bullet/Shotlib/ShotScriptProp/ShotImage.lua' )
dofile( './dat/Script/Bullet/Shotlib/SEScript/SESc.lua' )
dofile( './dat/Script/Library/Minion/MinionSc.lua' )

FMAX_X = 1529--(624*2)
FMIN_X = 391--(106)
FMAX_Y = 1388
FMIN_Y = 52

Infinity = 9999
function isNotStart()
	if (shot_time < 0) then return true end
	return false
end

rd_h = {}
function rd_h.toPlayer(x,y)
	return homing(x,y,Player.getX(),Player.getY())
end
function rd_h.toBoss(x,y)
	return homing(x,y,Boss.get_x(),Boss.get_y())
end
function rd_h.set()
	return homing(Boss.get_x(), Boss.get_y(), Player.getX(), Player.getY())
end

function FieldCrush(size, time)
	ShakeFunc(size, time)
end

function rand(num)
	return (-num + num * 2 *  math.random(10000) / 10000.0)
end