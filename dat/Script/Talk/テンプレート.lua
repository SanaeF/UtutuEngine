dofile( './dat/Script/Talk/Talklib/Library.lua' )

SetEndTalk(true)
--�e���O�̉�b�V�[��
if not(isEndTalk())then
	Scene(0)
end

--�e����̉�b�V�[��
if(isEndTalk())then
	Scene(0)
end