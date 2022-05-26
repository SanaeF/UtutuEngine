
function bullet6(rayer) se_play(BULLET01)--‚¤‚ç‚È’e–‹
	for n = 0 , 4 do
		rad = -PI / 5 * n
		Shot.Create(Player.getX_who(rayer), FMAX_Y, IMG.B_FLY, CL.RED, 2, rad, 6)
		Shot.setWho(rayer)
		et_s.rota(true)
		et_s.rayer(rayer)
		et_s.ringVecAt(Player.getX_who(rayer), FMAX_Y, num(8), r_dt(40), IMG.MINI_STAR, CL.BLUE, 2, rad, 6)
	end
end

--@EndScript