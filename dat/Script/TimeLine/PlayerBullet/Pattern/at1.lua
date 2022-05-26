
function bullet1(rayer) se_play(BULLET01)--‚Ý‚³‚Æ’e–‹
	px, py = Param2(Player.getX_who(rayer), Player.getY_who(rayer))
	for i=0,11 do
		angle = PI - PI / 12 * i + rand(PI / 2)
		Shot.Create(x_dt(px, angle, 400), y_dt(py, angle, 400), IMG.POIFUL, CL.YELLOW, -3, angle, 1)
		Shot.setState2(i % 2)
		Shot.setWho(rayer)
	end
end

--@EndScript