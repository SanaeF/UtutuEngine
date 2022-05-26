dofile( './dat/Script/Library/Talker/Library.lua' )
dofile( './dat/Script/Talk/Boss4TalkEnd/AyanoMisato.lua' )
dofile( './dat/Script/Talk/Boss4TalkEnd/AkagiHime.lua' )
dofile( './dat/Script/Talk/Boss4TalkEnd/Ioriko.lua' )

function TalkScene()--4–Ê’e–‹‘O‚Ì‰ï˜b

if(Player.getType() == 0 or Player.getType() == 1)then AyanoMisato() end
if(Player.getType() == 2 or Player.getType() == 3)then AkagiHime() end
if(Player.getType() == 4)then Ioriko() end

end

--@EndScript