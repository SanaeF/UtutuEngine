PI = 3.141592
PI2 = PI*2

FMAX_X = 624*2--(624*2)
FMIN_X = 106--(106)
FMAX_Y = 1388
FMIN_Y = 52

F_MAX_X = FMAX_X-FMIN_X
F_MAX_Y = FMAX_Y-FMIN_Y
F_HALF_X = F_MAX_X/2
F_HALF_Y = F_MAX_Y/2

P1_MIN_X = 30
P1_MAX_X = 946
P2_MIN_X = 974
P2_MAX_X = 1890

DEF_BOSS_X = F_MAX_X / 2
DEF_BOSS_Y = 450

PLAYER1 = 1
PLAYER2 = 2

function HP(num)
	return num
end
function Time(num)
	return num
end
function hitOutCircle(x1, y1, x2, y2, range)
	x_dist = (x1-x2)
	y_dist = (y1-y2)
	dist = math.sqrt((x_dist * x_dist) + (y_dist * y_dist))
	if (dist > range) then
		return true
	end
	return false
end
function hitInCircle(x1, y1, x2, y2, range)
	x_dist = (x1-x2)
	y_dist = (y1-y2)
	dist = math.sqrt((x_dist * x_dist) + (y_dist * y_dist))
	if (dist < range) then
		return true
	end
	return false
end
function between(time, t0, t1)
	if t0 <= time and time <= t1 then
		return true
	end
	return false
end

function rand(num)
	return HelperFunc(num,"Func:Random")
end
function crush(size,time)
	return HelperFunc(size,time,"Func:Crush")
end
function sqrt(num)
	return math.sqrt(num)
end
function sin_(num)
	return math.sin(num)
end
function cos_(num)
	return math.cos(num)
end
function num(num)
	return num
end
function num_add(num)
	return num
end
function x_(num)
	return num
end
function y_(num)
	return num
end
function knd(num)
	return num
end
function col(num)
	return num
end
function sp(num)
	return num
end
function spup(num)
	return num
end
function rd_dt(num)
	return num
end
function rd(num)
	return num
end
function st(num)
	return num
end
function id(num)
	return num
end
function length(num)
	return num
end
function width(num)
	return num
end
function r_dt(num)
	return num
end
function t0(num)
	return num
end
function t1(num)
	return num
end
function x_dt(x, rd, dist)
	return x + math.cos(rd) * dist
end
function y_dt(y, rd, dist)
	return y + math.sin(rd) * dist
end
function homing(x1, y1, x2, y2)
	return math.atan2(y2 - y1, x2 - x1)
end

function E(num)
	return num
end
function N(num)
	return num
end
function H(num)
	return num
end
function VH(num)
	return num
end

function Param2(num1, num2)
	return num1,num2
end
function Param3(num1, num2, num3)
	return num1,num2,num3
end
function Param4(num1, num2, num3, num4)
	return num1,num2,num3,num4
end
--@EndScript