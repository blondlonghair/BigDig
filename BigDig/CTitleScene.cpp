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

	CObject* titleText = OBJECT.AddObject(Tag::Untagged);
	titleText->ac<CSpriteRenderer>()->Init(SPRITE("TitleText"), SortingLayer::Default, RenderMode::Default);
	titleText->tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);

	//CObject* playButton = OBJECT.AddObject(Tag::UI);
	//playButton->ac<CButton>()->Init(Vec2(WINSIZEX / 2, WINSIZEY / 2),
	//	Vec2(1, 1), SPRITE("Button"), [=]()->void { SCENE.ChangeScene("STAGE1"); });

	CObject* emptyObj = OBJECT.AddObject(Tag::Untagged);
	emptyObj->ac<TitleScript>();
}

void CTitleScene::Update()
{
	//for (int x = 0; x < TILESIZEX; x++)
	//{
	//	for (int y = 0; y < TILESIZEY; y++)
	//	{
	//		if (GAME.m_Stage1Tile != 0)
	//		{
	//			tilePersent++;
	//		}
	//	}
	//}
}

void CTitleScene::Render()
{
}

void CTitleScene::Release()
{
}
