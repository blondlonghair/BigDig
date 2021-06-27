#include "DXUT.h"
#include "CGameManager.h"

CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
}

void CGameManager::Reset()
{
	isStart = false;

	for (int x = 0; x < TILESIZEX; x++)
	{
		for (int y = 0; y < TILESIZEY; y++)
		{
			m_Stage1Tile[x][y] = 0;
			m_Stage2Tile[x][y] = 0;
			m_Stage3Tile[x][y] = 0;
		}
	}
}
