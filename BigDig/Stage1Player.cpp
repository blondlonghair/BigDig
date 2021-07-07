#include "DXUT.h"
#include "Stage1Player.h"

void Stage1Player::Awake()
{
	ac<CSpriteRenderer>()->Init(SPRITE("PLAYER"), SortingLayer::Default, RenderMode::Default);
}

void Stage1Player::Start()
{
}

void Stage1Player::Update()
{
	if (INPUT.KeyDown(VK_F1))
	{
		for (int x = 0; x < TILESIZEX; x++)
		{
			for (int y = 0; y < TILESIZEY; y++)
			{
				gridTemp[x][y] = GAME.m_Stage1Tile[x][y];
			}
		}

		DXUTOutputDebugStringA("dmd");
	}

	if (!isHit && GAME.isStart)
	{
		Move();
	}

	if (isHit)
	{
		GoBack();

		GAME.m_playerLife--;
		CObject* stage1UI = OBJECT.Find(Tag::Stage1UI);
		stage1UI->gc<Stage1UI>()->HeartUI();
		tf->gc<CCollider>()->m_bEnable = false;
		isinvincibility = true;
		isHit = false;
		CAMERA.m_ShakeForce = 100;
	}

	if (isinvincibility)
	{
		invincibilityTime += dt;
		if (invincibilityTime < 0.5) { tf->gc<CSpriteRenderer>()->m_Color.a = 0.5; }
		if (invincibilityTime >= 0.2) { CAMERA.SetShake(); }
		if (invincibilityTime >= 0.5 && invincibilityTime < 1) { tf->gc<CSpriteRenderer>()->m_Color.a = 1; }
		if (invincibilityTime >= 1 && invincibilityTime < 1.5) { tf->gc<CSpriteRenderer>()->m_Color.a = 0.5; }
		if (invincibilityTime >= 1.5)
		{
			tf->gc<CCollider>()->m_bEnable = true;
			tf->gc<CSpriteRenderer>()->m_Color.a = 1;
			invincibilityTime = 0;
			isinvincibility = false;
		}
	}
}

void Stage1Player::LateUpdate()
{
}

void Stage1Player::OnRender()
{
}

void Stage1Player::OnDestroy()
{
}

void Stage1Player::OnCollisionEnter(CObject* _pObj)
{
	if (_pObj->m_Tag == Tag::Boss)
	{
		isHit = true;
	}
}

void Stage1Player::OnCollisionStay(CObject* _pObj)
{
}

void Stage1Player::OnCollisionExit(CObject* _pObj)
{
}

void Stage1Player::Move()
{
	int xTemp = tf->m_vPos.x - ((WINSIZEX - TILESIZEX) / 2);
	int yTemp = tf->m_vPos.y - ((WINSIZEY - TILESIZEY) / 2);

	if (INPUT.KeyDown(VK_UP))
	{
		if (moveRot != MoveRot::Down && GAME.m_Stage1Tile[xTemp][yTemp] != 1)
		{
			moveRot = MoveRot::Up;
		}

		if (GAME.m_Stage1Tile[xTemp][yTemp] == 1)
		{
			moveRot = MoveRot::Up;
		}
	}

	if (INPUT.KeyDown(VK_DOWN))
	{
		if (moveRot != MoveRot::Up && GAME.m_Stage1Tile[xTemp][yTemp] != 1)
		{
			moveRot = MoveRot::Down;
		}

		if (GAME.m_Stage1Tile[xTemp][yTemp] == 1)
		{
			moveRot = MoveRot::Down;
		}
	}

	if (INPUT.KeyDown(VK_LEFT))
	{
		if (moveRot != MoveRot::Right && GAME.m_Stage1Tile[xTemp][yTemp] != 1)
		{
			moveRot = MoveRot::Left;
		}

		if (GAME.m_Stage1Tile[xTemp][yTemp] == 1)
		{
			moveRot = MoveRot::Left;
		}
	}

	if (INPUT.KeyDown(VK_RIGHT))
	{
		if (moveRot != MoveRot::Left && GAME.m_Stage1Tile[xTemp][yTemp] != 1)
		{
			moveRot = MoveRot::Right;
		}

		if (GAME.m_Stage1Tile[xTemp][yTemp] == 1)
		{
			moveRot = MoveRot::Right;
		}
	}

	if (INPUT.KeyPress(VK_UP))
	{
		for (int i = 0; i < moveSpeed; i++)
		{
			if (GAME.m_Stage1Tile[xTemp][yTemp] == 1)
			{
				tf->m_vPos += Vec2(0, -1);
				tf->m_vRot = 0;

				if (MoveCheck1())
				{
					xPos = tf->m_vPos.x - ((WINSIZEX - TILESIZEX) / 2);
					yPos = tf->m_vPos.y - ((WINSIZEY - TILESIZEY) / 2);
					DrawLine();
					CheckFloodFill();
				}
				else if (!MoveCheck1())
				{
					tf->m_vPos += Vec2(0, 1);
				}
			}
		}
	}
	if (INPUT.KeyPress(VK_DOWN))
	{
		for (int i = 0; i < moveSpeed; i++)
		{
			if (GAME.m_Stage1Tile[xTemp][yTemp] == 1)
			{
				tf->m_vPos += Vec2(0, 1);
				tf->m_vRot = 180;

				if (MoveCheck1())
				{
					xPos = tf->m_vPos.x - ((WINSIZEX - TILESIZEX) / 2);
					yPos = tf->m_vPos.y - ((WINSIZEY - TILESIZEY) / 2);
					DrawLine();
					CheckFloodFill();
				}
				else if (!MoveCheck1())
				{
					tf->m_vPos += Vec2(0, -1);
				}
			}
		}
	}
	if (INPUT.KeyPress(VK_RIGHT))
	{
		for (int i = 0; i < moveSpeed; i++)
		{
			if (GAME.m_Stage1Tile[xTemp][yTemp] == 1)
			{
				tf->m_vPos += Vec2(1, 0);
				tf->m_vRot = 90;

				if (MoveCheck1())
				{
					xPos = tf->m_vPos.x - ((WINSIZEX - TILESIZEX) / 2);
					yPos = tf->m_vPos.y - ((WINSIZEY - TILESIZEY) / 2);
					DrawLine();
					CheckFloodFill();
				}
				else if (!MoveCheck1())
				{
					tf->m_vPos += Vec2(-1, 0);
				}
			}
		}
	}
	if (INPUT.KeyPress(VK_LEFT))
	{
		for (int i = 0; i < moveSpeed; i++)
		{
			if (GAME.m_Stage1Tile[xTemp][yTemp] == 1)
			{
				tf->m_vPos += Vec2(-1, 0);
				tf->m_vRot = 270;

				if (MoveCheck1())
				{
					xPos = tf->m_vPos.x - ((WINSIZEX - TILESIZEX) / 2);
					yPos = tf->m_vPos.y - ((WINSIZEY - TILESIZEY) / 2);
					DrawLine();
					CheckFloodFill();
				}
				else if (!MoveCheck1())
				{
					tf->m_vPos += Vec2(1, 0);
				}
			}
		}
	}



	if (moveRot == MoveRot::Up && GAME.m_Stage1Tile[xTemp][yTemp] != 1 && MoveCheck2())
	{
		for (int i = 0; i < moveSpeed - 1; i++)
		{
			tf->m_vPos += Vec2(0, -1);
			tf->m_vRot = 0;

			if (MoveCheck1() && MoveCheck2())
			{
				xPos = tf->m_vPos.x - ((WINSIZEX - TILESIZEX) / 2);
				yPos = tf->m_vPos.y - ((WINSIZEY - TILESIZEY) / 2);
				DrawLine();
				CheckFloodFill();
			}
			else if (!MoveCheck1())
			{
				tf->m_vPos += Vec2(0, 1);
			}
		}
	}
	else if (moveRot == MoveRot::Down && GAME.m_Stage1Tile[xTemp][yTemp] != 1 && MoveCheck2())
	{
		for (int i = 0; i < moveSpeed - 1; i++)
		{
			tf->m_vPos += Vec2(0, 1);
			tf->m_vRot = 180;

			if (MoveCheck1() && MoveCheck2())
			{
				xPos = tf->m_vPos.x - ((WINSIZEX - TILESIZEX) / 2);
				yPos = tf->m_vPos.y - ((WINSIZEY - TILESIZEY) / 2);
				DrawLine();
				CheckFloodFill();
			}
			else if (!MoveCheck1())
			{
				tf->m_vPos += Vec2(0, -1);
			}
		}
	}
	else if (moveRot == MoveRot::Left && GAME.m_Stage1Tile[xTemp][yTemp] != 1 && MoveCheck2())
	{
		for (int i = 0; i < moveSpeed - 1; i++)
		{
			tf->m_vPos += Vec2(-1, 0);
			tf->m_vRot = 270;

			if (MoveCheck1() && MoveCheck2())
			{
				xPos = tf->m_vPos.x - ((WINSIZEX - TILESIZEX) / 2);
				yPos = tf->m_vPos.y - ((WINSIZEY - TILESIZEY) / 2);
				DrawLine();
				CheckFloodFill();
			}
			else if (!MoveCheck1())
			{
				tf->m_vPos += Vec2(1, 0);
			}
		}
	}
	else if (moveRot == MoveRot::Right && GAME.m_Stage1Tile[xTemp][yTemp] != 1 && MoveCheck2())
	{
		for (int i = 0; i < moveSpeed - 1; i++)
		{
			tf->m_vPos += Vec2(1, 0);
			tf->m_vRot = 90;

			if (MoveCheck1() && MoveCheck2())
			{
				xPos = tf->m_vPos.x - ((WINSIZEX - TILESIZEX) / 2);
				yPos = tf->m_vPos.y - ((WINSIZEY - TILESIZEY) / 2);
				DrawLine();
				CheckFloodFill();
			}
			else if (!MoveCheck1())
			{
				tf->m_vPos += Vec2(-1, 0);
			}
		}
	}
}

bool Stage1Player::MoveCheck1()
{
	int xTemp = tf->m_vPos.x - ((WINSIZEX - TILESIZEX) / 2);
	int yTemp = tf->m_vPos.y - ((WINSIZEY - TILESIZEY) / 2);

	if ((yTemp < 0 || yTemp > TILESIZEY - 1 || xTemp < 0 || xTemp > TILESIZEX - 1) || GAME.m_Stage1Tile[xTemp][yTemp] == 3)
	{
		return false;
	}

	if (GAME.m_Stage1Tile[xTemp][yTemp] == 2 || GAME.m_Stage1Tile[xTemp][yTemp] == 1)
	{
		return true;
	}
}

bool Stage1Player::MoveCheck2()
{
	if (xPos + 2 <= TILESIZEX - 1 && xPos - 2 >= 0 && yPos + 2 <= TILESIZEY - 1 && yPos - 2 >= 0)
	{
		if (moveRot == MoveRot::Up && GAME.m_Stage1Tile[xPos][yPos - 2] == 2)
		{
			return false;
		}
		if (moveRot == MoveRot::Down && GAME.m_Stage1Tile[xPos][yPos + 2] == 2)
		{
			return false;
		}
		if (moveRot == MoveRot::Left && GAME.m_Stage1Tile[xPos - 2][yPos] == 2)
		{
			return false;
		}
		if (moveRot == MoveRot::Right && GAME.m_Stage1Tile[xPos + 2][yPos] == 2)
		{
			return false;
		}
	}

	return true;
}

void Stage1Player::DrawLine()
{
	int xLine = xPos;
	int yLine = yPos;

	if (GAME.m_Stage1Tile[xPos][yPos] == 0)
	{
		SPRITE("Stage1FrontBG")->m_pTexture->LockRect(0, &GAME.m_lockRect1, 0, D3DLOCK_DISCARD);

		DWORD* pColor = (DWORD*)GAME.m_lockRect1.pBits;
		D3DXCOLOR color = { 1, 0, 0, 1 };

		GAME.m_Stage1Tile[xLine][yPos] = 2;
		pColor[yLine * TILESIZEX + xLine] = color;

		SPRITE("Stage1FrontBG")->m_pTexture->UnlockRect(0);
	}
}

void Stage1Player::CheckFloodFill()
{
	switch (moveRot)
	{
	case Stage1Player::Up:
		if (GAME.m_Stage1Tile[xPos][yPos] == 2 && GAME.m_Stage1Tile[xPos][yPos - 1] == 1)
		{
			CheckFloodFillGrid(1, 1);
			tf->m_vPos.y -= 1;
		}
		break;
	case Stage1Player::Down:
		if (GAME.m_Stage1Tile[xPos][yPos] == 2 && GAME.m_Stage1Tile[xPos][yPos + 1] == 1)
		{
			CheckFloodFillGrid(1, 1);
			tf->m_vPos.y += 1;
		}
		break;
	case Stage1Player::Left:
		if (GAME.m_Stage1Tile[xPos][yPos] == 2 && GAME.m_Stage1Tile[xPos - 1][yPos] == 1)
		{
			CheckFloodFillGrid(1, 1);
			tf->m_vPos.x -= 1;
		}
		break;
	case Stage1Player::Right:
		if (GAME.m_Stage1Tile[xPos][yPos] == 2 && GAME.m_Stage1Tile[xPos + 1][yPos] == 1)
		{
			CheckFloodFillGrid(1, 1);
			tf->m_vPos.x += 1;
		}
		break;
	}
}

void Stage1Player::CheckFloodFillGrid(int x, int y)
{
	if (GAME.m_Stage1Tile[xPos - x][yPos - y] == 0)
	{
		FloodFill(xPos - x, yPos - y);
		FillColor();
	}

	if (GAME.m_Stage1Tile[xPos + x][yPos - y] == 0)
	{
		FloodFill(xPos + x, yPos - y);
		FillColor();
	}

	if (GAME.m_Stage1Tile[xPos - x][yPos + y] == 0)
	{
		FloodFill(xPos - x, yPos + y);
		FillColor();
	}

	if (GAME.m_Stage1Tile[xPos + x][yPos + y] == 0)
	{
		FloodFill(xPos + x, yPos + y);
		FillColor();
	}

	CObject* text = OBJECT.Find(Tag::Stage1UI);
	text->gc<Stage1UI>()->UpdateScore();
}

void Stage1Player::FillColor()
{
	SPRITE("Stage1FrontBG")->m_pTexture->LockRect(0, &GAME.m_lockRect1, 0, D3DLOCK_DISCARD);

	DWORD* pColor = (DWORD*)GAME.m_lockRect1.pBits;
	D3DXCOLOR color = { 0, 0, 0, 0 };

	for (int x = 1; x < TILESIZEX - 1; x++)
	{
		for (int y = 1; y < TILESIZEY - 1; y++)
		{
			if (GAME.m_Stage1Tile[x][y] == 1 && (!GAME.m_Stage1Tile[x + 1][y] == 0 && !GAME.m_Stage1Tile[x - 1][y] == 0 &&
				!GAME.m_Stage1Tile[x][y + 1] == 0 && !GAME.m_Stage1Tile[x][y - 1] == 0))
			{
				GAME.m_Stage1Tile[x][y] = 3;
			}
		}
	}

	for (int x = 0; x < TILESIZEX; x++)
	{
		for (int y = 0; y < TILESIZEY; y++)
		{
			if (GAME.m_Stage1Tile[x][y] == 3)
			{
				pColor[y * TILESIZEX + x] = color;
			}

			if (GAME.m_Stage1Tile[x][y] == 2)
			{
				GAME.m_Stage1Tile[x][y] = 1;
			}

		}
	}

	SPRITE("Stage1FrontBG")->m_pTexture->UnlockRect(0);
}

void Stage1Player::FloodFill(int x, int y)
{
	for (int x = 0; x < TILESIZEX; x++)
	{
		for (int y = 0; y < TILESIZEY; y++)
		{
			gridTemp[x][y] = GAME.m_Stage1Tile[x][y];
		}
	}

	CObject* boss = OBJECT.Find(Tag::Boss);
	queue<Vec2> fillQueue;

	fillQueue.push(Vec2(x, y));
	gridTemp[x][y] = 3;

	while (!fillQueue.empty())
	{
		Vec2 vTemp = fillQueue.front();
		fillQueue.pop();

		if ((int)vTemp.x + 1 <= TILESIZEX && (int)vTemp.x - 1 >= 0 && (int)vTemp.y + 1 <= TILESIZEY && (int)vTemp.y - 1 >= 0)
		{
			if (gridTemp[(int)vTemp.x + 1][(int)vTemp.y] == 0)
			{
				fillQueue.push(Vec2(vTemp.x + 1, vTemp.y));
				gridTemp[(int)vTemp.x + 1][(int)vTemp.y] = 3;
			}

			if (gridTemp[(int)vTemp.x - 1][(int)vTemp.y] == 0)
			{
				fillQueue.push(Vec2(vTemp.x - 1, vTemp.y));
				gridTemp[(int)vTemp.x - 1][(int)vTemp.y] = 3;
			}

			if (gridTemp[(int)vTemp.x][(int)vTemp.y + 1] == 0)
			{
				fillQueue.push(Vec2(vTemp.x, vTemp.y + 1));
				gridTemp[(int)vTemp.x][(int)vTemp.y + 1] = 3;
			}

			if (gridTemp[(int)vTemp.x][(int)vTemp.y - 1] == 0)
			{
				fillQueue.push(Vec2(vTemp.x, vTemp.y - 1));
				gridTemp[(int)vTemp.x][(int)vTemp.y - 1] = 3;
			}

		}

		if (!fillQueue.empty())
		{
			if (fillQueue.front() == boss->tf->m_vPos)
			{
				for (int i = 0; i < fillQueue.size(); i++)
				{
					fillQueue.pop();
				}
				return ReturnFill(fillQueue.front().x, fillQueue.front().y);
			}
		}
	}

	for (int x = 0; x < TILESIZEX; x++)
	{
		for (int y = 0; y < TILESIZEY; y++)
		{
			GAME.m_Stage1Tile[x][y] = gridTemp[x][y];
		}
	}
}

void Stage1Player::ReturnFill(int x, int y)
{
	queue<Vec2> returnQueue;
	returnQueue.push(Vec2(x, y));

	while (!returnQueue.empty())
	{
		if (GAME.m_Stage1Tile[x + 1][y] == 3)
		{
			returnQueue.push(Vec2(x + 1, y));
		}

		if (GAME.m_Stage1Tile[x - 1][y] == 3)
		{
			returnQueue.push(Vec2(x - 1, y));
		}

		if (GAME.m_Stage1Tile[x][y + 1] == 3)
		{
			returnQueue.push(Vec2(x, y + 1));
		}

		if (GAME.m_Stage1Tile[x][y - 1] == 3)
		{
			returnQueue.push(Vec2(x, y - 1));
		}

		GAME.m_Stage1Tile[x][y] == 0;

		returnQueue.pop();
	}
}

void Stage1Player::GoBack()
{
	//tf->gc<CCollider>()->m_bEnable = false;

	int xTemp = tf->m_vPos.x - ((WINSIZEX - TILESIZEX) / 2);
	int yTemp = tf->m_vPos.y - ((WINSIZEY - TILESIZEY) / 2);

	if (GAME.m_Stage1Tile[xTemp][yTemp] == 1)
		return;

	SPRITE("Stage1FrontBG")->m_pTexture->LockRect(0, &GAME.m_lockRect1, 0, D3DLOCK_DISCARD);

	DWORD* pColor = (DWORD*)GAME.m_lockRect1.pBits;
	D3DXCOLOR color = { 0, 0, 0, 1 };

	GAME.m_Stage1Tile[xPos][yPos] = 0;

	while (GAME.m_Stage1Tile[xTemp][yTemp] != 1 && xTemp != 0 && xTemp != TILESIZEX - 1 && yTemp != 0 && TILESIZEY - 1)
	{
		if (GAME.m_Stage1Tile[xTemp - 1][yTemp] == 2 && GAME.m_Stage1Tile[xTemp - 1][yTemp] != 1)
		{
			GAME.m_Stage1Tile[xTemp - 1][yTemp] = 0;
			pColor[yTemp * TILESIZEX + xTemp] = GAME.stage1Color[xTemp][yTemp];
			xTemp -= 1;
		}
		else if (GAME.m_Stage1Tile[xTemp - 1][yTemp] == 1)
		{
			xTemp -= 1;
			tf->m_vPos = Vec2(xTemp + ((WINSIZEX - TILESIZEX) / 2), yTemp + ((WINSIZEY - TILESIZEY) / 2));
			break;
		}


		if (GAME.m_Stage1Tile[xTemp + 1][yTemp] == 2 && GAME.m_Stage1Tile[xTemp + 1][yTemp] != 1)
		{
			GAME.m_Stage1Tile[xTemp + 1][yTemp] = 0;
			pColor[yTemp * TILESIZEX + xTemp] = GAME.stage1Color[xTemp][yTemp];
			xTemp += 1;
		}
		else if (GAME.m_Stage1Tile[xTemp + 1][yTemp] == 1)
		{
			xTemp += 1;
			tf->m_vPos = Vec2(xTemp + ((WINSIZEX - TILESIZEX) / 2), yTemp + ((WINSIZEY - TILESIZEY) / 2));
			break;
		}


		if (GAME.m_Stage1Tile[xTemp][yTemp - 1] == 2 && GAME.m_Stage1Tile[xTemp][yTemp - 1] != 1)
		{
			GAME.m_Stage1Tile[xTemp][yTemp - 1] = 0;
			pColor[yTemp * TILESIZEX + xTemp] = GAME.stage1Color[xTemp][yTemp];
			yTemp -= 1;
		}
		else if (GAME.m_Stage1Tile[xTemp][yTemp - 1] == 1)
		{
			yTemp -= 1;
			tf->m_vPos = Vec2(xTemp + ((WINSIZEX - TILESIZEX) / 2), yTemp + ((WINSIZEY - TILESIZEY) / 2));
			break;
		}


		if (GAME.m_Stage1Tile[xTemp][yTemp + 1] == 2 && GAME.m_Stage1Tile[xTemp][yTemp + 1] != 1)
		{
			GAME.m_Stage1Tile[xTemp][yTemp + 1] = 0;
			pColor[yTemp * TILESIZEX + xTemp] = GAME.stage1Color[xTemp][yTemp];
			yTemp += 1;
		}
		else if (GAME.m_Stage1Tile[xTemp][yTemp + 1] == 1)
		{
			yTemp += 1;
			tf->m_vPos = Vec2(xTemp + ((WINSIZEX - TILESIZEX) / 2), yTemp + ((WINSIZEY - TILESIZEY) / 2));
			break;
		}
	}

	SPRITE("Stage1FrontBG")->m_pTexture->UnlockRect(0);
}
