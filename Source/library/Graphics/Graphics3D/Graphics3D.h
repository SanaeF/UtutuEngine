#pragma once
#include <tchar.h>
#include "../../Source/Object/Object/Parameter/Position/Position.h"

namespace lib {
	class Graphics3D {
	private:
		int camera_num;
	public:
		static int load(const TCHAR* FileAdress);
		static void ModelScale(int Handle, obj::Position Scale);
		static void ModelRotate(int Handle, obj::Position Rotate);
		static void ModelPositioin(int Handle, obj::Position Position);
		static void CameraPosAndRota(
			obj::Position Position,
			float RotaV,
			float RotaH,
			float RotaT
		);
		static void cameraCenter(float x, float y);
		static void DrawModel(int Handle);
		static void UseLight(int Flag);
		//int cameraNum();
		static obj::Position VGet(float x, float y, float z);
	};
}