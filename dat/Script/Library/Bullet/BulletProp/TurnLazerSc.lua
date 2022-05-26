T_LAZ_MAX = getT_Laz_max
tLaz_number = -1
LazCr = {}
	function LazCr.Create(x, y, length, color, speed, angle, state)
		search_num = T_LazFunc("Func:Search", false, false, false)
		T_LazFunc("Func:Default", search_num, false, false)
		T_LazFunc("Func:Flag", search_num, true, true)
		T_LazFunc("Func:X", search_num, x, true)
		T_LazFunc("Func:Y", search_num, y, true)
		T_LazFunc("Func:Length", search_num, length, true)
		T_LazFunc("Func:Angle", search_num, angle, true)
		T_LazFunc("Func:Speed", search_num, speed, true)
		T_LazFunc("Func:Color", search_num, color, true)
		T_LazFunc("Func:State1", search_num, state, true)
		T_LazFunc("Func:Count", search_num, 0, true)
		T_LazFunc("Func:Who", search_num, 0, true)
		tLaz_number = search_num
	end

	function LazCr.isBound()
		T_LazFunc("Func:Bound", tLaz_number, true, true)
	end
	function LazCr.isNotBound()
		T_LazFunc("Func:Bound", tLaz_number, false, true)
	end
	function LazCr.clear()
		T_LazFunc("Func:Flag", tLaz_number, false, true)
	end

	function LazCr.setX(x)
		T_LazFunc("Func:X", tLaz_number, x, true)
	end
	function LazCr.setY(y)
		T_LazFunc("Func:Y", tLaz_number, y, true)
	end
	function LazCr.setSpeed(speed)
		T_LazFunc("Func:Speed", tLaz_number, speed, true)
	end
	function LazCr.addSpeed(speed)
		LazCr.setSpeed(LazCr.getSpeed(speed)+speed)
	end
	function LazCr.setAngle(angle)
		T_LazFunc("Func:Angle", tLaz_number, angle, true)
	end
	function LazCr.addAngle(angle)
		LazCr.setAngle(LazCr.getAngle(tLaz_number) + angle)
	end
	function LazCr.setColor(color)
		T_LazFunc("Func:Color", tLaz_number, color, true)
	end
	function LazCr.setState1(state)
		T_LazFunc("Func:State1", tLaz_number, state, true)
	end
	function LazCr.setState2(state)
		T_LazFunc("Func:State2", tLaz_number, state, true)
	end
	function LazCr.setCount(count)
		T_LazFunc("Func:Count", tLaz_number, count, true)
	end
	function LazCr.setWho(who)
		T_LazFunc("Func:Who", tLaz_number, who, true)
	end

	function LazCr.isFlag(num)
		tLaz_number = num
		return T_LazFunc("Func:Flag", tLaz_number, false, false)
	end
	function LazCr.getX(num)
		tLaz_number = num
		return T_LazFunc("Func:X", tLaz_number, false, false)
	end
	function LazCr.getY(num)
		tLaz_number = num
		return T_LazFunc("Func:Y", tLaz_number, false, false)
	end
	function LazCr.getSpeed(num)
		tLaz_number = num
		return T_LazFunc("Func:Speed", tLaz_number, false, false)
	end
	function LazCr.getAngle(num)
		tLaz_number = num
		return T_LazFunc("Func:Angle", tLaz_number, false, false)
	end
	function LazCr.getColor(num)
		tLaz_number = num
		return T_LazFunc("Func:Color", tLaz_number, false, false)
	end
	function LazCr.getState1(num)
		tLaz_number = num
		return T_LazFunc("Func:State1", tLaz_number, false, false)
	end
	function LazCr.getState2(num)
		tLaz_number = num
		return T_LazFunc("Func:State2", tLaz_number, false, false)
	end
	function LazCr.getCount(num)
		tLaz_number = num
		return T_LazFunc("Func:Count", tLaz_number, false, false)
	end
	function LazCr.getBoundCount(num)
		tLaz_number = num
		return T_LazFunc("Func:BoundArea", tLaz_number, false, false)
	end
	function LazCr.getBoundArea(num)
		tLaz_number = num
		return T_LazFunc("Func:BoundArea", tLaz_number, false, true)
	end
--@EndScript