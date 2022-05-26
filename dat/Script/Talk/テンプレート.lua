dofile( './dat/Script/Talk/Talklib/Library.lua' )

SetEndTalk(true)
--弾幕前の会話シーン
if not(isEndTalk())then
	Scene(0)
end

--弾幕後の会話シーン
if(isEndTalk())then
	Scene(0)
end