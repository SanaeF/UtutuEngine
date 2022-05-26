
function prop(time, hp)
	setTime(time)
	Boss.initHP(0,hp)
end
function summon(index,x,y,type,hp)
	BulletFunc(x,y,type,index, "Func:Summon")
	Boss.initHP(index,hp)
	Boss.setDamageEffect(index,false)
end
function resetPosition()
	BulletFunc("Func:ResetPosition")
end
function returnBackPosition(flag)
	BulletFunc(flag,"Func:ReturnBackPosition")
end
function setWaitTime(time)
	BulletFunc(time, "Func:SetWaitTime")
end
function setTime(time)
	BulletFunc(time + 1, true, "Func:Timer")
end
function setInvalidBom(flag)
	BulletFunc(flag, true, "Func:SetInvalidBom")
end
function setInbicible(flag)
	BulletFunc(flag, true, "Func:SetInbicible")
end
function setSpecialBullet(flag)
	BulletFunc(flag, true, "Func:SetSpecialBullet")
end
function setReturnBack(flag)
	BulletFunc(flag, true, "Func:SetReturnBack")
end
function setDeathEffect(flag)
	BulletFunc(flag, true, "Func:SetDeathEffect")
end
function drawSerifBox(x,y,time,text)
	BulletFunc(x,y,time,text,"Func:SetSerifBox")
end
function getTime()
	time = BulletFunc(false, false, "Func:Timer")
	return time / 60
end