#include "DXUT.h"
#include "CheatKey.h"

void CheatKey::Awake()
{
}

void CheatKey::Start()
{
}

void CheatKey::Update()
{
	if (INPUT.KeyDown(VK_F5))
	{
		SCENE.ChangeScene("STAGE1");
	}
	if (INPUT.KeyDown(VK_F6))
	{
		SCENE.ChangeScene("STAGE2");
	}
	if (INPUT.KeyDown(VK_F7))
	{
		SCENE.ChangeScene("STAGE3");
	}
	if (INPUT.KeyDown(VK_F8))
	{
		SCENE.ChangeScene("TITLE");
	}
}

void CheatKey::LateUpdate()
{
}

void CheatKey::OnRender()
{
}

void CheatKey::OnDestroy()
{
}

void CheatKey::OnCollisionEnter(CObject* _pObj)
{
}

void CheatKey::OnCollisionStay(CObject* _pObj)
{
}

void CheatKey::OnCollisionExit(CObject* _pObj)
{
}
