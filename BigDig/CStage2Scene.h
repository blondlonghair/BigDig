#pragma once
#include "CScene.h"
class CStage2Scene :
    public CScene
{
public:
    CObject* paperStamp;
    CObject* pBackBG;
    CObject* pFrontBG;
    CObject* pPlayer;
    CObject* pBoss;
    CObject* ScoreText;

private:
    bool isStart = false;

public:
    CStage2Scene();
    ~CStage2Scene();

public:
    // CScene을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

