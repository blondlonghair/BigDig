#pragma once
#include "CScene.h"
class CStage2Scene :
    public CScene
{
    // CScene��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

