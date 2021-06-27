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
    int m_playerLife = 3;
    int m_Stage1Tile[TILESIZEX][TILESIZEY];
    int m_Stage2Tile[TILESIZEX][TILESIZEY];
    int m_Stage3Tile[TILESIZEX][TILESIZEY];
    bool isStart = false;

public:
    CGameManager();
    ~CGameManager();

public:
    void Reset();
};

#define GAME (*CGameManager::GetInstance())