#pragma once
#include "CSingleton.h"

// Unity�� GameManager�� �����
// �������� ����� �������� ���⼭ �����
// Score, PlayerName ...
class CGameManager :
    public CSingleton<CGameManager>
{
public:
    D3DLOCKED_RECT m_lockRect;
    int m_Stage1Tile[TILESIZEX][TILESIZEY];

public:
    CGameManager();
    ~CGameManager();

public:
    void Reset();
    void FloodFill();
};

#define GAME (*CGameManager::GetInstance())