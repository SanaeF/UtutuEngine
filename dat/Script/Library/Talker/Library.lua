dofile( './dat/Script/Library/Player/PlayerSc.lua' )
dofile( './dat/Script/Library/Talker/SerifBoxSc.lua' )
dofile( './dat/Script/Library/Talker/ImgCharaSc.lua' )

function SimpleMassage(name,text1,text2,text3)
	Massage.setName(name)
	Massage.Text(text1,text2,text3)
end

function Scene(num)
	EndScene(num+1)
	TalkFunc(num,"Func:Scene")
end
function SceneEnd(num)
	TalkFunc(num,"Func:Scene")
end
function WaitAndSkip(time)
	TalkFunc(time,"Func:WaitAndSkip")
end
function PlayBGM(num)
	TalkFunc(num,"Func:PlayBGM")
end
function SummonBoss(type,index)
	TalkFunc(type,index,"Func:SummonBoss")
end
function JoinBullet(bullet_first,bullet_end)
	TalkFunc(bullet_first,bullet_end,"Func:JoinBullet")
	WaitAndSkip(0)
end
function EndScene(num)
	TalkFunc(num,"Func:End")
end
function isEndTalk()
	return TalkFunc(false,"Func:GetEndTalk")
end
function SetEndTalk(num)
	TalkFunc(num,"Func:SetEndTalk")
end

function EndingPhase()
	return TalkFunc(true,"Func:GoEnding")
end

function name_(text)
	return text
end
function id_(num)
	return num
end
function x_(num)
	return num
end
function y_(num)
	return num
end
function size_(num)
	return num
end

function index(id)
	return id
end
--@EndScript