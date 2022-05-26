dofile( './dat/Script/Library/Helper.lua' )
dofile( './dat/Script/Library/Bullet/BulletProp/ShotSc.lua' )
dofile( './dat/Script/Library/Bullet/BulletProp/LazerSc.lua' )
dofile( './dat/Script/Library/Bullet/BulletProp/TurnLazerSc.lua' )
dofile( './dat/Script/Library/Bullet/BulletProp/BulletColor.lua' )
dofile( './dat/Script/Library/Bullet/BulletProp/BulletImage.lua' )
dofile( './dat/Script/Library/Bullet/BulletProp/BossBulletEt/BulletEtSet.lua' )

Infinity = 9999

function FieldCrush(size, time)
	ShakeFunc(size, time)
end

function diff(easy, normal, hard, v_hard)
	if difficulty==0 then return easy end
	if difficulty==1 then return normal end
	if difficulty==2 then return hard end
	if difficulty==3 then return v_hard end
	return -1
end
function knd_(easy, normal, hard, v_hard)
	if difficulty==0 then return easy end
	if difficulty==1 then return normal end
	if difficulty==2 then return hard end
	if difficulty==3 then return v_hard end
	return -1
end
function col_(easy, normal, hard, v_hard)
	if difficulty==0 then return easy end
	if difficulty==1 then return normal end
	if difficulty==2 then return hard end
	if difficulty==3 then return v_hard end
	return -1
end
function sp_(easy, normal, hard, v_hard)
	if difficulty==0 then return easy end
	if difficulty==1 then return normal end
	if difficulty==2 then return hard end
	if difficulty==3 then return v_hard end
	return -1
end
function rd_(easy, normal, hard, v_hard)
	if difficulty==0 then return easy end
	if difficulty==1 then return normal end
	if difficulty==2 then return hard end
	if difficulty==3 then return v_hard end
	return -1
end
--@EndScript