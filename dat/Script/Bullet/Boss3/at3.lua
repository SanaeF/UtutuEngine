dofile('./dat/Script/Bullet/Library.lua' )

function Initialize()
	Boss.cooldown_(2)
	Boss.setMainBullet()
	Boss.set(Time(60), HP(12500))
end

function BossShot()
	bTime = shot_time

	if(between(bTime%126,20,80))then Boss.setSerifBox(Boss.getX(),Boss.getY()-250,1,"そこだ！") end
	if(shot_time == 1)then
		Boss.Motion(0)
		move((FMAX_X - FMIN_X) / 2, (FMAX_Y - FMIN_Y) / 3, 40)
	end
	if(bTime%126==20)then Boss.Motion(1) end
	if(bTime%126==30)then boss_SE(BULLET01)
		et_s.noDelete(true)
		et_s.ringAt(Player.getX(),Player.getY(), diff(7,9,12,0), 240, IMG.NORMAL, CL.GREEN, 0, 0, 1)
	end
	if(bTime%126==50)then Boss.Motion(0) end
	for bl_num = 0 , SHOT_MAX do Trans(bl_num) end --ステータス変更
	for lc_num = 0 , T_LAZ_MAX do TransLc(lc_num) end
end

function Trans(bl_num)
	if (Shot.isFlag(bl_num))then
		if (Shot.getState1(bl_num) == 1) then
			if(Shot.getCount(bl_num)==120)then 
				Shot.setSpeed(3)
				Shot.addAngle(PI)
			end
			if(Shot.getCount(bl_num)==200)then boss_SE(KIRAN)
				LazCr.Create(Shot.getX(bl_num),Shot.getY(bl_num), 25, CL.RED, sp_(6,6,8,0), Shot.getAngle(bl_num)+PI, 2)
			end
		end
	end
end
function TransLc(lc_num)
	if(LazCr.isFlag(lc_num))then
		if(LazCr.getState1(lc_num)==2)then
			if(LazCr.getCount(lc_num)%18==8)then LazCr.addAngle(-PI/2) end
			if(LazCr.getCount(lc_num)%18==17)then LazCr.addAngle(PI/2) end
		end
	end
end

--@EndScript