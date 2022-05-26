Boss = {}
	function Boss.set(time, hp)
		BossFunc(time, true, "Func:InitTime")
		BossFunc(hp, true, "Func:InitHP")
		Boss.noDelMinion(false)
		Boss.setBulletState(0)
	end
	function Boss.summon(index,hp)
		Boss.initHP(index,hp)
	end
	function Boss.setX(index,x)
		BossFunc(x, true, index, "Func:X")
	end
	function Boss.setY(index,y)
		BossFunc(y, true, index, "Func:Y")
	end
	function Boss.initHP(index,hp)
		BossFunc(hp, true, index, "Func:InitHP")
	end
	function Boss.setHP(index,hp)
		BossFunc(hp, true, index, "Func:HP")
	end
	function Boss.mv(index, x, y, time)
		BossFunc(x, y, time, index, "Func:setMove")
	end
	function Boss.mv_rand(index, x1, y1, x2, y2, dist, time)
		BossFunc(x1, y1, x2, y2, dist, time, index, "Func:SetRandMove")
	end
	function Boss.charge(index)
		BossFunc(index, "Func:Charge")
	end
	function Boss.setDamageEffect(index,flag)
		BossFunc(flag,index, "Func:SetDeathEffect")
	end
	function Boss.setMotion(index,type)
		return BossFunc(type, index, "Func:MotionType")
	end
	function Boss.setSerifBox(x,y,time,text)
		BossFunc(x,y,time,text,"Func:SerifBox")
	end

	function Boss.getX(index)
		return BossFunc(false, false, index, "Func:X")
	end
	function Boss.getY(index)
		return BossFunc(false, false, index, "Func:Y")
	end


function boss_SE(type)
	if(shot_time > 0)then se_play(type) end
end
function move(x, y, time)
	Boss.mv(0,x, y, time)
end
function move_rand(x1, y1, x2, y2, dist, time)
	Boss.mv_rand(0,x1, y1, x2, y2, dist, time)
end
--@EndScript