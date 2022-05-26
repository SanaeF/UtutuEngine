
function bullet5(rayer) se_play(BULLET01)--‚Ü‚É‚í’e–‹
	px, py = Param2(Player.getX_who(rayer), Player.getY_who(rayer))
	et_s.rayer(rayer)
	et_s.rota(true)
	et_s.ringAt(px, py - 430, 7, 0, IMG.MINI_STAR, CL.RED, 3, 0, 5)
	et_s.rayer(rayer)
	et_s.rota(true)
	et_s.ringAt(px + 300, py - 630, 7, 0, IMG.MINI_STAR, CL.BLUE, 3, 0, 5)
	et_s.rayer(rayer)
	et_s.rota(true)
	et_s.ringAt(px - 300, py - 630, 7, 0, IMG.MINI_STAR, CL.BLUE, 3, 0, 5)
end

--@EndScript