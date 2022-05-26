Player = {}
	function Player.setX(x)
		PlayerFunc("Func:X", x, true)
	end
	function Player.setY(y)
		PlayerFunc("Func:Y", y, true)
	end
	function Player.setItemApple(num)
		return PlayerFunc("Func:ItemApple", num, true)
	end
	function Player.getX()
		return PlayerFunc("Func:X", false, false)
	end
	function Player.getY()
		return PlayerFunc("Func:Y", false, false)
	end
	function Player.getItemApple()
		return PlayerFunc("Func:ItemApple", false, false)
	end

	function Player.getP1X()
		return PlayerFunc("Func:GetP1X", false, false)
	end
	function Player.getP1Y()
		return PlayerFunc("Func:GetP1Y", false, false)
	end
	function Player.getP2X()
		return PlayerFunc("Func:GetP2X", false, false)
	end
	function Player.getP2Y()
		return PlayerFunc("Func:GetP2Y", false, false)
	end
	function Player.getType()
		return PlayerFunc("Func:GetType", false, false)
	end
	function Player.getTypeRayer(who)
		if(who == PLAYER1)then rayer = 0 end
		if(who == PLAYER1)then rayer = 1 end
		return PlayerFunc("Func:GetType", false, rayer)
	end
	function Player.getX_who(who)
		if(who == PLAYER1)then return Player.getP1X() end
		if(who == PLAYER2)then return Player.getP2X() end
	end
	function Player.getY_who(who)
		if(who == PLAYER1)then return Player.getP1Y() end
		if(who == PLAYER2)then return Player.getP2Y() end
	end

	function Player.getIsHide(who)
		return PlayerFunc("Func:GetIsHide", false, who)
	end
	function Player.getKeyInput(who, keyNum)
		if(who == PLAYER1)then PlayerWho = 0 end
		if(who == PLAYER2)then PlayerWho = 1 end
		return PlayerFunc("Func:GetKeyInput", keyNum, PlayerWho)
	end
	function Player.bossWho()
		if(Player.getIsHide(0))then return PLAYER1 end
		if(Player.getIsHide(1))then return PLAYER2 end
	end
	function Player.bossNotWho()
		if(Player.getIsHide(0))then return PLAYER2 end
		if(Player.getIsHide(1))then return PLAYER1 end
	end
--@EndScript