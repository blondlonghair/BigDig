#include "DXUT.h"
#include "CStage1Scene.h"

CStage1Scene::CStage1Scene()
{
}

CStage1Scene::~CStage1Scene()
{
}

void CStage1Scene::Init()
{
	GAME.Reset();

	pBackBG = OBJECT.AddObject(Tag::BackGround);
	pBackBG->ac<CSpriteRenderer>()->Init(SPRITE("Stage1BackBG"), SortingLayer::BackBG, RenderMode::Default);
	pBackBG->tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);

	pFrontBG = OBJECT.AddObject(Tag::Untagged);
	pFrontBG->ac<Stage1TileMap>();

	pPlayer = OBJECT.AddObject(Tag::Player);
	pPlayer->ac<CPlayer>();
	pPlayer->ac<CCollider>()->Init(40);
	pPlayer->tf->m_vPos = Vec2(WINSIZEX / 2, ((WINSIZEY - TILESIZEY) / 2));

	pBoss = OBJECT.AddObject(Tag::Boss);
	pBoss->ac<Stage1Boss>();
	pBoss->ac<CCollider>()->Init(125);
	pBoss->tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);

	//LeftHand = OBJECT.AddObject(Tag::Boss);
}

void CStage1Scene::Update()
{
}

void CStage1Scene::Render()
{
}

void CStage1Scene::Release()
{
}
