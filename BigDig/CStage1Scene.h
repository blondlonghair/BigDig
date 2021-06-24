#pragma once
#include "CScene.h"
class CStage1Scene :
    public CScene
{
private:
    bool isStart = false;

public:
    CStage1Scene();
    ~CStage1Scene();

public:
    // CScene을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

