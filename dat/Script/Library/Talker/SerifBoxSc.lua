direction = 0
Massage = {}
function Massage.setBoxL()
	Massage.reset()
	direction = 0
	DirFunc(0)
end
function Massage.setBoxR()
	Massage.reset()
	direction = 1
	DirFunc(1)
end
function Massage.setBoxGray()
	direction = 2
	DirFunc(2)
end
function Massage.set_et( id, x, y, size, text)
	SetBoxFunc()
	BoxFunc( id, x, y, size, text)
end
function Massage.setName(text)
	SetBoxFunc()
	BoxFunc( 0, 592 + direction * 520, 980, 50, text)
end
function Massage.Text(text1,text2,text3)
	SetBoxFunc()
	pos_x = 282 + 180
	BoxFunc( 1, pos_x, 1100, 45, text1)
	BoxFunc( 2, pos_x, 1180, 45, text2)
	BoxFunc( 3, pos_x, 1260, 45, text3)
end
function Massage.MiddleText(size, text)
end

function Massage.setColor(id,r,g,b)
	TextColorFunc(id,r,g,b)
end

function Massage.reset()
Massage.setColor(0,255,255,255)
Massage.setColor(1,255,255,255)
Massage.setColor(2,255,255,255)
Massage.setColor(3,255,255,255)
Massage.setColor(4,255,255,255)
end

--@EndScript