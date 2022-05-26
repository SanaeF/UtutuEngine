PI = 3.141592
PI2 = PI*2
function HP(num)
	return num
end
function Time(num)
	return num
end
function between(time, t0, t1)
	if t0 <= time and time <= t1 then
		return true
	end
	return false
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
function rd(num)
	return num
end
function st_(num)
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
	return math.atan2(x2-x1,y2-y1)
end
function diff(easy, normal, hard, v_hard)
	if difficulty==0 then return easy end
	if difficulty==1 then return normal end
	if difficulty==2 then return hard end
	if difficulty==3 then return v_hard end
	return -1
end
function knd_(easy, normal, hard, v_hard)
	if difficulty==0 then return easy end
	if difficulty==1 then return normal end
	if difficulty==2 then return hard end
	if difficulty==3 then return v_hard end
	return -1
end
function col_(easy, normal, hard, v_hard)
	if difficulty==0 then return easy end
	if difficulty==1 then return normal end
	if difficulty==2 then return hard end
	if difficulty==3 then return v_hard end
	return -1
end
function sp_(easy, normal, hard, v_hard)
	if difficulty==0 then return easy end
	if difficulty==1 then return normal end
	if difficulty==2 then return hard end
	if difficulty==3 then return v_hard end
	return -1
end
function rd_(easy, normal, hard, v_hard)
	if difficulty==0 then return easy end
	if difficulty==1 then return normal end
	if difficulty==2 then return hard end
	if difficulty==3 then return v_hard end
	return -1
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