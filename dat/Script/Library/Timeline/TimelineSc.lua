dofile( './dat/Script/Library/Bullet/BulletLib.lua' )
dofile( './dat/Script/Library/Player/PlayerSc.lua' )
dofile( './dat/Script/Library/Minion/MinionSc.lua')
dofile( './dat/Script/Library/Sound/SoundSc.lua' )

resetTimer = 1

function resetTime(num)
	resetTimer = num
end
function isTime(num)
	if (num == (stage_time%resetTimer)) then return true end
	return false
end

function isTimeBetween(num1,num2)
	return between(stage_time, num1,num2)
end

function isOverTime(num)
	if (stage_time > num) then return true end
	return false
end

TL = {}
	function TL.setRoad()
		TimeFunc( true, "Func:RoadFlag")
	end
	function TL.endStage()
		TimeFunc( false, "Func:RoadFlag")
	end
	function TL.setNotRoad()
		TimeFunc( true, "Func:RoadFlag")
	end
	function TL.setTalkScene(id)
		TimeFunc(id, true, "Func:TalkSceneFlag")
	end
	function TL.setNotTalkScene()
		TimeFunc( false, "Func:TalkSceneFlag")
	end
	function TL.setSubTitle()
		TimeFunc( true, "Func:SubTitleFlag")
	end
	function TL.setInterBoss(type, bullet_first, bullet_end)
		TimeFunc(type, bullet_first, bullet_end, "Func:InterBoss")
	end
	function TL.setEnding()
		TimeFunc(true, "Func:GoEnding")
	end
--@EndScript