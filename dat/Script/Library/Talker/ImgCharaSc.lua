ACCENT=0
HAPPY=1
SWEAT=2
BLACK=3
ANGRY=4
STOP=5

chara_num = 0
Chara={}
function Chara.create_ID(id)
	CharaFunc(id + 1, "Func:AddChara")
end
function Chara.isBack(id, flag)
	CharaFunc(id, flag, "Func:Back")
end
function Chara.spawn(id, chara, x, y, size)
	CharaFunc(id, true, "Func:Flag")
	CharaFunc(id, chara, "Func:SetType")
	CharaFunc(id,  x, y, "Func:SetPos")
	Chara.setSize(id, size)
	Chara.eye(id, 1)
	Chara.mouth(id, 0)
	Chara.isBack(id, false)
end
function Chara.spawnFacial(id, type, x, y)
	CharaFunc(id, type, x, y, "Func:FacialEffect")
end
function Chara.hide(id)
	CharaFunc(id, false, "Func:Flag")
end
function Chara.Type(id, chara)
	CharaFunc(id, chara, "Func:SetType")
end
function Chara.setPos(id, x, y)
	CharaFunc(id,  x, y, "Func:SetPos")
end
function Chara.setSize(id, size)
	CharaFunc(id, size, "Func:SetSize")
end
function Chara.body(id, state)
	CharaFunc(id, state, "Func:BodyState")
end
function Chara.eye(id, state)
	CharaFunc(id, state, "Func:EyeState")
end
function Chara.brow(id, state)
	CharaFunc(id, state, "Func:BrowState")
end
function Chara.mouth(id, state)
	CharaFunc(id, state, "Func:MouthState")
end

function Chara.img(id, brow, eye, mouth, is_back)
	Chara.brow(id, brow)
	Chara.eye(id, eye)
	Chara.mouth(id, mouth)
	Chara.isBack(id, is_back)
end

function tag(num)
	return num
end
function brow(num)
	return num
end
function eye(num)
	return num
end
function mouth(num)
	return num
end
function back(num)
	return num
end

--@EndScript