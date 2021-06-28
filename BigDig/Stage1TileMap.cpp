#include "DXUT.h"
#include "Stage1TileMap.h"

void Stage1TileMap::Awake()
{
	go->ac<CSpriteRenderer>()->Init(SPRITE("Stage1FrontBG"), SortingLayer::FrontBG, RenderMode::Default);
	go->tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);

	//go->gc<CSpriteRenderer>()->m_pSprite->m_pTexture->LockRect(0, &GAME.m_lockRect, 0, D3DLOCK_DISCARD);
	SPRITE("Stage1FrontBG")->m_pTexture->LockRect(0, &GAME.m_lockRect, 0, D3DLOCK_DISCARD);

	DWORD* pColor = (DWORD*)GAME.m_lockRect.pBits;

	for (int y = 0; y < TILESIZEY; y++)
	{
		for (int x = 0; x < TILESIZEX; x++)
		{
			D3DXCOLOR color = pColor[y * TILESIZEX + x];
			color.a = 1;
			pColor[y * TILESIZEX + x] = color;
			GAME.stage1Color[x][y] = color;
		}
	}

	SPRITE("Stage1FrontBG")->m_pTexture->UnlockRect(0);
	
	//for (int x = 0; x < WINSIZEX; x++)
	//{
	//	for (int y = 0; y < WINSIZEY; y++)
	//	{
	//		GAME.m_Stage1Tile[x][y] = pColor;
	//	}
	//}

	InitArray();
}

void Stage1TileMap::Start()
{
}

void Stage1TileMap::Update()
{
}

void Stage1TileMap::LateUpdate()
{
}

void Stage1TileMap::OnRender()
{
}

void Stage1TileMap::OnDestroy()
{
}

void Stage1TileMap::OnCollisionEnter(CObject* _pObj)
{
}

void Stage1TileMap::OnCollisionStay(CObject* _pObj)
{
}

void Stage1TileMap::OnCollisionExit(CObject* _pObj)
{
}

void Stage1TileMap::InitArray()
{
	for (int x = 0; x < TILESIZEX; x++)
	{
		for (int y = 0; y < TILESIZEY; y++)
		{
			GAME.m_Stage1Tile[x][y] = 0;
		}
	}

	for (int i = 0; i < TILESIZEX; i++)
	{
		GAME.m_Stage1Tile[i][0] = 1;
		GAME.m_Stage1Tile[i][TILESIZEY - 1] = 1;
	}
	for (int i = 0; i < TILESIZEY; i++)
	{
		GAME.m_Stage1Tile[0][i] = 1;
		GAME.m_Stage1Tile[TILESIZEX - 1][i] = 1;
	}
}
