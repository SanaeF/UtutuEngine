LAZER_MAX = getLazer_max
lazer_number = -1
Lazer = {}
	function Lazer.Create(x, y, type, color, speed, angle, state)
		search_num = LazerFunc("Func:Search", false, false, false)
		LazerFunc("Func:Default", search_num, false, false)
		LazerFunc("Func:Flag", search_num, true, true)
		LazerFunc("Func:Collision", search_num, false, true)
		LazerFunc("Func:X", search_num, x, true)
		LazerFunc("Func:Y", search_num, y, true)
		LazerFunc("Func:Angle", search_num, angle, true)
		LazerFunc("Func:Speed", search_num, speed, true)
		LazerFunc("Func:Type", search_num, type, true)
		LazerFunc("Func:Color", search_num, color, true)
		LazerFunc("Func:MainType", search_num, type, true)
		LazerFunc("Func:MainColor", search_num, color, true)
		LazerFunc("Func:Thick", search_num, 0, true)
		LazerFunc("Func:Length", search_num, 0, true)
		LazerFunc("Func:State1", search_num, state, true)
		LazerFunc("Func:Count", search_num, 0, true)
		lazer_number = search_num
	end

	function Lazer.isBound()
		LazerFunc("Func:Bound", lazer_number, true, true)
	end
	function Lazer.isNotBound()
		LazerFunc("Func:Bound", lazer_number, false, true)
	end
	function Lazer.isNoDelete()
		LazerFunc("Func:NoDelete", lazer_number, true, true)
	end
	function Lazer.isNoBoundAngle()
		LazerFunc("Func:BoundNoAngle", lazer_number, true, true)
	end
	function Lazer.isBoundAngle()
		LazerFunc("Func:BoundNoAngle", lazer_number, false, true)
	end
	function Lazer.isCollision()
		LazerFunc("Func:Collision", lazer_number, true, true)
	end
	function Lazer.isNotCollision()
		LazerFunc("Func:Collision", lazer_number, false, true)
	end
	function Lazer.isDelete()
		LazerFunc("Func:NoDelete", lazer_number, false, true)
	end
	function Lazer.clear()
		LazerFunc("Func:Flag", lazer_number, false, true)
	end

	function Lazer.setX(x)
		LazerFunc("Func:X", lazer_number, x, true)
	end
	function Lazer.setY(y)
		LazerFunc("Func:Y", lazer_number, y, true)
	end
	function Lazer.setSpeed(speed)
		LazerFunc("Func:Speed", lazer_number, speed, true)
	end
	function Lazer.setAngle(angle)
		LazerFunc("Func:Angle", lazer_number, angle, true)
	end
	function Lazer.setLengthAngle(angle)
		LazerFunc("Func:LengthAngle", lazer_number, angle, true)
	end
	function Lazer.addLengthAngle(angle)
		Lazer.setLengthAngle(Lazer.getLengthAngle(lazer_number) + angle)
	end
	function Lazer.addAngle(angle)
		Lazer.setAngle(Lazer.getAngle(lazer_number) + angle)
	end
	function Lazer.setRota(t0,t1,angle)
		if(between(Lazer.getCount(lazer_number),t0,t1))then
			add_angle = angle/(t1-t0)
			Lazer.setLengthAngle(Lazer.getLengthAngle(lazer_number)+add_angle)
		end
	end
	function Lazer.setType(type)
		LazerFunc("Func:Type", lazer_number, type, true)
	end
	function Lazer.setColor(color)
		LazerFunc("Func:Color", lazer_number, color, true)
	end
	function Lazer.setMainType(type)
		LazerFunc("Func:MainType", lazer_number, type, true)
	end
	function Lazer.setMainColor(color)
		LazerFunc("Func:MainColor", lazer_number, color, true)
	end
	function Lazer.setThick(size)
		LazerFunc("Func:Thick", lazer_number, size, true)
	end
	function Lazer.addThick(size)
		Lazer.setThick(Lazer.getThick(lazer_number) + size)
	end
	function Lazer.setLength(size)
		LazerFunc("Func:Length", lazer_number, size, true)
	end
	function Lazer.addLength(size)
		Lazer.setLength(Lazer.getLength(lazer_number) + size)
	end
	function Lazer.setState1(state)
		LazerFunc("Func:State1", lazer_number, state, true)
	end
	function Lazer.setState2(state)
		LazerFunc("Func:State2", lazer_number, state, true)
	end
	function Lazer.setCount(count)
		LazerFunc("Func:Count", lazer_number, count, true)
	end
	function Lazer.setWho(who)
		LazerFunc("Func:Who", lazer_number, who, true)
	end

	function Lazer.isFlag(num)
		lazer_number = num
		return LazerFunc("Func:Flag", lazer_number, false, false)
	end
	function Lazer.getX(num)
		lazer_number = num
		return LazerFunc("Func:X", lazer_number, false, false)
	end
	function Lazer.getY(num)
		lazer_number = num
		return LazerFunc("Func:Y", lazer_number, false, false)
	end
	function Lazer.getSpeed(num)
		lazer_number = num
		return LazerFunc("Func:Speed", lazer_number, false, false)
	end
	function Lazer.getAngle(num)
		lazer_number = num
		return LazerFunc("Func:Angle", lazer_number, false, false)
	end
	function Lazer.getLengthAngle(num)
		lazer_number = num
		return LazerFunc("Func:LengthAngle", lazer_number, false, false)
	end
	function Lazer.getType(num)
		lazer_number = num
		return LazerFunc("Func:Type", lazer_number, false, false)
	end
	function Lazer.getColor(num)
		lazer_number = num
		return LazerFunc("Func:Color", lazer_number, false, false)
	end
	function Lazer.getMainType(num)
		lazer_number = num
		return LazerFunc("Func:MainType", lazer_number, false, false)
	end
	function Lazer.getMainColor(num)
		lazer_number = num
		return LazerFunc("Func:MainColor", lazer_number, false, false)
	end
	function Lazer.getSize(num)
		lazer_number = num
		return LazerFunc("Func:Size", lazer_number, false, false)
	end
	function Lazer.getThick(num)
		lazer_number = num
		return LazerFunc("Func:Thick", lazer_number, false, false)
	end
	function Lazer.getLength(num)
		lazer_number = num
		return LazerFunc("Func:Length", lazer_number, false, false)
	end
	function Lazer.getState1(num)
		lazer_number = num
		return LazerFunc("Func:State1", lazer_number, false, false)
	end
	function Lazer.getState2(num)
		lazer_number = num
		return LazerFunc("Func:State2", lazer_number, false, false)
	end
	function Lazer.getCount(num)
		lazer_number = num
		return LazerFunc("Func:Count", lazer_number, false, false)
	end

	function Lazer.getBoundCount(num)
		lazer_number = num
		return LazerFunc("Func:BoundArea", lazer_number, false, false)
	end
	function Lazer.getBoundArea(num)
		lazer_number = num
		return LazerFunc("Func:BoundArea", lazer_number, false, true)
	end

--@EndScript