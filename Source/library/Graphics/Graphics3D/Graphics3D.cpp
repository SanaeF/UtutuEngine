#include "Graphics3D.h"
#include "DxLib.h"
#include <iostream>
namespace lib {
	VECTOR setVector(obj::Position param) {
		VECTOR param2;
		param2.x = param.x;
		param2.y = param.y;
		param2.z = param.z;
		return param2;
	}
	int Graphics3D::load(const TCHAR* FileAdress) {
		return MV1LoadModel(FileAdress);
	}
	void Graphics3D::ModelScale(int Handle, obj::Position Scale) {
		MV1SetScale(Handle, setVector(Scale));
	}
	void Graphics3D::ModelRotate(int Handle, obj::Position Rotate) {
		MV1SetRotationXYZ(Handle, setVector(Rotate));
	}
	void Graphics3D::ModelPositioin(int Handle, obj::Position Position) {
		MV1SetPosition(Handle, setVector(Position));
	}
	void Graphics3D::CameraPosAndRota(obj::Position Position,
		float RotaV,
		float RotaH,
		float RotaT
	) {
		SetCameraPositionAndAngle(setVector(Position), RotaV, RotaH, RotaT);//(v,h,t),cŒü‚«‰ñ“],‰¡Œü‚«‰ñ“],•ûŒü‚»‚Ì‚Ü‚ÜƒJƒƒ‰‚ð‰ñ“]
	}
	void Graphics3D::cameraCenter(float x, float y) {
		SetCameraScreenCenter(x, y);
	}
	void Graphics3D::DrawModel(int Handle) {
		MV1DrawModel(Handle);
	}
	void Graphics3D::UseLight(int Flag) {
		SetUseLighting(Flag);
	}
	//int Graphics3D::cameraNum() {
	//	return this->camera_num;
	//}
	obj::Position Graphics3D::VGet(float x, float y, float z)
	{
		obj::Position Result(x, y, z);
		return Result;
	}
}