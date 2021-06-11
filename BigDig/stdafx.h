#pragma once

// stdafx.h
// �� ��������� DXUT���� ��Ŭ��� ���ְ� ���� �׸��� DXUT�� ��� ���Ͽ��� ��Ŭ��� ���ְ� ����
// �� ����� �� ��������� ��� ���Ͽ��� ��Ŭ��� ���ִ� ���������

// �⺻������ ����ϴ� STL�� C++
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

// �⺻������ ����ϴ� STL�� C++

using namespace std; // <- �����ϸ� ���� std::vector �̷������� ����ؾߵǴµ� ����ϰԵǸ� vector�� ª�� �� �� ����

// ���� using namespace std�� �Ȱ��� �� �ڷ����� ª�� ���̴� �ڵ�
using Vec2 = D3DXVECTOR2;
using Vec3 = D3DXVECTOR3;
using Vec4 = D3DXVECTOR4;
using Matrix = D3DXMATRIX;
using Quaternion = D3DXQUATERNION;
using Color = D3DXCOLOR;
// ���� using namespace std�� �Ȱ��� �� �ڷ����� ª�� ���̴� �ڵ�

// �⺻���� default�� ������
const int WINSIZEX = 1920;  // ���α׷� X������
const int WINSIZEY = 1080;   // ���α׷� Y������
const bool WINDOWED = true; // â���� �� ���ΰ� ?

const int TILESIZEX = 1800;
const int TILESIZEY = 960;
// �⺻���� default�� ������

// enum�� enum class�� ������
// ������ enum�� �������� �����µ� enum�� class�� ������ �������� ���ܼ�
// enum Tag �� ��쿡�� �׳� Untagged �̷��� �ٷ� ����� �� �־ ª�� �������� �������� ��������
// enum class Tag �� ��쿡�� Tag::Untagged �̷��� �Ǿ ���� ��������� �������� ������

// Unity�� Tag��� �����ϸ� ����
// ������Ʈ�� ������ ũ��ũ�� �з��ϴ� ����
enum class Tag 
{
	Untagged,
	Player,
	Enemy,
	UI,
	BackGround,
	Boss
};

// Unity�� SortingLayer��� �����ϸ� ����
// ������Ʈ�� ������ ������ ��Ÿ���� �з� ����
enum class SortingLayer
{
	BackBG,
	FrontBG,
	Default,
	UI
};

// ������Ʈ�� �׷��ִ� ���¸� ��Ÿ��
//   Default = �׳� �׷���
// BillBoard = 3D ī�޶� ����� ��� �̹����� �� ī�޶� �ٶ󺸴� ������� �׷��� (2D ��� X)
//        UI = ���� �� ���� �׷��ִ� ���� ��� UI�� �÷��̾ ���Ϳ� �������� �ȵǴϱ� ī�޶� ����ũ ���� ���� ����鸲
enum class RenderMode
{
	Default,
	BillBoard,
	UI
};

#define g_Device DXUTGetD3D9Device() // DXUT���� ������� ���α׷�(����̽�)�� ����ϱ� ���� �Լ��� define�� ��
#define dt DXUTGetElapsedTime()	     // Unity�� Time.DeltaTime�� �Ȱ���

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

// �������� �Լ����� ��Ƶδ� ��
namespace math
{
	// Vec3���� ���Ϸ� ���ʹϿ� ������ ��ȯ���ִ� �Լ�
	static Quaternion GetQuaternion(Vec3 _vRotation)
	{
		Quaternion quat;
		D3DXQuaternionRotationYawPitchRoll(&quat, D3DXToRadian(_vRotation.y), D3DXToRadian(_vRotation.x), D3DXToRadian(_vRotation.z));
		return quat;
	}

	// �� ���⿡ �°� ȸ������ ���� ȸ���� ���ִ� �Լ�
	static Vec2 GetRotatedVector2D(Vec2 _vDir, float _fRot)
	{
		Vec2 vDir = _vDir;
		Matrix MatRot;
		D3DXMatrixRotationZ(&MatRot, D3DXToRadian(_fRot));
		D3DXVec2TransformNormal(&vDir, &vDir, &MatRot);
		return vDir;
	}

	// �� v1��ǥ�� v2��ǥ�� ���̸� ���ϴ� �Լ� (3D)
	static float GetLength(Vec3 _v1, Vec3 _v2)
	{
		return D3DXVec3Length(&(_v2 - _v1));
	}

	// �� v1��ǥ�� v2��ǥ�� ���̸� ���ϴ� �Լ� (2D)
	static float GetLength(Vec2 _v1, Vec2 _v2)
	{
		return D3DXVec2Length(&(_v2 - _v1));
	}

	// _min, _max ���̿��� �������� ���� ��ȯ����
	static int RandRange(int _min, int _max)
	{
		return rand() % (_max - _min) + _min;
	}

	// Vec2���� ���� ��ũ ź��Ʈ�� �̿��ؼ� ���Ϸ� ������ ����
	static float GetVecRot(Vec2 _vRot)
	{
		return  D3DXToDegree(atan2f(_vRot.y, _vRot.x));
	}
}
using namespace math; // ���� std�� ����

// �Ŵ��� �� ������Ʈ ��������� ������
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

#include "CPlayer.h"
#include "Stage1TileMap.h"
#include "Stage1Boss.h"

// �Ŵ��� �� ������Ʈ ��������� ������

// Unity�� Lerp�� �Ȱ��� s���� e���� t�ð���ŭ ������
template <class T>
T Lerp(T s, T e, float t)
{
	return s + t * (e - s);
}
