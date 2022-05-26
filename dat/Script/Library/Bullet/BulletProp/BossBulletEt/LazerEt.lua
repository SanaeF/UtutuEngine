
et_l = {
	lz_boss_id=0,
	lz_stand_type, 
	lz_length = 0, 
	lz_length_angle = 0, 
	lz_thick = 0,
	lz_count = 0,
	lz_rayer = 0, 
	lz_num_in_st2 = false,
	lz_is_no_delete = false,
	lz_is_collision = false,
	lz_is_bound=false,
	lz_is_no_bound_angle=false
}
	function et_l.between(time, t0, t1)
		if t0 <= time and time <= t1 then
			return true
		end
		return false
	end
	function et_l.boss_id(num)
		lz_boss_id = num
	end
	function et_l.standType(num)
		lz_stand_type = num
	end
	function et_l.size(length, thick)
		lz_length = length
		lz_thick = thick
	end
	function et_l.rota_angle(angle)
		lz_length_angle = angle
	end
	function et_l.startCount(num)
		lz_count = num
	end
	function et_l.numInState2(flag)
		lz_num_in_st2 = flag
	end
	function et_l.rayer(num)
		lz_rayer = num
	end
	function et_l.collision(flag)
		lz_is_collision = flag
	end
	function et_l.bound(flag)
		lz_is_bound = flag
	end
	function et_l.noBoundAngle(flag)
		lz_is_no_bound_angle = flag
	end
	function et_l.noDelete(flag)
		lz_is_no_delete = flag
	end

	function et_l.ring(num, dist, type ,color, speed, add_rd, state)
		et_l.ringAt(Boss.getX(lz_boss_id), Boss.getY(lz_boss_id), num, dist, type ,color, speed, add_rd, state)
		et_l.PropClear()
	end
	function et_l.ringAt(x, y,num, dist, type ,color, speed, add_rd, state)
		for bl_num = 1 , num do
			local angle = ((bl_num * PI2) / num) + add_rd
			Lazer.Create(x_dt(x, angle, dist),y_dt(y, angle, dist), type, color, speed, angle, state)
			et_l.Prop()
			et_l.useParamProp(bl_num)
		end
		et_l.PropClear()
	end
	function et_l.nway(nway, num, dist, type ,color, speed, add_speed, radian, add_rd, state)
		if(num == 0)then return end
		et_l.nwayAt(Boss.getX(lz_boss_id), Boss.getY(lz_boss_id), nway, num, dist, type ,color, speed, add_speed, radian, add_rd, state)
		et_l.PropClear()
	end
	function et_l.nwayAt(x, y, nway, num, dist, type ,color, speed, add_speed, radian, add_rd, state)
		if (nway % 2 == 0)then angleMiddle = (radian * (nway/2)) - (radian/2) end
		if (nway % 2 == 1)then angleMiddle = radian * ((nway-1)/2) end
		for bl_num = 1 , nway do
			local angle = ((bl_num-1) * radian) + (add_rd - angleMiddle)
			for bl_num2 = 1 , num do
				Lazer.Create(x_dt(x, angle, dist),y_dt(y, angle, dist), type, color, speed + (bl_num2-1) * add_speed, angle, state)
				et_l.Prop()
				et_l.useParamProp(bl_num)
			end
		end
		et_l.PropClear()
	end
	function et_l.rd_add(bl_num, start_time, add_time, add_angle, state)
		if not(Lazer.getState1(bl_num) == state) then return end
		if not(et_l.between(LazCr.getCount(bl_num), start_time, add_time)) then return end
		Lazer.setAngle(Lazer.getAngle(bl_num) + add_angle)
	end

	function et_l.sp_up(bl_num, start_time, add_time, add_speed, state)
		if not(Lazer.getState1(bl_num) == state) then return end
		if not(et_l.between(LazCr.getCount(bl_num), start_time, add_time)) then return end
		Lazer.setSpeed(Lazer.getSpeed(bl_num) + add_speed)
	end

	function et_l.Prop()
		Lazer.setWho(lz_rayer)
		Lazer.setCount(lz_count)
		Lazer.setType(lz_stand_type)
		Lazer.setLength(lz_length)
		Lazer.setThick(lz_thick)
		Lazer.setLengthAngle(lz_length_angle)
		if(lz_is_collision)then Lazer.isCollision() end
		if(lz_is_bound)then Lazer.isBound() else Lazer.isNotBound() end
		if(lz_is_no_bound_angle)then Lazer.isNoBoundAngle() else Lazer.isBoundAngle() end
		if(lz_is_no_delete)then Lazer.isNoDelete() else Lazer.isDelete() end
	end
	function et_l.useParamProp(num)
		if(lz_num_in_st2)then
			Lazer.setState2(num)
		end
	end
	function et_l.PropClear()
		lz_boss_id = 0
		lz_rayer = 0
		lz_count = 0
		lz_length = 0
		lz_thick = 0
		lz_length_angle = 0
		lz_is_collision = false
		lz_is_bound=false
		lz_is_no_bound_angle=false
		lz_is_no_delete = false
		lz_num_in_st2=false
	end
--@EndScript