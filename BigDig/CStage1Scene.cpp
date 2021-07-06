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
	paperStamp = OBJECT.AddObject(Tag::Untagged);
	paperStamp->ac<PaperAndStamp>();
	paperStamp->tf->m_vPos = Vec2(0, 0);

	pBackBG = OBJECT.AddObject(Tag::BackGround);
	pBackBG->ac<CSpriteRenderer>()->Init(SPRITE("Stage1BackBG"), SortingLayer::BackBG, RenderMode::Default);
	pBackBG->tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);

	pFrontBG = OBJECT.AddObject(Tag::Untagged);
	pFrontBG->ac<Stage1TileMap>();

	pPlayer = OBJECT.AddObject(Tag::Player);
	pPlayer->ac<Stage1Player>();
	pPlayer->ac<CCollider>()->Init(30);
	pPlayer->tf->m_vPos = Vec2(WINSIZEX / 2, ((WINSIZEY - TILESIZEY) / 2));

	pBoss = OBJECT.AddObject(Tag::Boss);
	pBoss->ac<Stage1Boss>();
	pBoss->ac<CCollider>()->Init(125);
	pBoss->tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);

	ScoreText = OBJECT.AddObject(Tag::Stage1UI);
	ScoreText->ac<Stage1UI>();

	CObject* cheatKey = OBJECT.AddObject(Tag::Untagged);
	cheatKey->ac<CheatKey>();
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
