#pragma once
#include "CSingleton.h"

// Unity의 GameManager와 비슷함
// 전역으로 사용할 변수들을 여기서 사용함
// Score, PlayerName ...
class CGameManager :
    public CSingleton<CGameManager>
{
public:
    D3DLOCKED_RECT m_lockRect;
    int m_Stage1Tile[TILESIZEX][TILESIZEY];
    int m_playerLife = 3;

public:
    CGameManager();
    ~CGameManager();

public:
    void Reset();
    void FloodFill();
};

#define GAME (*CGameManager::GetInstance())