#include "DXUT.h"
#include "TitleScript.h"

void TitleScript::Awake()
{
}

void TitleScript::Start()
{
}

void TitleScript::Update()
{
	for (int i = 0; i < 165; i++)
	{
		if (INPUT.KeyDown(i))
		{
			SCENE.ChangeScene("STAGE1");
		}
	}
}

void TitleScript::LateUpdate()
{
}

void TitleScript::OnRender()
{
}

void TitleScript::OnDestroy()
{
}

void TitleScript::OnCollisionEnter(CObject* _pObj)
{
}

void TitleScript::OnCollisionStay(CObject* _pObj)
{
}

void TitleScript::OnCollisionExit(CObject* _pObj)
{
}
