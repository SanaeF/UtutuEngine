dofile( './dat/Script/MinionProp/Bullet/Stage0/Pattern/at0.lua' )
dofile( './dat/Script/MinionProp/Bullet/Stage0/Pattern/at1.lua' )
dofile( './dat/Script/MinionProp/Bullet/Stage0/Pattern/at2.lua' )
dofile( './dat/Script/MinionProp/Bullet/Stage0/Pattern/at3.lua' )
dofile( './dat/Script/MinionProp/Bullet/Stage0/Pattern/at4.lua' )

function MinionBulletUpdate(id)
	if(Minion.getBulletID(id) == 0)then Bullet0(id) end
	if(Minion.getBulletID(id) == 1)then Bullet1(id) end
	if(Minion.getBulletID(id) == 2)then Bullet2(id) end
	if(Minion.getBulletID(id) == 3)then Bullet3(id) end
	if(Minion.getBulletID(id) == 4)then Bullet4(id) end
end
function MinionBulletTrans()
	for bl_num = 0, SHOT_MAX do
		if(Shot.isFlag(bl_num))then
			if(Shot.getState1(bl_num) == 0)then Trans0(bl_num) end
			if(Shot.getState1(bl_num) == 1)then Trans1(bl_num) end
			if(Shot.getState1(bl_num) == 2)then Trans2(bl_num) end
			if(Shot.getState1(bl_num) == 3)then Trans3(bl_num) end
			if(Shot.getState1(bl_num) == 4)then Trans4(bl_num) end
		end
	end
end
--@EndScript