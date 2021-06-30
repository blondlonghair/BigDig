#include "DXUT.h"
#include "Stage3TileMap.h"

void Stage3TileMap::Awake()
{
	go->ac<CSpriteRenderer>()->Init(SPRITE("Stage3FrontBG"), SortingLayer::FrontBG, RenderMode::Default);
	go->tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);

	//go->gc<CSpriteRenderer>()->m_pSprite->m_pTexture->LockRect(0, &GAME.m_lockRect1, 0, D3DLOCK_DISCARD);
	SPRITE("Stage3FrontBG")->m_pTexture->LockRect(0, &GAME.m_lockRect1, 0, D3DLOCK_DISCARD);

	DWORD* pColor = (DWORD*)GAME.m_lockRect1.pBits;

	if (GAME.firstTime3)
	{
		for (int y = 0; y < TILESIZEY; y++)
		{
			for (int x = 0; x < TILESIZEX; x++)
			{
				D3DXCOLOR color = pColor[y * TILESIZEX + x];
				color.a = 1;
				pColor[y * TILESIZEX + x] = color;
				GAME.stage3Color[x][y] = color;
			}
		}
	}
	GAME.firstTime3 = false;
	SPRITE("Stage3FrontBG")->m_pTexture->UnlockRect(0);

	//for (int x = 0; x < WINSIZEX; x++)
	//{
	//	for (int y = 0; y < WINSIZEY; y++)
	//	{
	//		GAME.m_Stage3Tile[x][y] = pColor;
	//	}
	//}

	InitArray();
}

void Stage3TileMap::Start()
{
}

void Stage3TileMap::Update()
{
	if (GAME.m_playerLife <= 0)
	{
		SCENE.ChangeScene("TITLE");
		GAME.m_playerLife = 3;
	}
}

void Stage3TileMap::LateUpdate()
{
}

void Stage3TileMap::OnRender()
{
}

void Stage3TileMap::OnDestroy()
{
}

void Stage3TileMap::OnCollisionEnter(CObject* _pObj)
{
}

void Stage3TileMap::OnCollisionStay(CObject* _pObj)
{
}

void Stage3TileMap::OnCollisionExit(CObject* _pObj)
{
}

void Stage3TileMap::InitArray()
{
	SPRITE("Stage3FrontBG")->m_pTexture->LockRect(0, &GAME.m_lockRect1, 0, D3DLOCK_DISCARD);

	DWORD* pColor = (DWORD*)GAME.m_lockRect1.pBits;

	for (int x = 0; x < TILESIZEX; x++)
	{
		for (int y = 0; y < TILESIZEY; y++)
		{
			GAME.m_Stage3Tile[x][y] = 0;
			pColor[y * TILESIZEX + x] = GAME.stage3Color[x][y];
		}
	}

	SPRITE("Stage3FrontBG")->m_pTexture->UnlockRect(0);

	for (int i = 0; i < TILESIZEX; i++)
	{
		GAME.m_Stage3Tile[i][0] = 1;
		GAME.m_Stage3Tile[i][TILESIZEY - 1] = 1;
	}
	for (int i = 0; i < TILESIZEY; i++)
	{
		GAME.m_Stage3Tile[0][i] = 1;
		GAME.m_Stage3Tile[TILESIZEX - 1][i] = 1;
	}
}
