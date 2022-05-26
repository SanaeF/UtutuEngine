et_lc = {
	lc_boss_id=0,
	lc_size = 1,
	lc_bound = false,
	lc_outside_rd = 0,
	lc_rayer = 0,
	lc_state2 = 0
}
	function et_lc.between(time, t0, t1)
		if t0 <= time and time <= t1 then
			return true
		end
		return false
	end
	function et_lc.boss_id(num)
		lc_boss_id = num
	end
	function et_lc.bound(flag)
		lc_bound = flag
	end
	function et_lc.ringAt(x, y, num, dist, length, color, speed, add_rd, state)
		for bl_num = 1 , num do
			local angle = ((bl_num * PI2) / num) + add_rd
			LazCr.Create(x_dt(x, angle, dist), y_dt(y, angle, dist), length, color, speed, angle, state)
			et_lc.Prop()
		end
		et_lc.PropClear()
	end
	function et_lc.ring(num, dist, length, color, speed, add_rd, state)
		et_lc.ringAt(Boss.getX(lc_boss_id), Boss.getY(lc_boss_id), num, dist, length, color, speed, add_rd, state)
		et_lc.PropClear()
	end
	function et_lc.rd_add(bl_num, start_time, add_time, add_angle, state)
		if not(LazCr.getState1(bl_num) == state) then return end
		if not(et_lc.between(LazCr.getCount(bl_num), start_time, add_time)) then return end
		LazCr.setAngle(LazCr.getAngle(bl_num) + add_angle)
	end
	function et_lc.sp_up(bl_num, start_time, add_time, add_speed, state)
		if not(LazCr.getState1(bl_num) == state) then return end
		if not(et_lc.between(LazCr.getCount(bl_num), start_time, add_time)) then return end
		LazCr.setAngle(LazCr.getAngle(bl_num) + add_angle)
	end
	function et_lc.nway(length, nway, dist, color, speed, radian, add_rd, state)
		et_lc.nwayAt(Boss.getX(lc_boss_id), Boss.getY(lc_boss_id), length, nway, dist, color, speed, radian, add_rd, state)
		et_lc.PropClear()
	end
	function et_lc.nwayAt(x, y, length, nway, dist, color, speed, radian, add_rd, state)
		if (nway % 2 == 0)then angleMiddle = (radian * (nway/2)) - (radian/2) end
		if (nway % 2 == 1)then angleMiddle = radian * ((nway-1)/2) end
		for bl_num = 1 , nway do
			local angle = ((bl_num-1) * radian) + (add_rd - angleMiddle)
			LazCr.Create(x_dt(x, angle, dist),y_dt(y, angle, dist), length, color, speed, angle, state)
			et_lc.Prop()
		end
		et_lc.PropClear()
	end

	function et_lc.Prop()
		--LazCr.setSize(et_size)
		LazCr.setWho(lc_rayer)
		LazCr.setState2(lc_state2)
		if (lc_bound)then LazCr.isBound() else LazCr.isNotBound() end
	end
	function et_lc.PropClear()
		lc_boss_id = 0
		lc_state2 = 0
		lc_rayer = 0
		lc_size = 1
		lc_bound = false
	end

	function et_lc.clear()
		for bl_num = 0, T_LAZ_MAX do
			if(LazCr.isFlag(bl_num))then
				LazCr.clear()
			end
		end
	end
--@EndScript