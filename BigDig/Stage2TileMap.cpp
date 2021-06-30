#include "DXUT.h"
#include "Stage2TileMap.h"

void Stage2TileMap::Awake()
{
	go->ac<CSpriteRenderer>()->Init(SPRITE("Stage2FrontBG"), SortingLayer::FrontBG, RenderMode::Default);
	go->tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);

	//go->gc<CSpriteRenderer>()->m_pSprite->m_pTexture->LockRect(0, &GAME.m_lockRect2, 0, D3DLOCK_DISCARD);
	SPRITE("Stage2FrontBG")->m_pTexture->LockRect(0, &GAME.m_lockRect2, 0, D3DLOCK_DISCARD);

	DWORD* pColor = (DWORD*)GAME.m_lockRect2.pBits;

	if (GAME.firstTime2)
	{
		for (int y = 0; y < TILESIZEY; y++)
		{
			for (int x = 0; x < TILESIZEX; x++)
			{
				D3DXCOLOR color = pColor[y * TILESIZEX + x];
				pColor[y * TILESIZEX + x] = color;
				GAME.stage2Color[x][y] = color;
			}
		}
	}
	GAME.firstTime2 = false;
	SPRITE("Stage2FrontBG")->m_pTexture->UnlockRect(0);

	//for (int x = 0; x < WINSIZEX; x++)
	//{
	//	for (int y = 0; y < WINSIZEY; y++)
	//	{
	//		GAME.m_Stage2Tile[x][y] = pColor;
	//	}
	//}

	InitArray();
}

void Stage2TileMap::Start()
{
}

void Stage2TileMap::Update()
{
	if (GAME.m_playerLife <= 0)
	{
		SCENE.ChangeScene("TITLE");
		GAME.m_playerLife = 3;
	}
}

void Stage2TileMap::LateUpdate()
{
}

void Stage2TileMap::OnRender()
{
}

void Stage2TileMap::OnDestroy()
{
}

void Stage2TileMap::OnCollisionEnter(CObject* _pObj)
{
}

void Stage2TileMap::OnCollisionStay(CObject* _pObj)
{
}

void Stage2TileMap::OnCollisionExit(CObject* _pObj)
{
}

void Stage2TileMap::InitArray()
{
	SPRITE("Stage2FrontBG")->m_pTexture->LockRect(0, &GAME.m_lockRect2, 0, D3DLOCK_DISCARD);

	DWORD* pColor = (DWORD*)GAME.m_lockRect2.pBits;

	for (int x = 0; x < TILESIZEX; x++)
	{
		for (int y = 0; y < TILESIZEY; y++)
		{
			GAME.m_Stage2Tile[x][y] = 0;
			pColor[y * TILESIZEX + x] = GAME.stage2Color[x][y];
		}
	}

	SPRITE("Stage2FrontBG")->m_pTexture->UnlockRect(0);

	for (int i = 0; i < TILESIZEX; i++)
	{
		GAME.m_Stage2Tile[i][0] = 1;
		GAME.m_Stage2Tile[i][TILESIZEY - 1] = 1;
	}
	for (int i = 0; i < TILESIZEY; i++)
	{
		GAME.m_Stage2Tile[0][i] = 1;
		GAME.m_Stage2Tile[TILESIZEX - 1][i] = 1;
	}
}
