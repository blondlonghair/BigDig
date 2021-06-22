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
	if (INPUT.KeyDown('A'))
	{
		SCENE.ChangeScene("STAGE1");
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
