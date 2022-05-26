dofile( './dat/Script/Library/Talker/Library.lua' )
dofile( './dat/Script/Talk/Boss7Talk/Ayano.lua' )
dofile( './dat/Script/Talk/Boss7Talk/Misato.lua' )
dofile( './dat/Script/Talk/Boss7Talk/Akagi.lua' )
dofile( './dat/Script/Talk/Boss7Talk/Hime.lua' )
dofile( './dat/Script/Talk/Boss7Talk/Ioriko.lua' )
--7面弾幕前(アリスモード)の会話

function TalkScene()

if(Player.getType() == 0)then Ayano() end
if(Player.getType() == 1)then Misato() end
if(Player.getType() == 2)then Akagi() end
if(Player.getType() == 3)then Hime() end
if(Player.getType() == 4)then Ioriko() end

end

--@EndScript