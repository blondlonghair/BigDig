#pragma once

// stdafx.h
// 이 헤더파일은 DXUT에서 인클루드 해주고 있음 그리고 DXUT는 모든 파일에서 인클루드 해주고 있음
// 한 마디로 이 헤더파일은 모든 파일에서 인클루드 해주는 헤더파일임

// 기본적으로 사용하는 STL및 C++
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <string>
#include <functional>
#include <queue>
#include <cstdarg>
#include <cstdlib>
#include <Mmsystem.h>
#include <mciapi.h>
#pragma comment(lib, "Winmm.lib")

// 기본적으로 사용하는 STL및 C++

using namespace std; // <- 사용안하면 원래 std::vector 이런식으로 사용해야되는데 사용하게되면 vector로 짧게 쓸 수 있음

// 위에 using namespace std랑 똑같이 긴 자료형을 짧게 줄이는 코드
using Vec2 = D3DXVECTOR2;
using Vec3 = D3DXVECTOR3;
using Vec4 = D3DXVECTOR4;
using Matrix = D3DXMATRIX;
using Quaternion = D3DXQUATERNION;
using Color = D3DXCOLOR;
// 위에 using namespace std랑 똑같이 긴 자료형을 짧게 줄이는 코드

// 기본적인 default값 변수들
const int WINSIZEX = 1920;  // 프로그램 X사이즈
const int WINSIZEY = 1080;   // 프로그램 Y사이즈
const bool WINDOWED = false; // 창모드로 할 것인가 ?

const int TILESIZEX = 1800;
const int TILESIZEY = 960;
// 기본적인 default값 변수들

// enum과 enum class의 차이점
// 원래의 enum은 강제성이 없었는데 enum에 class가 붙으면 강제성이 생겨서
// enum Tag 일 경우에는 그냥 Untagged 이렇게 바로 사용할 수 있어서 짧고 편하지만 가독성이 좋지않음
// enum class Tag 일 경우에는 Tag::Untagged 이렇게 되어서 조금 길어지지만 가독성이 좋아짐

// Unity의 Tag라고 생각하면 편함
// 오브젝트의 종류를 크게크게 분류하는 기준
enum class Tag
{
	Untagged,
	Player,
	Enemy,
	UI,
	BackGround,
	Boss,
	Stage1UI,
	Stage2UI,
	Stage3UI,
};

// Unity의 SortingLayer라고 생각하면 편함
// 오브젝트의 렌더링 순서를 나타내는 분류 기준
enum class SortingLayer
{
	BackBG,
	FrontBG,
	Default,
	UI
};

// 오브젝트의 그려주는 상태를 나타냄
//   Default = 그냥 그려줌
// BillBoard = 3D 카메라를 사용할 경우 이미지가 그 카메라를 바라보는 방식으로 그려줌 (2D 사용 X)
//        UI = 가장 맨 위에 그려주는 렌더 모드 UI가 플레이어나 몬스터에 가려지면 안되니까 카메라 쉐이크 했을 때도 안흔들림
enum class RenderMode
{
	Default,
	BillBoard,
	UI
};

#define g_Device DXUTGetD3D9Device() // DXUT에서 만들어준 프로그램(디바이스)를 사용하기 위한 함수를 define한 것
#define dt DXUTGetElapsedTime()	     // Unity의 Time.DeltaTime과 똑같음

#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

static void Debug(const wchar_t* str)
{
	OutputDebugString(str);
	OutputDebugString(L"\n");
}

template<typename T>
void Debug(const wchar_t* format, const T src...)
{
	wchar_t str[256];
	va_list args;
	va_start(args, format);
	vswprintf(str, 256, format, args);
	OutputDebugString(str);
	OutputDebugString(L"\n");
	va_end(args);
}

// 수학적인 함수들을 담아두는 곳
namespace math
{
	const double PI = 3.141592653589793238462643383279502884L;

	// Vec3값을 오일러 쿼터니온 값으로 변환해주는 함수
	static Quaternion GetQuaternion(Vec3 _vRotation)
	{
		Quaternion quat;
		D3DXQuaternionRotationYawPitchRoll(&quat, D3DXToRadian(_vRotation.y), D3DXToRadian(_vRotation.x), D3DXToRadian(_vRotation.z));
		return quat;
	}

	// 그 방향에 맞게 회전률에 따라 회전을 해주는 함수
	static Vec2 GetRotatedVector2D(Vec2 _vDir, float _fRot)
	{
		Vec2 vDir = _vDir;
		Matrix MatRot;
		D3DXMatrixRotationZ(&MatRot, D3DXToRadian(_fRot));
		D3DXVec2TransformNormal(&vDir, &vDir, &MatRot);
		return vDir;
	}

	// 그 v1좌표와 v2좌표의 길이를 구하는 함수 (3D)
	static float GetLength(Vec3 _v1, Vec3 _v2)
	{
		return D3DXVec3Length(&(_v2 - _v1));
	}

	// 그 v1좌표와 v2좌표의 길이를 구하는 함수 (2D)
	static float GetLength(Vec2 _v1, Vec2 _v2)
	{
		return D3DXVec2Length(&(_v2 - _v1));
	}

	// _min, _max 사이에서 랜덤으로 값을 반환해줌
	static int RandRange(int _min, int _max)
	{
		return rand() % (_max - _min) + _min;
	}

	// Vec2값에 따라 아크 탄젠트를 이용해서 오일러 각도를 구함
	static float GetVecRot(Vec2 _vRot)
	{
		return  D3DXToDegree(atan2f(_vRot.y, _vRot.x));
	}

	//히히 Lerp
	static float Lerp(float _v1, float _v2, float _time)
	{
		return _v1 + _time * (_v2 - _v1);
	}

	//히히 아탄2
	static float Atan2(Vec2 _v1, Vec2 _v2)
	{
		return (atan2f(_v2.y - _v1.y, _v2.x - _v1.x)) * 180 / PI;
	}
}
using namespace math; // 위에 std랑 같음

// 매니저 및 컴포넌트 헤더파일을 가져옴
#include "CSingleton.h"

#include "CScheduleAdmin.h"
#include "CSprite.h"

#include "CScene.h"
#include "CObject.h"
#include "CComponent.h"
#include "CTransform.h"

#include "CGraphicsManager.h"
#include "CInputManager.h"
#include "CCameraManager.h"
#include "CObjectManager.h"
#include "CSceneManager.h"
#include "CGameManager.h"
#include "Timer.h"

#include "CRenderer2D.h"
#include "CSpriteRenderer.h"
#include "CText.h"
#include "CButton.h"
#include "CCollider.h"
#include "CAnimation.h"

//공용
#include "PaperAndStamp.h"
#include "Bullet.h"
#include "Bullet2.h"
#include "CheatKey.h"

//타이틀 화면
#include "TitleScript.h"

//스테이지1
#include "Stage1Player.h"
#include "Stage1TileMap.h"
#include "Stage1Boss.h"
#include "Stage1UI.h"

//스테이지2
#include "Stage2Boss.h"
#include "Stage2Player.h"
#include "Stage2UI.h"
#include "Stage2TileMap.h"

//스테이지4
#include "Stage3Boss.h"
#include "Stage3Player.h"
#include "Stage3UI.h"
#include "Stage3TileMap.h"


// 매니저 및 컴포넌트 헤더파일을 가져옴

// Unity의 Lerp랑 똑같음 s에서 e까지 t시간만큼 움직임
template <class T>
T Lerp(T s, T e, float t)
{
	return s + t * (e - s);
}

