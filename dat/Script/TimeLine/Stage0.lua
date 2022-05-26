dofile( './dat/Script/Library/Timeline/TimelineSc.lua' )
dofile( './dat/Script/Timeline/ItemMinion/ItemMinion.lua' )
dofile( './dat/Script/MinionProp/Bullet/Stage0/MinionBullet.lua' )
dofile( './dat/Script/MinionProp/Move/Stage0/MinionMover.lua' )
--広瀬すず
resetTime(6000)

function TimeLine()
	f_max = FMAX_X - FMIN_X
	if (isTime(50)) then TL.setSubTitle() end
	--右から連射
	if (isTime(250)or
		isTime(280)or
		isTime(310)or
		isTime(340)) then
		en_spawn(f_max - 200, 0, DEV_NORMAL, 60, 0, 0)
		en_bullet(IMG.NORMAL,CL.PINK)
		en_item(PowerGhost, 1)
	end
	--左から連射
	if (isTime(450)or
		isTime(480)or
		isTime(510)or
		isTime(540)) then
		en_spawn(200, 0, DEV_NORMAL, 60, 0, 1)
		en_bullet(IMG.NORMAL,CL.PINK)
		en_item(PowerGhost, 1)
	end
	--左右から交互に連射
	if (isTime(600)or
		isTime(660)or
		isTime(720)) then
		en_spawn(f_max - 100, 0, DEV_NORMAL, 60, 0, 0)
		en_bullet(IMG.NORMAL,CL.PURPLE)
		en_item(PowerGhost, 1)
	end
	if (isTime(630)or
		isTime(690)or
		isTime(750)) then
		en_spawn(100, 0, DEV_NORMAL, 60, 0, 1)
		en_bullet(IMG.NORMAL,CL.PURPLE)
		en_item(PowerGhost, 1)
	end
	--第1リンゴ
	if (isTime(800)) then
		en_spawn(f_max/2, 0, DEV_ORANGE, 480, 1, 2)
		en_bullet(IMG.POIFUL,CL.RED)
		en_item(Apple, 1)
	end
	--リズムを刻んで出てくる
	if (isTime(1220)) then
		en_spawn(100, 0, DEV_BONE, 120, 2, 2)
		en_bullet(IMG.OVERLA,CL.PINK)
		en_item(PowerGhost, 5)
	end
	if (isTime(1245)) then
		en_spawn(300, 0, DEV_BONE, 120, 2, 2)
		en_bullet(IMG.OVERLA,CL.PINK)
		en_item(PowerGhost, 5)
	end
	if (isTime(1270)) then
		en_spawn(500, 0, DEV_BONE, 120, 2, 2)
		en_bullet(IMG.OVERLA,CL.PINK)
		en_item(PowerGhost, 5)
	end
	if (isTime(1295)) then
		en_spawn(700, 0, DEV_BONE, 120, 2, 2)
		en_bullet(IMG.OVERLA,CL.PINK)
		en_item(PowerGhost, 5)
	end
	if (isTime(1310)) then
		en_spawn(f_max - 100, 0, DEV_BONE, 120, 2, 2)
		en_bullet(IMG.OVERLA,CL.YELLOW)
		en_item(PowerGhost, 5)
	end
	if (isTime(1335)) then
		en_spawn(f_max - 300, 0, DEV_BONE, 120, 2, 2)
		en_bullet(IMG.OVERLA,CL.YELLOW)
		en_item(PowerGhost, 5)
	end
	if (isTime(1360)) then
		en_spawn(f_max - 500, 0, DEV_BONE, 120, 2, 2)
		en_bullet(IMG.OVERLA,CL.YELLOW)
		en_item(PowerGhost, 5)
	end
	if (isTime(1385)) then
		en_spawn(f_max - 700, 0, DEV_BONE, 120, 2, 2)
		en_bullet(IMG.OVERLA,CL.YELLOW)
		en_item(PowerGhost, 5)
	end
	--第2リンゴ
	if (isTime(1600)) then
		en_spawn(f_max/2, 0, DEV_ORANGE, 450, 1, 2)
		en_bullet(IMG.POIFUL,CL.ORANGE)
		en_item(Apple, 1)
	end
	if (isTime(1700)or
		isTime(1730)or
		isTime(1760)or
		isTime(1790)or
		isTime(1820)) then
		en_spawn(f_max - 100, 200, DEV_NORMAL, 60, 0, 3)
		en_bullet(IMG.RICE,CL.BLUE)
		en_item(PowerGhost, 1)
		en_spawn(100, 200, DEV_NORMAL, 60, 0, 3)
		en_bullet(IMG.RICE,CL.BLUE)
		en_item(PowerGhost, 1)
	end
	--フォーメーションリズム1960
	if (isTime(1960))then
		en_spawn(100, 50, DEV_GREEN, 80, 3, 5)
		en_bullet(IMG.RICE, CL.PINK)
		en_item(PowerGhost, 5)
		en_spawn(f_max - 100, 50, DEV_GREEN, 80, 4, 4)
		en_bullet(IMG.RICE, CL.PINK)
		en_item(PowerGhost, 5)
	end
	if (isTime(2160))then
		en_spawn(200, 50, DEV_GREEN, 80, 3, 5)
		en_bullet(IMG.RICE, CL.GREEN)
		en_item(PowerGhost, 5)
		en_spawn(f_max - 200, 50, DEV_GREEN, 80, 4, 4)
		en_bullet(IMG.RICE, CL.GREEN)
		en_item(PowerGhost, 5)
	end
	if (isTime(2260))then
		en_spawn(400, 50, DEV_GREEN, 80, 3, 5)
		en_bullet(IMG.RICE, CL.CYAN)
		en_item(PowerGhost, 5)
		en_spawn(f_max - 400, 50, DEV_GREEN, 80, 4, 4)
		en_bullet(IMG.RICE, CL.CYAN)
		en_item(PowerGhost, 5)
	end
	if (isTime(3100))then
		en_spawn(300, 50, DEV_GREEN, 80, 3, 5)
		en_bullet(IMG.RICE, CL.PURPLE)
		en_item(PowerGhost, 5)
		en_spawn(f_max - 300, 50, DEV_GREEN, 80, 4, 4)
		en_bullet(IMG.RICE, CL.PURPLE)
		en_item(PowerGhost, 5)
	end
	if (isTime(3600))then TL.setInterBoss(N05_BLACK, 0,1) end--3600
	--第2リンゴ
	if (isTime(3700))then
		if (Player.getItemApple() == 2)then item = Apple
		else item = GoldenApple end
		en_spawn(f_max/2, 0, DEV_ORANGE, 500, 1, 2)
		en_bullet(IMG.POIFUL,CL.PINK)
		en_item(item, 1)
	end

	enter_boss_time = 50--00
	if (isTime(enter_boss_time))then TL.setTalkScene(0) end--会話シーンへ移行
	if (isTime(enter_boss_time+60))then TL.setTalkScene(1) end--会話シーンへ移行
	if (isTime(enter_boss_time+120))then TL.endStage() end

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