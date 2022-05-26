dofile( './dat/Script/Library/Talker/Library.lua' )
dofile( './dat/Script/Talk/Boss5Talk/Ayano.lua' )
dofile( './dat/Script/Talk/Boss5Talk/Misato.lua' )
dofile( './dat/Script/Talk/Boss5Talk/Akagi.lua' )
dofile( './dat/Script/Talk/Boss5Talk/Hime.lua' )
dofile( './dat/Script/Talk/Boss5Talk/Ioriko.lua' )

function TalkScene()--5–Ê’e–‹‘O‚Ì‰ï˜b

if(Player.getType() == 0)then Ayano() end
if(Player.getType() == 1)then Misato() end
if(Player.getType() == 2)then Akagi() end
if(Player.getType() == 3)then Hime() end
if(Player.getType() == 4)then Ioriko() end

end

--@EndScript