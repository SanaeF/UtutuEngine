
function bullet0(rayer) se_play(BULLET01)--ˆ»”T’e–‹
	et_l.rayer(rayer)
	et_l.nwayAt(Player.getX_who(rayer), 100, 3, 1, 0, IMG.NORMAL , CL.BLUE, 7, 0, PI / 5, PI / 2, 0)
	et_s.bound(true)
	et_s.rayer(rayer)
	et_s.ringAt(Player.getX_who(rayer), 20, 13, 0, IMG.OVERLAP, CL.ORANGE, 4, 0, 0)
end

--@EndScript