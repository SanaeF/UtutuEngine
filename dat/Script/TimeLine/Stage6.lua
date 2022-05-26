dofile( './dat/Script/Library/Timeline/TimelineSc.lua' )
dofile('./dat/Script/Timeline/ItemMinion/ItemMinion.lua')
dofile( './dat/Script/MinionProp/Bullet/Stage6/MinionBullet.lua' )
dofile( './dat/Script/MinionProp/Move/Stage6/MinionMover.lua' )

resetTime(1900)

function TimeLine()
	if (isTime(90))then TL.setSubTitle() end

	enter_boss_time=400
	if (isTime(enter_boss_time))then TL.setTalkScene(15) end
	if (isTime(enter_boss_time+60))then TL.setTalkScene(16) end
	if (isTime(enter_boss_time+120))then TL.setEnding() end

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