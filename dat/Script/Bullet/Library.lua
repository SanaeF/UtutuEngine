dofile( './dat/Script/Library/Boss/BossSc.lua' )
dofile( './dat/Script/Library/BossBullet/BossBullet.lua' )
dofile( './dat/Script/Library/Player/PlayerSc.lua' )
dofile( './dat/Script/Library/Sound/SoundSc.lua' )
dofile( './dat/Script/Library/Minion/MinionSc.lua' )
dofile( './dat/Script/Library/Bullet/BulletLib.lua' )

function isNotStart()
	if (shot_time < 0) then return true end
	return false
end
function getBulletState()
	return Boss.getBulletState(state)
end
function setBulletState(num)
	Boss.setBulletState(num)
end


rd_h = {}
function rd_h.toPlayer(x,y)
	return homing(x,y,Player.getX(),Player.getY())
end
function rd_h.toBoss(index,x,y)
	return homing(x,y,Boss.getX(index),Boss.getY(index))
end
function rd_h.Boss_Player(index)
	return homing(Boss.getX(index), Boss.getY(index), Player.getX(), Player.getY())
end
function rd_h.set(index)
	return homing(Boss.getX(index), Boss.getY(index), Player.getX(), Player.getY())
end

function rd_h.fShot_p(num)
	return rd_h.toPlayer(Shot.getX(num), Shot.getY(num))
end
function rd_h.fShot_b(num)
	return rd_h.toBoss(Shot.getX(num), Shot.getY(num))
end

function rd_h.fMinion_p(num)
	return rd_h.toPlayer(Minion.getX(num), Minion.getY(num))
end
function rd_h.fMinion_b(num)
	return rd_h.toBoss(Minion.getX(num), Minion.getY(num))
end
--@EndScript