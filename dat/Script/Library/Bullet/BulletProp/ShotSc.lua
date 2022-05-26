SHOT_MAX = getShot_max
shot_number = -1

Shot = {}
	function Shot.Create(x, y, type, color, speed, angle, state)
		search_num = ShotFunc("Func:Search", false, false, false)
		ShotFunc("Func:Default", search_num, false, false)
		ShotFunc("Func:Flag", search_num, true, true)
		ShotFunc("Func:X", search_num, x, true)
		ShotFunc("Func:Y", search_num, y, true)
		ShotFunc("Func:Angle", search_num, angle, true)
		ShotFunc("Func:Speed", search_num, speed, true)
		ShotFunc("Func:Type", search_num, type, true)
		ShotFunc("Func:Color", search_num, color, true)
		ShotFunc("Func:State1", search_num, state, true)
		ShotFunc("Func:Size", search_num, 1, true)
		ShotFunc("Func:Count", search_num, 0, true)
		shot_number = search_num
		return search_num
	end

	function Shot.isRota()
		ShotFunc("Func:Rota", shot_number, true, true)
	end
	function Shot.isShine()
		ShotFunc("Func:Shine", shot_number, true, true)
	end
	function Shot.isBound()
		ShotFunc("Func:Bound", shot_number, true, true)
	end
	function Shot.isHide()
		ShotFunc("Func:Hide", shot_number, true, true)
	end
	function Shot.isNoDelete()
		ShotFunc("Func:NoDelete", shot_number, true, true)
	end
	function Shot.isNotRota()
		ShotFunc("Func:Rota", shot_number, false, true)
	end
	function Shot.isNotShine()
		ShotFunc("Func:Shine", shot_number, false, true)
	end
	function Shot.isNotBound()
		ShotFunc("Func:Bound", shot_number, false, true)
	end
	function Shot.isNotHide()
		ShotFunc("Func:Hide", shot_number, false, true)
	end
	function Shot.isDelete()
		ShotFunc("Func:NoDelete", shot_number, false, true)
	end
	function Shot.clear()
		ShotFunc("Func:Flag", shot_number, false, true)
	end

	function Shot.setX(x)
		ShotFunc("Func:X", shot_number, x, true)
	end
	function Shot.setY(y)
		ShotFunc("Func:Y", shot_number, y, true)
	end
	function Shot.setSpeed(speed)
		ShotFunc("Func:Speed", shot_number, speed, true)
	end
	function Shot.addSpeed(speed)
		Shot.setSpeed(Shot.getSpeed(shot_number) + speed)
	end
	function Shot.setAngle(angle)
		ShotFunc("Func:Angle", shot_number, angle, true)
	end
	function Shot.addAngle(angle)
		Shot.setAngle(Shot.getAngle(shot_number) + angle)
	end
	function Shot.setType(type)
		ShotFunc("Func:Type", shot_number, type, true)
	end
	function Shot.setColor(color)
		ShotFunc("Func:Color", shot_number, color, true)
	end
	function Shot.setSize(size)
		ShotFunc("Func:Size", shot_number,size, true)
	end
	function Shot.setState1(state)
		ShotFunc("Func:State1", shot_number, state, true)
	end
	function Shot.setState2(state)
		ShotFunc("Func:State2", shot_number, state, true)
	end
	function Shot.setCount(count)
		ShotFunc("Func:Count", shot_number, count, true)
	end
	function Shot.setWho(who)
		ShotFunc("Func:Who", shot_number, who, true)
	end
	function Shot.setBoundCount(num)
		ShotFunc("Func:BoundCount", shot_number, num, true)
	end
	function Shot.setBoundArea(num)
		ShotFunc("Func:BoundArea", shot_number, num, true)
	end

	function Shot.id()
		return shot_number
	end
	function Shot.isFlag(num)
		shot_number = num
		return ShotFunc("Func:Flag", shot_number, false, false)
	end
	function Shot.getX(num)
		shot_number = num
		return ShotFunc("Func:X", shot_number, false, false)
	end
	function Shot.getY(num)
		shot_number = num
		return ShotFunc("Func:Y", shot_number, false, false)
	end
	function Shot.getSpeed(num)
		shot_number = num
		return ShotFunc("Func:Speed", shot_number, false, false)
	end
	function Shot.getAngle(num)
		shot_number = num
		return ShotFunc("Func:Angle", shot_number, false, false)
	end
	function Shot.getType(num)
		shot_number = num
		return ShotFunc("Func:Type", shot_number, false, false)
	end
	function Shot.getColor(num)
		shot_number = num
		return ShotFunc("Func:Color", shot_number, false, false)
	end
	function Shot.getSize(num)
		shot_number = num
		return ShotFunc("Func:Size", shot_number, false, false)
	end
	function Shot.getState1(num)
		shot_number = num
		return ShotFunc("Func:State1", shot_number, false, false)
	end
	function Shot.getState2(num)
		shot_number = num
		return ShotFunc("Func:State2", shot_number, false, false)
	end
	function Shot.getCount(num)
		shot_number = num
		return ShotFunc("Func:Count", shot_number, false, false)
	end
	function Shot.getBoundCount(num)
		shot_number = num
		return ShotFunc("Func:BoundCount", shot_number, false, false)
	end
	function Shot.getBoundArea(num)
		shot_number = num
		return ShotFunc("Func:BoundArea", shot_number, false, false)
	end
	function Shot.getWho(num)
		shot_number = num
		return ShotFunc("Func:Who", shot_number, false, false)
	end
--@EndScript