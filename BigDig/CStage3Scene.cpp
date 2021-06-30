#include "DXUT.h"
#include "CStage3Scene.h"

void CStage3Scene::Init()
{
	GAME.Reset();
	paperStamp = OBJECT.AddObject(Tag::Untagged);
	paperStamp->ac<PaperAndStamp>();
	paperStamp->tf->m_vPos = Vec2(0, 0);

	pBackBG = OBJECT.AddObject(Tag::BackGround);
	pBackBG->ac<CSpriteRenderer>()->Init(SPRITE("Stage2BackBG"), SortingLayer::BackBG, RenderMode::Default);
	pBackBG->tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);

	pFrontBG = OBJECT.AddObject(Tag::Untagged);
	pFrontBG->ac<Stage3TileMap>();

	pPlayer = OBJECT.AddObject(Tag::Player);
	pPlayer->ac<Stage3Player>();
	pPlayer->ac<CCollider>()->Init(40);
	pPlayer->tf->m_vPos = Vec2(WINSIZEX / 2, ((WINSIZEY - TILESIZEY) / 2));

	pBoss = OBJECT.AddObject(Tag::Boss);
	pBoss->ac<Stage3Boss>();
	pBoss->ac<CCollider>()->Init(125);
	pBoss->tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);

	ScoreText = OBJECT.AddObject(Tag::Stage2UI);
	ScoreText->ac<Stage3UI>();
}

void CStage3Scene::Update()
{
}

void CStage3Scene::Render()
{
}

void CStage3Scene::Release()
{
}
