Shot = {}
	function Shot.Create(x, y, type, color, speed, angle, state)
		ShotSearch()
		ShotFlag(true, true)
		ShotPosX(x, true)
		ShotPosY(y, true)
		ShotAngle(angle, true)
		ShotSpeed(speed, true)
		ShotType(type, true)
		ShotColor(color, true)
		ShotState1(state, true)
		ShotSize(1, true)
		ShotCount(0, true)
	end

	function Shot.isRota()
		ShotRota(true, true)
	end
	function Shot.isShine()
		ShotShine(true, true)
	end
	function Shot.isBound()
		ShotBound(true, true)
	end
	function Shot.isNotRota()
		ShotRota(false, true)
	end
	function Shot.isNotShine()
		ShotShine(false, true)
	end
	function Shot.isNotBound()
		ShotBound(false, true)
	end
	function Shot.clear()
		ShotFlag(false, true)
	end

	function Shot.set_X(x)
		ShotPosX(x, true)
	end
	function Shot.set_Y(y)
		ShotPosY(y, true)
	end
	function Shot.set_Speed(speed)
		ShotSpeed(speed, true)
	end
	function Shot.set_Angle(angle)
		ShotSize(angle, true)
	end
	function Shot.set_Type(type)
		ShotType(type, true)
	end
	function Shot.set_Color(color)
		ShotColor(color, true)
	end
	function Shot.set_Size(size)
		ShotSize(size, true)
	end
	function Shot.set_State1(state)
		ShotState1(state, true)
	end
	function Shot.set_State2(state)
		ShotState2(state, true)
	end
	function Shot.set_Count(count)
		ShotCount(count, true)
	end

	function Shot.get_Flag(num)
		ShotNumber(num)
		return ShotFlag(false, false)
	end

	function Shot.get_x(num)
		ShotNumber(num)
		return ShotPosX(false, false)
	end