dofile( './dat/Script/Library/Talker/Library.lua' )
dofile( './dat/Script/Talk/Boss1TalkEnd/Ayano.lua' )
dofile( './dat/Script/Talk/Boss1TalkEnd/Misato.lua' )
dofile( './dat/Script/Talk/Boss1TalkEnd/Akagi.lua' )
dofile( './dat/Script/Talk/Boss1TalkEnd/Hime.lua' )
dofile( './dat/Script/Talk/Boss1TalkEnd/Ioriko.lua' )

function TalkScene()--1ñ íeñãèIóπå„ÇÃâÔòb

if(Player.getType() == 0)then Ayano() end
if(Player.getType() == 1)then Misato() end
if(Player.getType() == 2)then Akagi() end
if(Player.getType() == 3)then Hime() end
if(Player.getType() == 4)then Ioriko() end

end

--@EndScript