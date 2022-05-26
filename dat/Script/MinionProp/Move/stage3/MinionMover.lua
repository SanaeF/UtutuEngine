dofile( './dat/Script/MinionProp/Move/Stage3/Pattern/at0.lua' )
dofile( './dat/Script/MinionProp/Move/Stage3/Pattern/at1.lua' )
dofile( './dat/Script/MinionProp/Move/Stage3/Pattern/at2.lua' )
dofile( './dat/Script/MinionProp/Move/Stage3/Pattern/at3.lua' )
dofile( './dat/Script/MinionProp/Move/Stage3/Pattern/at4.lua' )

function MinionMoveUpdate(id)
	if(Minion.getMoverID(id) == 0)then MovePattern0(id) end
	if(Minion.getMoverID(id) == 1)then MovePattern1(id) end
	if(Minion.getMoverID(id) == 2)then MovePattern2(id) end
	if(Minion.getMoverID(id) == 3)then MovePattern3(id) end
	if(Minion.getMoverID(id) == 4)then MovePattern4(id) end
end

--@EndScript