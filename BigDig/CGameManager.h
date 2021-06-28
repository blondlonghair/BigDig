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
    int m_playerLife = 3;
    int m_Stage1Tile[TILESIZEX][TILESIZEY];
    D3DXCOLOR stage1Color[TILESIZEX][TILESIZEY];
    int m_Stage2Tile[TILESIZEX][TILESIZEY];
    D3DXCOLOR stage2Color[TILESIZEX][TILESIZEY];
    int m_Stage3Tile[TILESIZEX][TILESIZEY];
    D3DXCOLOR stage3Color[TILESIZEX][TILESIZEY];
    bool isStart = false;

public:
    CGameManager();
    ~CGameManager();

public:
    void Reset();
};

#define GAME (*CGameManager::GetInstance())