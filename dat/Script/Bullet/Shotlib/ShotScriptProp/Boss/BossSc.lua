Boss = {}
	function Boss.set(time, hp)
		BossFunc(time, true, "Func:InitTime")
		BossFunc(hp, true, "Func:InitHP")
	end
	function Boss.cooldown_(cooldown)
		BossFunc(cooldown, true, "Func:WaitTime")
	end
	function Boss.setLast()
		BossFunc(true, true, "Func:IsLast")
	end

	function Boss.set_x(x)
		ShotFunc(x, true, "Func:X")
	end
	function Boss.set_y(y)
		ShotFunc(y, true, "Func:Y")
	end
	function Boss.set_Time(time)
		BossFunc(time, true, "Func:Time")
	end
	function Boss.set_HP(hp)
		BossFunc(hp, true, "Func:HP")
	end
	function Boss.get_x()
		return BossFunc(false, false, "Func:X")
	end
	function Boss.get_y()
		return BossFunc(false, false, "Func:Y")
	end
	function Boss.get_Time()
		return BossFunc(false, false, "Func:Time")
	end
	function Boss.get_HP()
		return BossFunc(false, false, "Func:HP")
	end
	function Boss.mv(x, y, time)
		BossFunc("Func:moveFlag")
		BossFunc(x, y, time, "Func:setMove")
	end
	function Boss.mv_rand(x1, y1, x2, y2, dist, time)
		BossFunc("Func:moveRandFlag")
		BossFunc(x1, y1, x2, y2, dist, time, "Func:SetRandMove")
	end
function move(x, y, time)
	Boss.mv(x, y, time)
end
function move_rand(x1, y1, x2, y2, dist, time)
	Boss.mv_rand(x1, y1, x2, y2, dist, time)
end