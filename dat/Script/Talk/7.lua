dofile( './dat/Script/Library/Talker/Library.lua' )
dofile( './dat/Script/Talk/Boss4Talk/Ayano.lua' )
dofile( './dat/Script/Talk/Boss4Talk/Misato.lua' )
dofile( './dat/Script/Talk/Boss4Talk/Akagi.lua' )
dofile( './dat/Script/Talk/Boss4Talk/Hime.lua' )
dofile( './dat/Script/Talk/Boss4Talk/Ioriko.lua' )

function TalkScene()--4�ʒe���O�̉�b

if(Player.getType() == 0)then Ayano() end
if(Player.getType() == 1)then Misato() end
if(Player.getType() == 2)then Akagi() end
if(Player.getType() == 3)then Hime() end
if(Player.getType() == 4)then Ioriko() end

end

--@EndScript