Lazer = {}
	NONE = 0

	function Shot.Create(x, y, type, color, speed, angle, state)
		LazerFunc("Func:Search", 0, 0)
		LazerFunc("Func:Flag", true, true)
		LazerFunc("Func:X", x, true)
		LazerFunc("Func:Y", y, true)
		LazerFunc("Func:Angle", angle, true)
		LazerFunc("Func:Speed", speed, true)
		LazerFunc("Func:Type", type, true)
		LazerFunc("Func:Color", color, true)
		LazerFunc("Func:State1", state, true)
		LazerFunc("Func:Size", 1, true)
		LazerFunc("Func:Count", 0, true)
	end

	function Shot.isRota()
		LazerFunc("Func:Rota", true, true)
	end
	function Shot.isShine()
		LazerFunc("Func:Shine", true, true)
	end
	function Shot.isBound()
		LazerFunc("Func:Bound", true, true)
	end
	function Shot.isNotRota()
		LazerFunc("Func:Rota", false, true)
	end
	function Shot.isNotShine()
		LazerFunc("Func:Shine", false, true)
	end
	function Shot.isNotBound()
		LazerFunc("Func:Bound", false, true)
	end
	function Shot.clear()
		LazerFunc("Func:Flag", false, true)
	end

	function Shot.set_X(x)
		LazerFunc("Func:X", x, true)
	end
	function Shot.set_Y(y)
		LazerFunc("Func:Y", y, true)
	end
	function Shot.set_Speed(speed)
		LazerFunc("Func:Speed", speed, true)
	end
	function Shot.set_Angle(angle)
		LazerFunc("Func:Angle", angle, true)
	end
	function Shot.set_Type(type)
		LazerFunc("Func:Type", type, true)
	end
	function Shot.set_Color(color)
		LazerFunc("Func:Color", color, true)
	end
	function Shot.set_Size(size)
		LazerFunc("Func:Size", size, true)
	end
	function Shot.set_State1(state)
		LazerFunc("Func:State1", state, true)
	end
	function Shot.set_State2(state)
		LazerFunc("Func:State2", state, true)
	end
	function Shot.set_Count(count)
		LazerFunc("Func:Count", count, true)
	end

	function Shot.get_Flag(num)
		LazerFunc("Func:Number", num, 0)
		return LazerFunc("Func:Flag", false, false)
	end

	function Shot.get_x(num)
		LazerFunc("Func:Number", num, 0)
		return LazerFunc("Func:X", false, false)
	end