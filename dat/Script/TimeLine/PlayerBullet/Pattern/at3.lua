
function bullet3(rayer) se_play(LAZER01)--•Q’e–‹
	PosX = Player.getX_who(rayer) + (P1_MAX_X - P1_MIN_X) / 2 + rand(((P1_MAX_X - P1_MIN_X) / 2))
	et_l.rayer(rayer)
	et_l.size(2000, 2)
	et_l.nwayAt(PosX, 70, 3, 1, 0, IMG.LAZER , CL.GREEN, 0, 0, PI / 6, PI / 2, 3)

	rad = -PI + rand(PI / 12)
	et_s.rayer(rayer)
	et_s.ringAt(PosX, 60, 3, 0, IMG.OVERLAP, CL.ORANGE, 3 + rand(2), rad , 3)
	et_s.rayer(rayer)
	et_s.ringAt(PosX, 60, 3, 0, IMG.OVERLAP, CL.ORANGE, 3 + rand(2), PI / 3 + rad , 3)
end

--@EndScript