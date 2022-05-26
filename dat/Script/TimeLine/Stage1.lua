dofile('./dat/Script/Library/Timeline/TimelineSc.lua')
dofile('./dat/Script/Timeline/ItemMinion/ItemMinion.lua')
dofile('./dat/Script/MinionProp/Bullet/Stage1/MinionBullet.lua')
dofile('./dat/Script/MinionProp/Move/Stage1/MinionMover.lua')

resetTime(6000)

function TimeLine()
	f_max = FMAX_X - FMIN_X
	--ばらまき突進
	if (isTime(50)or
		isTime(70)or
		isTime(90)or
		isTime(110)or
		isTime(130)or
		isTime(150)or
		isTime(170)or
		isTime(190)) then
		x=f_max/2+rand(f_max/2)
		y=300+rand(200)
		en_spawn(x, y, DEV_NORMAL, 120, 0, 0)
		en_bullet(IMG.MINI_STAR, CL.GREEN)
		en_item(PowerGhost, 3)
	end

	if (isTime(1300))then TL.setSubTitle() end
	--ホーミング突進
	f_time = 1500
	if (isTime(f_time)or
		isTime(f_time+30)or
		isTime(f_time+60)or
		isTime(f_time+90)or
		isTime(f_time+120)or
		isTime(f_time+150)or
		isTime(f_time+180)or
		isTime(f_time+210)or
		isTime(f_time+240)or
		isTime(f_time+270)or
		isTime(f_time+300)or
		isTime(f_time+330)or
		isTime(f_time+360)or
		isTime(f_time+390)or
		isTime(f_time+420)) then
		x=f_max/2+rand(f_max/2)
		en_spawn(x, 20, DEV_NORMAL, 110, 1, 0)
		en_bullet(IMG.BIG,CL.BLUE)
		if(isTime(f_time+420))then item=Apple
		else item=PowerGhost
		end
		en_item(item, 2)
	end

	--回転デビルボーン
	if (isTime(2090))then
		en_spawn(f_max/2+300, 500, DEV_BONE, 210, 2, 1)
		en_bullet(IMG.SCALY,CL.PINK)
		en_item(PowerGhost, 5)
	end
	if (isTime(2120))then
		en_spawn(f_max/2+300, 500, DEV_BONE, 210, 2, 1)
		en_bullet(IMG.SCALY,CL.PINK)
		en_item(PowerGhost, 5)
	end

	if (isTime(2400))then
		en_spawn(f_max/2-300, 500, DEV_BONE, 380, 2, 2)
		en_bullet(IMG.SCALY,CL.ORANGE)
		en_item(PowerGhost, 6)
	end
	if (isTime(2430))then
		en_spawn(f_max/2-300, 500, DEV_BONE, 380, 2, 2)
		en_bullet(IMG.SCALY,CL.ORANGE)
		en_item(PowerGhost, 6)
	end
	--交差ヤロウ
	if (isTime(2800))then
		en_spawn(f_max/2, -20, DEV_ORANGE, 800, 3, 3)
		en_bullet(IMG.RICE,CL.YELLOW)
		en_item(Apple, 2)
	end

	f_time = 3350
	if (isTime(f_time)or
		isTime(f_time+10)or
		isTime(f_time+20)or
		isTime(f_time+30)or
		isTime(f_time+40)or
		isTime(f_time+50)or
		isTime(f_time+60)or
		isTime(f_time+70)or
		isTime(f_time+80)or
		isTime(f_time+90)or
		isTime(f_time+100)or
		isTime(f_time+110)or
		isTime(f_time+120)or
		isTime(f_time+130)or
		isTime(f_time+140)) then
		en_spawn(-20, 600, DEV_NORMAL, 10, 4, 4)
		en_bullet(IMG.SCALY,CL.GREEN)
		if(isTime(f_time+140))then item=Apple
		else item=PowerGhost
		end
		en_item(item, 2)
	end

	f_time = 3500
	if (isTime(f_time)or
		isTime(f_time+10)or
		isTime(f_time+20)or
		isTime(f_time+30)or
		isTime(f_time+40)or
		isTime(f_time+50)or
		isTime(f_time+60)or
		isTime(f_time+70)or
		isTime(f_time+80)or
		isTime(f_time+90)or
		isTime(f_time+100)or
		isTime(f_time+110)or
		isTime(f_time+120)or
		isTime(f_time+130)or
		isTime(f_time+140)) then
		en_spawn(f_max+20, 600, DEV_NORMAL, 10, 4, 5)
		en_bullet(IMG.SCALY,CL.PINK)
		if(isTime(f_time+140))then item=Apple
		else item=PowerGhost
		end
		en_item(item, 2)
	end

	f_time = 3650
	if (isTime(f_time)or
		isTime(f_time+10)or
		isTime(f_time+20)or
		isTime(f_time+30)or
		isTime(f_time+40)or
		isTime(f_time+50)or
		isTime(f_time+60)or
		isTime(f_time+70)or
		isTime(f_time+80)or
		isTime(f_time+90)or
		isTime(f_time+100)or
		isTime(f_time+110)or
		isTime(f_time+120)or
		isTime(f_time+130)or
		isTime(f_time+140)) then
		en_spawn(-20, 800, DEV_NORMAL, 10, 4, 4)
		en_bullet(IMG.SCALY,CL.GREEN)
		en_item(PowerGhost, 7)
	end

	f_time = 3800
	if (isTime(f_time)or
		isTime(f_time+10)or
		isTime(f_time+20)or
		isTime(f_time+30)or
		isTime(f_time+40)or
		isTime(f_time+50)or
		isTime(f_time+60)or
		isTime(f_time+70)or
		isTime(f_time+80)or
		isTime(f_time+90)or
		isTime(f_time+100)or
		isTime(f_time+110)or
		isTime(f_time+120)or
		isTime(f_time+130)or
		isTime(f_time+140)) then
		en_spawn(f_max+20, 800, DEV_NORMAL, 10, 4, 5)
		en_bullet(IMG.SCALY,CL.PINK)
		en_item(PowerGhost, 7)
	end

	enter_boss_time = 5000
	if (isTime(enter_boss_time))then TL.setTalkScene(2) end--会話シーンへ移行
	if (isTime(enter_boss_time+10))then TL.setTalkScene(3) end--会話シーンへ移行
	if (isTime(enter_boss_time+40))then TL.endStage() end

	--道中の挙動と特殊演出
	for i=0,MINION_MAX do
		if(Minion.isFlag(i))then
			MinionBulletUpdate(i)
			MinionMoveUpdate(i)
		end
	end
	MinionBulletTrans()--弾幕の変化
	ItemMinion()--アイテムballoonの召喚
end

--@EndScript