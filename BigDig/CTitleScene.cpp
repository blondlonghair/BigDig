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
	titleBG->ac<CSpriteRenderer>()->Init(SPRITE("Stage3BackBG"), SortingLayer::Default, RenderMode::Default);
	titleBG->tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);

	CObject* playButton = OBJECT.AddObject(Tag::UI);
	playButton->ac<CButton>()->Init(Vec2(WINSIZEX / 2, WINSIZEY / 2), 
		Vec2(1, 1), SPRITE("Button"), [=]()->void {SCENE.ChangeScene("STAGE1"); });
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
