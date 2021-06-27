#include "DXUT.h"
#include "CStage2Scene.h"

void CStage2Scene::Init()
{
	GAME.Reset();

	CObject* paperStamp = OBJECT.AddObject(Tag::Untagged);
	paperStamp->ac<PaperAndStamp>();
	paperStamp->tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);

	//CObject* 
}

void CStage2Scene::Update()
{
}

void CStage2Scene::Render()
{
}

void CStage2Scene::Release()
{
}
