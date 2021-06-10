#pragma once
#include "CComponent.h"

class Stage1TileMap :
    public CComponent
{
public:

public:
    virtual void Awake() override;
    virtual void Start() override;
    virtual void Update() override;
    virtual void LateUpdate() override;
    virtual void OnRender() override;
    virtual void OnDestroy() override;
    virtual void OnCollisionEnter(CObject* _pObj) override;
    virtual void OnCollisionStay(CObject* _pObj) override;
    virtual void OnCollisionExit(CObject* _pObj) override;

private:
    void Stage1TileMap::InitArray();
    void Stage1TileMap::UpdateLockRect();
};

