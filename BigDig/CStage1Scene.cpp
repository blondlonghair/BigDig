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
	CObject* paperStamp = OBJECT.AddObject(Tag::Untagged);
	paperStamp->ac<PaperAndStamp>();
	paperStamp->tf->m_vPos = Vec2(0, 0);

	CObject* pBackBG = OBJECT.AddObject(Tag::BackGround);
	pBackBG->ac<CSpriteRenderer>()->Init(SPRITE("Stage1BackBG"), SortingLayer::BackBG, RenderMode::Default);
	pBackBG->tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);
	
	CObject* pFrontBG = OBJECT.AddObject(Tag::Untagged);
	pFrontBG->ac<Stage1TileMap>();
	
	CObject* pPlayer = OBJECT.AddObject(Tag::Player);
	pPlayer->ac<Stage1Player>();
	pPlayer->ac<CCollider>()->Init(40);
	pPlayer->tf->m_vPos = Vec2(WINSIZEX / 2, ((WINSIZEY - TILESIZEY) / 2));
	
	CObject* pBoss = OBJECT.AddObject(Tag::Boss);
	pBoss->ac<Stage1Boss>();
	pBoss->ac<CCollider>()->Init(125);
	pBoss->tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);

	CObject* ScoreText = OBJECT.AddObject(Tag::Stage1Score);
	ScoreText->ac<Stage1Score>();

	CObject* heart1 = OBJECT.AddObject(Tag::PlayerLife);
	heart1->ac<CSpriteRenderer>()->Init(SPRITE("Heart"), SortingLayer::UI, RenderMode::UI);
	heart1->tf->m_vPos = Vec2(WINSIZEX - 32 - 64 - 64 - 10 - 10, 32);

	CObject* heart2 = OBJECT.AddObject(Tag::PlayerLife);
	heart2->ac<CSpriteRenderer>()->Init(SPRITE("Heart"), SortingLayer::UI, RenderMode::UI);
	heart2->tf->m_vPos = Vec2(WINSIZEX - 32 - 64 - 10, 32);

	CObject* heart3 = OBJECT.AddObject(Tag::PlayerLife);
	heart3->ac<CSpriteRenderer>()->Init(SPRITE("Heart"), SortingLayer::UI, RenderMode::UI);
	heart3->tf->m_vPos = Vec2(WINSIZEX - 32, 32);
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
