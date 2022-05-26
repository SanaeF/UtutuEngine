Player = {}
	function Player.setX(x)
		PlayerFunc("Func:X", x, true)
	end
	function Player.setY(y)
		PlayerFunc("Func:Y", y, true)
	end
	function Player.getX()
		return PlayerFunc("Func:X", false, false)
	end
	function Player.getY()
		return PlayerFunc("Func:Y", false, false)
	end