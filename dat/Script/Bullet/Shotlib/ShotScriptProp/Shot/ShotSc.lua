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
	function Shot.isNotRota()
		ShotFunc("Func:Rota", shot_number, false, true)
	end
	function Shot.isNotShine()
		ShotFunc("Func:Shine", shot_number, false, true)
	end
	function Shot.isNotBound()
		ShotFunc("Func:Bound", shot_number, false, true)
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
	function Shot.setAngle(angle)
		ShotFunc("Func:Angle", shot_number, angle, true)
	end
	function Shot.setType(type)
		ShotFunc("Func:Type", shot_number, type, true)
	end
	function Shot.setColor(color)
		ShotFunc("Func:Color", shot_number, color, true)
	end
	function Shot.setSize(size)
		ShotFunc("Func:Size", shot_number, size, true)
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


et_s = {}
	function et_s.between(time, t0, t1)
		if t0 <= time and time <= t1 then
			return true
		end
		return false
	end

	function et_s.ring(num, dist, type ,color, speed, add_rd, state)
		for bl_num = 1 , num do
			angle = ((bl_num * PI2) / num) + add_rd
			Shot.Create(x_dt(Boss.get_x(), angle, dist),y_dt(Boss.get_y(), angle, dist), type, color, speed, angle, state)
			Shot.isNotRota()
			Shot.isNotShine()
		end
	end

	function et_s.rd_add(bl_num, start_time, add_time, add_angle, state)
		if not(Shot.getState1(bl_num) == state) then return end
		if not(et_s.between(Shot.getCount(bl_num), start_time, add_time)) then return end
		Shot.setAngle(Shot.getAngle(bl_num) + add_angle)
	end
	function et_s.sp_up(bl_num, start_time, add_time, add_speed, state)
		if not(Shot.getState1(bl_num) == state) then return end
		if not(et_s.between(Shot.getCount(bl_num), start_time, add_time)) then return end
		Shot.setSpeed(Shot.getSpeed(bl_num) + add_speed)
	end