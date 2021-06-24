#pragma once
#include "CScene.h"
class CStage2Scene :
    public CScene
{
    // CScene을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

