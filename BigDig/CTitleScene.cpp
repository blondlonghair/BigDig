#include "DXUT.h"
#include "CTitleScene.h"

CTitleScene::CTitleScene()
{
}

CTitleScene::~CTitleScene()
{
}

void CTitleScene::Init()
{
	GAME.Reset();

	CObject* titleBG = OBJECT.AddObject(Tag::Untagged);
	titleBG->ac<CSpriteRenderer>()->Init(SPRITE("TitleBG"), SortingLayer::Default, RenderMode::Default);
	titleBG->tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);

	CObject* titleText = OBJECT.AddObject(Tag::UI);
	titleText->ac<CSpriteRenderer>()->Init(SPRITE("TitleText"), SortingLayer::Default, RenderMode::Default);
	titleText->tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);

	CObject* keyPressObj = OBJECT.AddObject(Tag::Untagged);
	keyPressObj->ac<TitleScript>();

	CObject* continueText = OBJECT.AddObject(Tag::UI);
	continueText->ac<CSpriteRenderer>()->Init(SPRITE("continueText"), SortingLayer::UI, RenderMode::UI);
	continueText->tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);

	CObject* cheatKey = OBJECT.AddObject(Tag::Untagged);
	cheatKey->ac<CheatKey>();

}

void CTitleScene::Update()
{
}

void CTitleScene::Render()
{
}

void CTitleScene::Release()
{
}
