AREA_LEFT = 1
AREA_RIGHT = 2
AREA_UP = 3
AREA_DOWN = 4

et_s = {
	s_boss_id=0,
	s_size = 1,
	s_bound = false,
	s_rota = false,
	s_shine = false,
	s_num_in_st2 = false,
	s_no_delete = false,
	s_outside_rd = 0,
	s_rayer = 0,
	s_state2 = 0
}
	function et_s.between(time, t0, t1)
		if t0 <= time and time <= t1 then
			return true
		end
		return false
	end
	function et_s.boss_id(num)
		s_boss_id = num
	end
	function et_s.size(num)
		s_size = num
	end
	function et_s.shine(flag)
		s_shine = flag
	end
	function et_s.rota(flag)
		s_rota = flag
	end
	function et_s.bound(flag)
		s_bound = flag
	end
	function et_s.state2(num)
		s_state2 = num
	end
	function et_s.numInState2(flag)
		s_num_in_st2 = flag
	end
	function et_s.noDelete(flag)
		s_no_delete = flag
	end
	function et_s.rayer(num)
		s_rayer = num
	end
	function et_s.ringAt(x, y, num, dist, type, color, speed, add_rd, state)
		if(num == 0)then return end
		for bl_num = 1 , num do
			local angle = ((bl_num * PI2) / num) + add_rd
			Shot.Create(x_dt(x, angle, dist),y_dt(y, angle, dist), type, color, speed, angle, state)
			et_s.Prop()
			et_s.useParamProp(bl_num)
		end
		et_s.PropClear()
	end
	function et_s.ring(num, dist, type, color, speed, add_rd, state)
		if(num == 0)then return end
		et_s.ringAt(Boss.getX(s_boss_id), Boss.getY(s_boss_id),num, dist, type ,color, speed, add_rd, state)
		et_s.PropClear()
	end

	function et_s.ringVecAt(x, y, num, dist, type, color, speed, angle, state)
		if(num == 0)then return end
		for bl_num = 1 , num do
			local rad = ((bl_num * PI2) / num) + angle
			Shot.Create(x_dt(x, rad, dist),y_dt(y, rad, dist), type, color, speed, angle, state)
			et_s.Prop()
			et_s.useParamProp(bl_num)
		end
		et_s.PropClear()
	end
	function et_s.ringVec(num, dist, type, color, speed, angle, state)
		if(num == 0)then return end
		et_s.ringVecAt(Boss.getX(s_boss_id), Boss.getY(s_boss_id), num, dist, type ,color, speed, angle, state)
		et_s.PropClear()
	end

	function et_s.nwayAt(x, y, nway, num, dist, type ,color, speed, add_speed, space_rd, add_rd, state)
		if(num == 0)then return end
		if (nway % 2 == 0)then angleMiddle = (space_rd * (nway/2)) - (space_rd/2) end
		if (nway % 2 == 1)then angleMiddle = space_rd * ((nway-1)/2) end
		for bl_num = 1 , nway do
			local angle = ((bl_num-1) * space_rd) + (add_rd - angleMiddle)
			for bl_num2 = 1 , num do
				Shot.Create(x_dt(x, angle, dist),y_dt(y, angle, dist), type, color, speed + (bl_num2-1) * add_speed, angle, state)
				et_s.Prop()
				et_s.useParamProp(bl_num)
			end
		end
		et_s.PropClear()
	end
	function et_s.nway(nway, num, dist, type ,color, speed, add_speed, space_rd, add_rd, state)
		if(num == 0)then return end
		et_s.nwayAt(Boss.getX(s_boss_id), Boss.getY(s_boss_id), nway, num, dist, type ,color, speed, add_speed, space_rd, add_rd, state)
		et_s.PropClear()
	end

	function et_s.outside(area, type ,color, speed, add_rd, state)
		if(area < 1) then return 0 end
		if area == AREA_LEFT then
			outside_x = 0
			outside_y = ((FMAX_Y - FMIN_Y) / 2)+rand((FMAX_Y - FMIN_Y) / 2)
			outside_rd = 0
		end
		if area == AREA_RIGHT then
			outside_x = FMAX_X - FMIN_X
			outside_y = ((FMAX_Y - FMIN_Y) / 2)+rand((FMAX_Y - FMIN_Y) / 2)
			outside_rd = PI
		end
		if area == AREA_UP then
			outside_x = ((FMAX_X - FMIN_X) / 2)+rand((FMAX_X - FMIN_X) / 2)
			outside_y = 0
			outside_rd = PI/2
		end
		if area == AREA_DOWN then
			outside_x = ((FMAX_X - FMIN_X) / 2)+rand((FMAX_X - FMIN_X) / 2)
			outside_y = FMAX_Y - FMIN_Y
			outside_rd = PI + PI/2
		end
		Shot.Create(outside_x, outside_y, type, color, speed, outside_rd + add_rd, state)
		et_s.Prop()
		et_s.PropClear()
		return Shot.id()
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

	function et_s.Prop(num)
		Shot.setSize(s_size)
		Shot.setWho(s_rayer)
		Shot.setState2(s_state2)
		if (s_shine)then Shot.isShine() else Shot.isNotShine() end
		if (s_rota)then Shot.isRota() else Shot.isNotRota() end
		if (s_bound)then Shot.isBound() else Shot.isNotBound() end
		if (s_no_delete)then Shot.isNoDelete() else Shot.isDelete() end
	end
	function et_s.useParamProp(num)
		if(s_num_in_st2)then
			Shot.setState2(num)
		end
	end
	function et_s.PropClear()
		s_boss_id = 0
		s_state2 = 0
		s_rayer = 0
		s_size = 1
		s_bound = false
		s_rota = false
		s_shine = false
		s_num_in_st2=false
		s_no_delete = false
	end

	function et_s.clear()
		for bl_num = 0, SHOT_MAX do
			if(Shot.isFlag(bl_num))then
				Shot.clear()
			end
		end
	end
--@EndScript