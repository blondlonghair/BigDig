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
	if (INPUT.KeyDown('S'))
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
		//GoBack();
		isHit = false;
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
}
void Stage1Player::OnCollisionStay(CObject* _pObj)
{
}

void Stage1Player::OnCollisionExit(CObject* _pObj)
{
}

void Stage1Player::Move()
{
	if (INPUT.KeyPress(VK_UP) && moveRot != Down)
	{
		for (int i = 0; i < moveSpeed; i++)
		{
			//OutputDebugStringA("\nUp");
			moveRot = MoveRot::Up;

			tf->m_vPos += Vec2(0, -1)/* * dt * 80*/;
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
				tf->m_vPos += Vec2(0, 1)/* * dt * 80*/;
			}
			if (!MoveCheck2())
			{
				tf->m_vPos += Vec2(0, 1)/* * dt * 80*/;
				GAME.m_Stage1Tile[xPos][yPos + 1] = 0;
			}
		}
	}
	else if (INPUT.KeyPress(VK_DOWN) && moveRot != Up)
	{
		for (int i = 0; i < moveSpeed; i++)
		{
			//OutputDebugStringA("\nDown");
			moveRot = MoveRot::Down;

			tf->m_vPos += Vec2(0, 1)/* * dt * 80*/;
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
				tf->m_vPos += Vec2(0, -1)/* * dt * 80*/;
			}
			if (!MoveCheck2())
			{
				tf->m_vPos += Vec2(0, -1)/* * dt * 80*/;
				GAME.m_Stage1Tile[xPos][yPos - 1] = 0;
			}
		}
	}
	else if (INPUT.KeyPress(VK_LEFT) && moveRot != Right)
	{
		for (int i = 0; i < moveSpeed; i++)
		{
			//OutputDebugStringA("\nLeft");
			moveRot = MoveRot::Left;

			tf->m_vPos += Vec2(-1, 0)/* * dt * 80*/;
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
				tf->m_vPos += Vec2(1, 0)/* * dt * 80*/;
			}
			if (!MoveCheck2())
			{
				tf->m_vPos += Vec2(1, 0)/* * dt * 80*/;
				GAME.m_Stage1Tile[xPos + 1][yPos] = 0;
			}
		}
	}
	else if (INPUT.KeyPress(VK_RIGHT) && moveRot != Left)
	{
		for (int i = 0; i < moveSpeed; i++)
		{
			//OutputDebugStringA("\nRight");
			moveRot = MoveRot::Right;

			tf->m_vPos += Vec2(1, 0)/* * dt * 80*/;
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
				tf->m_vPos += Vec2(-1, 0)/* * dt * 80*/;
			}
			if (!MoveCheck2())
			{
				tf->m_vPos += Vec2(-1, 0)/* * dt * 80*/;
				GAME.m_Stage1Tile[xPos - 1][yPos] = 0;
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
		SPRITE("Stage1FrontBG")->m_pTexture->LockRect(0, &GAME.m_lockRect, 0, D3DLOCK_DISCARD);

		DWORD* pColor = (DWORD*)GAME.m_lockRect.pBits;
		D3DXCOLOR color = { 1, 0, 0, 1 };

		GAME.m_Stage1Tile[xLine][yPos] = 2;
		pColor[yLine * TILESIZEX + xLine] = color;

		if (moveRot == MoveRot::Up)
		{
			GAME.m_Stage1Tile[xLine][yLine + 1] = 2;
			pColor[(yLine + 1) * TILESIZEX + xLine] = color;
		}
		if (moveRot == MoveRot::Down)
		{
			GAME.m_Stage1Tile[xLine][yLine - 1] = 2;
			pColor[(yLine - 1) * TILESIZEX + xLine] = color;
		}
		if (moveRot == MoveRot::Left)
		{
			GAME.m_Stage1Tile[xLine + 1][yLine] = 2;
			pColor[yLine * TILESIZEX + (xLine + 1)] = color;
		}
		if (moveRot == MoveRot::Right)
		{
			GAME.m_Stage1Tile[xLine - 1][yLine] = 2;
			pColor[yLine * TILESIZEX + (xLine - 1)] = color;
		}

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
}

void Stage1Player::FillColor()
{
	SPRITE("Stage1FrontBG")->m_pTexture->LockRect(0, &GAME.m_lockRect, 0, D3DLOCK_DISCARD);

	DWORD* pColor = (DWORD*)GAME.m_lockRect.pBits;
	D3DXCOLOR color = { 0, 0, 0, 0 };

	for (int x = 1; x < TILESIZEX - 1; x++)
	{
		for (int y = 1; y < TILESIZEY - 1; y++)
		{
			if (GAME.m_Stage1Tile[x][y] == 1 && (!GAME.m_Stage1Tile[x + 1][y] == 0 && !GAME.m_Stage1Tile[x - 1][y] == 0 && !GAME.m_Stage1Tile[x][y + 1] == 0 && !GAME.m_Stage1Tile[x][y - 1] == 0))
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

	CObject* text = OBJECT.Find(Tag::Stage1Score);
	text->gc<Stage1Score>()->UpdateScore();
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
	tf->gc<CCollider>()->m_bEnable = false;

	GAME.m_Stage1Tile[xPos][yPos] = 0;

	while ((GAME.m_Stage1Tile[xPos - 1][yPos] == 2 || GAME.m_Stage1Tile[xPos + 1][yPos] == 2 || GAME.m_Stage1Tile[xPos][yPos - 1] == 2 || GAME.m_Stage1Tile[xPos][yPos + 1] == 2))
	{
		xPos = tf->m_vPos.x - ((WINSIZEX - TILESIZEX) / 2);
		yPos = tf->m_vPos.y - ((WINSIZEY - TILESIZEY) / 2);

		if (GAME.m_Stage1Tile[xPos - 1][yPos] == 2)
		{
			//OutputDebugStringA("GAME.m_Stage1Tile[xPos - 1][yPos] == 2\n");
			GAME.m_Stage1Tile[xPos - 1][yPos] == 0;
			tf->m_vPos.x -= 1;
			//xPos -= 1;
		}

		else if (GAME.m_Stage1Tile[xPos + 1][yPos] == 2)
		{
			//OutputDebugStringA("GAME.m_Stage1Tile[xPos + 1][yPos] == 2\n");
			GAME.m_Stage1Tile[xPos + 1][yPos] == 0;
			tf->m_vPos.x += 1;
			//xPos += 1;
		}

		else if (GAME.m_Stage1Tile[xPos][yPos - 1] == 2)
		{
			//OutputDebugStringA("GAME.m_Stage1Tile[xPos][yPos - 1] == 2\n");
			GAME.m_Stage1Tile[xPos][yPos - 1] == 0;
			tf->m_vPos.y -= 1;
			//yPos -= 1;
		}

		else if (GAME.m_Stage1Tile[xPos][yPos + 1] == 2)
		{
			//OutputDebugStringA("GAME.m_Stage1Tile[xPos][yPos + 1] == 2\n");
			GAME.m_Stage1Tile[xPos][yPos + 1] == 0;
			tf->m_vPos.x += 1;
			//yPos += 1;
		}

		else
		{
			break;
		}

		//char xbuffer[20];
		//char ybuffer[20];
		//_itoa_s(xPos, xbuffer, 20, 2);
		//_itoa_s(yPos, ybuffer, 20, 2);
		//LPCSTR x = xbuffer;
		//LPCSTR y = ybuffer;
		//OutputDebugStringA(x);
		//OutputDebugStringA(y);
	}
}
