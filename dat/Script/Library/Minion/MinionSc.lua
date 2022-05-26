dofile( './dat/Script/Library/ItemList.lua' )

MINION_MAX = getMinion_max
minion_number = -1
Minion={}
	function Minion.setFlag()
		MinionFunc(minion_number, true, true, "Func:Flag")
	end
	function Minion.kill()
		MinionFunc(minion_number, true, false, "Func:Flag")
	end
	function Minion.setX(num)
		MinionFunc(minion_number, true, num, "Func:X")
	end
	function Minion.setY(num)
		MinionFunc(minion_number, true, num, "Func:Y")
	end
	function Minion.setSize(num)
		MinionFunc(minion_number, true, num, "Func:Size")
	end
	function Minion.setType(num)
		MinionFunc(minion_number, true, num, "Func:Type")
	end
	function Minion.setAngle(num)
		MinionFunc(minion_number, true, num, "Func:Angle")
	end
	function Minion.addAngle(num)
		Minion.setAngle(Minion.getAngle(minion_number) + num)
	end
	function Minion.setSpeed(num)
		MinionFunc(minion_number, true, num, "Func:Speed")
	end
	function Minion.addSpeed(num)
		Minion.setSpeed(Minion.getSpeed(minion_number) + num)
	end
	function Minion.setHP(num)
		MinionFunc(minion_number, true, num, "Func:HP")
	end
	function Minion.setLastHP(num)
		MinionFunc(minion_number, num, "Func:LastHP")
	end
	function Minion.setBoss()
		MinionFunc(minion_number, true, true, "Func:isBoss")
	end
	function Minion.setNotBoss()
		MinionFunc(minion_number, true, false, "Func:isBoss")
	end
	function Minion.setNoUI(flag)
		MinionFunc(minion_number, true, flag, "Func:NoUI")
	end
	function Minion.setMoverID(num)
		MinionFunc(minion_number, true, num, "Func:MoveID")
	end
	function Minion.setBulletID(num)
		MinionFunc(minion_number, true, num, "Func:BulletID")
	end
	function Minion.setMotion(num)
		MinionFunc(minion_number, true, num, "Func:MotionType")
	end
	function Minion.setItemID(num)
		MinionFunc(minion_number, true, num, "Func:ItemID")
	end
	function Minion.setItemNum(num)
		MinionFunc(minion_number, num, "Func:ItemNum")
	end
	function Minion.setState1(num)
		MinionFunc(minion_number, true, num, "Func:State1")
	end
	function Minion.setState2(num)
		MinionFunc(minion_number, true, num, "Func:State2")
	end
	function Minion.setCount(num)
		MinionFunc(minion_number, true, num, "Func:Count")
	end
	function Minion.setWho(num)
		MinionFunc(minion_number, true, num, "Func:Who")
	end
	function Minion.setBulletObjType(num)
		MinionFunc(minion_number, true, num, "Func:BulletObjType")
	end
	function Minion.setBulletObjColor(num)
		MinionFunc(minion_number, true, num, "Func:BulletObjColor")
	end
	function Minion.setMove(x,y,time)
		MinionFunc(minion_number, x, y, time, "Func:Move")
	end
	function Minion.setRandMove(x0,y0,x1,y1,dist,time)
		MinionFunc(minion_number, x0, y0, x1, y1, dist, time, "Func:RandMove")
	end

	function Minion.sendID(id)
		MinionFunc(id, "Func:SendID")
	end

	function Minion.isFlag(num)
		minion_number = num
		Minion.sendID(num)
		flag = MinionFunc(num, false, -1, "Func:Flag")
		if(flag == true)then return true end
		return false
	end
	function Minion.getX(num)
		minion_number = num
		return MinionFunc(num, false, -1, "Func:X")
	end
	function Minion.getY(num)
		minion_number = num
		return MinionFunc(num, false, -1, "Func:Y")
	end
	function Minion.getType(num)
		minion_number = num
		return MinionFunc(num, false, -1, "Func:Type")
	end
	function Minion.getAngle(num)
		minion_number = num
		return MinionFunc(num, false, -1, "Func:Angle")
	end
	function Minion.getSize(num)
		minion_number = num
		return MinionFunc(num, false, -1, "Func:Size")
	end
	function Minion.getSpeed(num)
		minion_number = num
		return MinionFunc(num, false, -1, "Func:Speed")
	end
	function Minion.getHP(num)
		minion_number = num
		return MinionFunc(num, false, -1, "Func:HP")
	end
	function Minion.getBoss(num)
		minion_number = num
		return MinionFunc(num, false, -1, "Func:isBoss")
	end
	function Minion.getNotBoss(num)
		minion_number = num
		return MinionFunc(num, false, -1, "Func:isBoss")
	end
	function Minion.getMoverID(num)
		minion_number = num
		return MinionFunc(num, false, -1, "Func:MoveID")
	end
	function Minion.getBulletID(num)
		minion_number = num
		return MinionFunc(num, false, -1, "Func:BulletID")
	end
	function Minion.getItemID(num)
		minion_number = num
		return MinionFunc(num, false, -1, "Func:ItemID")
	end
	function Minion.getState1(num)
		minion_number = num
		return MinionFunc(num, false, false, "Func:State1")
	end
	function Minion.getState2(num)
		minion_number = num
		return MinionFunc(num, false, -1, "Func:State2")
	end
	function Minion.getCount(num)
		minion_number = num
		return MinionFunc(num, false, -1, "Func:Count")
	end
	function Minion.getWho(num)
		minion_number = num
		return MinionFunc(num, false, -1, "Func:Who")
	end
	function Minion.getBulletObjType(num)
		minion_number = num
		return MinionFunc(num, false, -1, "Func:BulletObjType")
	end
	function Minion.getBulletObjColor(num)
		minion_number = num
		return MinionFunc(num, false, -1, "Func:BulletObjColor")
	end
	function Minion.searchID()
		return MinionFunc("Func:Search")
	end
	function Minion.spawn(hp, move_id, bullet_id, item_id)
		search_num = MinionFunc("Func:Search")
		minion_number = search_num
		Minion.setFlag()
		Minion.setNotBoss(search_num)
		Minion.setHP(hp)
		Minion.setMoverID(move_id)
		Minion.setBulletID(bullet_id)
		Minion.setItemID(item_id)
		Minion.setAngle(PI / 2)
		Minion.setCount(0)
	end
	function Minion.spawnBoss(id, hp, move_id, bullet_id, item_id)
		minion_number = id
		Minion.sendID(id)
		Minion.setFlag()
		Minion.setBoss()
		Minion.setHP(hp)
		Minion.setMoverID(move_id)
		Minion.setBulletID(bullet_id)
		Minion.setItemID(item_id)
		Minion.setAngle(0)
	end

function en_spawn(x, y, type, hp, bullet_id, move_id)
	Minion.spawn(hp, move_id, bullet_id, 0)
	Minion.setX(x)
	Minion.setY(y)
	Minion.setType(type)
	Minion.setSize(1)
	Minion.setWho(0)
end
function en_item(id, num)
	Minion.setItemID(id)
	Minion.setItemNum(num)
end
function en_bullet(type, color)
	Minion.setBulletObjType(type)
	Minion.setBulletObjColor(color)
end
function en_who(num)
	Minion.setWho(num)
end
function boss_spawn(id, x, y, type, hp, item_id)
	Minion.spawnBoss(id, hp, -1, -1, item_id)
	Minion.setX(x)
	Minion.setY(y)
	Minion.setType(type)
	Minion.setSize(1.5)
	Minion.setWho(0)
end
function deadMinionInfo(rayer)
	deadFlag=false
	for i=0,MINION_MAX do
		if(Minion.getWho(i) == rayer and Minion.getState1(i) == -1 and Minion.getState2(i) == -1)then
			Minion.setWho(0)
			Minion.setState1(0)
			Minion.setState2(0)
			deadFlag = true
		end
	end
	return deadFlag
end
--@EndScript