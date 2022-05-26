dofile('./dat/Script/TimeLine/PlayerBullet/Pattern/at0.lua')
dofile('./dat/Script/TimeLine/PlayerBullet/Pattern/at1.lua')
dofile('./dat/Script/TimeLine/PlayerBullet/Pattern/at2.lua')
dofile('./dat/Script/TimeLine/PlayerBullet/Pattern/at3.lua')
dofile('./dat/Script/TimeLine/PlayerBullet/Pattern/at4.lua')
dofile('./dat/Script/TimeLine/PlayerBullet/Pattern/at5.lua')
dofile('./dat/Script/TimeLine/PlayerBullet/Pattern/at6.lua')

function PlayerBullet(flag,rayer)--‘ŠŽè‚É‘—‚é’e–‹ƒŠƒXƒg
	BulletTrans()
	if not(flag)then return end
	if(rayer == PLAYER1)then shot_rayer = PLAYER2 end
	if(rayer == PLAYER2)then shot_rayer = PLAYER1 end
	type = Player.getType(shot_rayer)
	if(type == 0)then bullet0(shot_rayer) end
	if(type == 1)then bullet1(shot_rayer) end
	if(type == 2)then bullet2(shot_rayer) end
	if(type == 3)then bullet3(shot_rayer) end
	if(type == 4)then bullet4(shot_rayer) end
	if(type == 5)then bullet5(shot_rayer) end
	if(type == 6)then bullet6(shot_rayer) end
end

function BulletTrans()
	for bl_num = 0, SHOT_MAX do
		if(Shot.isFlag(bl_num))then
			if(Shot.getState1(bl_num) == 0)then
				if (Shot.getBoundCount(bl_num) > 0)then Shot.isNotBound() end
			end
			if(Shot.getState1(bl_num) == 1)then
				if (Shot.getCount(bl_num) < 200)then
					if(Shot.getState2(bl_num) == 0)then Shot.addAngle(PI / 2 / 200) end
					if(Shot.getState2(bl_num) == 1)then Shot.addAngle(-PI / 2 / 200) end
				end
			end
			if(Shot.getState1(bl_num) == 2)then
				if (Shot.getBoundCount(bl_num) == 3)then Shot.clear() end
				if (Shot.getCount(bl_num) < 260 and Shot.getCount(bl_num) % 62 == 30)then
					angle = rand(PI / 2)
					et_s.rota(true)
					et_s.rayer(Shot.getWho(bl_num))
					et_s.ringAt(Shot.getX(bl_num), Shot.getY(bl_num), 3, 0, IMG.MINI_STAR, CL.SKY, 2, angle, 0)
				end
			end
		end
	end
	for bl_num = 0, LAZER_MAX do 
		if (Lazer.isFlag(bl_num))then
			if(Lazer.getState1(bl_num) == 0)then
				if (Lazer.getCount(bl_num) <10)then
					Lazer.addThick(0.75)
					Lazer.addLength(10)
					Lazer.isCollision()
				end
			end
			if(Lazer.getState1(bl_num) == 3)then
				if(between(Lazer.getCount(bl_num), 30, 40))then Lazer.addThick(1) end
				if(Lazer.getCount(bl_num) == 40)then Lazer.isCollision() end
				if(between(Lazer.getCount(bl_num), 110, 120))then Lazer.addThick(-1) end
				if(Lazer.getCount(bl_num) == 120)then
					Lazer.isNotCollision()
					Lazer.clear()
				end
			end
			if(Lazer.getState1(bl_num) == 4)then
				Lazer.setY(Lazer.getY(bl_num) + 2)
				if(Lazer.getCount(bl_num) < 10)then Lazer.addThick(1)
				else Lazer.isCollision() end
				Lazer.setLength(120)
				Lazer.addAngle(PI2 / 90)
			end
		end
	end
end

--@EndScript