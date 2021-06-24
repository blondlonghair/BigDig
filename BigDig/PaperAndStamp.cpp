#include "DXUT.h"
#include "PaperAndStamp.h"

void PaperAndStamp::Awake()
{
	papers = OBJECT.AddObject(Tag::Untagged);
	papers->ac<CSpriteRenderer>()->Init(SPRITE("papers"), SortingLayer::UI, RenderMode::Default);
	papers->ac<CAnimation>()->Init("papers", 0.1, true);
	papers->tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);

	stamp = OBJECT.AddObject(Tag::Untagged);
	stamp->ac<CSpriteRenderer>()->Init(SPRITE("stamp"), SortingLayer::UI, RenderMode::UI);
	stamp->ac<CAnimation>()->Init("stamp", 0.1, true);
	stamp->tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);
}

void PaperAndStamp::Start()
{
}

void PaperAndStamp::Update()
{
	if (INPUT.KeyDown(VK_SPACE))
	{
		GAME.isStart = true;
		//천천히 사라지게 바꾸기
		papers->Destroy();
		stamp->Destroy();
	}
}

void PaperAndStamp::LateUpdate()
{
}

void PaperAndStamp::OnRender()
{
}

void PaperAndStamp::OnDestroy()
{
}

void PaperAndStamp::OnCollisionEnter(CObject* _pObj)
{
}

void PaperAndStamp::OnCollisionStay(CObject* _pObj)
{
}

void PaperAndStamp::OnCollisionExit(CObject* _pObj)
{
}
