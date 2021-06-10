#include "DXUT.h"
#include "CPlayer.h"

void CPlayer::Awake()
{
	ac<CSpriteRenderer>()->Init(SPRITE("PLAYER"), SortingLayer::Default, RenderMode::Default);
}

void CPlayer::Start()
{
	//xPos = tf->m_vPos.x - ((WINSIZEX - TILESIZEX) / 2) + 1;
	//yPos = tf->m_vPos.y - ((WINSIZEY - TILESIZEY) / 2) + 1;
}

void CPlayer::Update()
{
	//for (int x = 0; x < TILESIZEX + 2; x++)
	//{
	//	for (int y = 0; y < TILESIZEY + 2; y++)
	//	{
	//		gridTemp[x][y] = GAME.m_Stage1Tile[x][y];
	//	}
	//}

	//xPos = tf->m_vPos.x - ((WINSIZEX - TILESIZEX) / 2) + 1;
	//yPos = tf->m_vPos.y - ((WINSIZEY - TILESIZEY) / 2) + 1;

	//if ((yPos < 1 || yPos > TILESIZEY || xPos < 1 || xPos > TILESIZEX))
	//{
	//	if (moveRot == MoveRot::Up)
	//	{
	//		tf->m_vPos = Vec2(tf->m_vPos.x, ((WINSIZEY - TILESIZEY) / 2));
	//	}
	//	if (moveRot == MoveRot::Down)
	//	{
	//		tf->m_vPos = Vec2(tf->m_vPos.x, TILESIZEY + ((WINSIZEY - TILESIZEY) / 2));
	//	}
	//	if (moveRot == MoveRot::Left)
	//	{
	//		tf->m_vPos = Vec2(((WINSIZEX - TILESIZEX) / 2), tf->m_vPos.y);
	//	}
	//	if (moveRot == MoveRot::Right)
	//	{
	//		tf->m_vPos = Vec2(TILESIZEX + ((WINSIZEX - TILESIZEX) / 2), tf->m_vPos.y);
	//	}
	//}

	if (INPUT.KeyDown('S'))
	{
		for (int x = 0; x < TILESIZEX + 2; x++)
		{
			for (int y = 0; y < TILESIZEY + 2; y++)
			{
				gridTemp[x][y] = GAME.m_Stage1Tile[x][y];
			}
		}
	}

	Move();
}

void CPlayer::LateUpdate()
{
}

void CPlayer::OnRender()
{
}

void CPlayer::OnDestroy()
{
}

void CPlayer::OnCollisionEnter(CObject* _pObj)
{
}
void CPlayer::OnCollisionStay(CObject* _pObj)
{
}

void CPlayer::OnCollisionExit(CObject* _pObj)
{
}

void CPlayer::Move()
{
	//int xTemp = tf->m_vPos.x + 1;
	//int yTemp = tf->m_vPos.y + 1;

	if (INPUT.KeyPress(VK_UP) && moveRot != Down)
	{
		OutputDebugStringA("\nUp");
		moveRot = MoveRot::Up;

		tf->m_vPos += Vec2(0, -1) * dt * 100;
		tf->m_vRot = 0;

		if (MoveCheck() == 0)
		{
			xPos = tf->m_vPos.x - ((WINSIZEX - TILESIZEX) / 2) + 1;
			yPos = tf->m_vPos.y - ((WINSIZEY - TILESIZEY) / 2) + 1;
			DrawLine();
			CheckFloodFill();
		}
		else if (MoveCheck() == 1)
		{
			tf->m_vPos += Vec2(0, 1) * dt * 100;
			//tf->m_vPos = Vec2(tf->m_vPos.x, ((WINSIZEY - TILESIZEY) / 2));
		}
		if (!MoveCheck2())
		{
			tf->m_vPos += Vec2(0, 1) * dt * 100;
			GAME.m_Stage1Tile[xPos][yPos + 1] = 0;
		}
	}
	else if (INPUT.KeyPress(VK_DOWN) && moveRot != Up)
	{
		OutputDebugStringA("\nDown");
		moveRot = MoveRot::Down;

		tf->m_vPos += Vec2(0, 1) * dt * 100;
		tf->m_vRot = 180;

		if (MoveCheck() == 0)
		{
			xPos = tf->m_vPos.x - ((WINSIZEX - TILESIZEX) / 2) + 1;
			yPos = tf->m_vPos.y - ((WINSIZEY - TILESIZEY) / 2) + 1;
			DrawLine();
			CheckFloodFill();
		}
		else if (MoveCheck() == 1)
		{
			tf->m_vPos += Vec2(0, -1) * dt * 100;
			//tf->m_vPos = Vec2(tf->m_vPos.x, TILESIZEY + ((WINSIZEY - TILESIZEY) / 2));
		}
		if (!MoveCheck2())
		{
			tf->m_vPos += Vec2(0, -1) * dt * 100;
			GAME.m_Stage1Tile[xPos][yPos - 1] = 0;
		}
	}
	else if (INPUT.KeyPress(VK_LEFT) && moveRot != Right)
	{
		OutputDebugStringA("\nLeft");
		moveRot = MoveRot::Left;

		tf->m_vPos += Vec2(-1, 0) * dt * 100;
		tf->m_vRot = 270;

		if (MoveCheck() == 0)
		{
			xPos = tf->m_vPos.x - ((WINSIZEX - TILESIZEX) / 2) + 1;
			yPos = tf->m_vPos.y - ((WINSIZEY - TILESIZEY) / 2) + 1;
			DrawLine();
			CheckFloodFill();
		}
		else if (MoveCheck() == 1)
		{
			tf->m_vPos += Vec2(1, 0) * dt * 100;
			//tf->m_vPos = Vec2(((WINSIZEX - TILESIZEX) / 2), tf->m_vPos.y);
		}
		if (!MoveCheck2())
		{
			tf->m_vPos += Vec2(1, 0) * dt * 100;
			GAME.m_Stage1Tile[xPos + 1][yPos] = 0;

		}
	}
	else if (INPUT.KeyPress(VK_RIGHT) && moveRot != Left)
	{
		OutputDebugStringA("\nRight");
		moveRot = MoveRot::Right;

		tf->m_vPos += Vec2(1, 0) * dt * 100;
		tf->m_vRot = 90;

		if (MoveCheck() == 0)
		{
			xPos = tf->m_vPos.x - ((WINSIZEX - TILESIZEX) / 2) + 1;
			yPos = tf->m_vPos.y - ((WINSIZEY - TILESIZEY) / 2) + 1;
			DrawLine();
			CheckFloodFill();
		}
		else if (MoveCheck() == 1)
		{
			tf->m_vPos += Vec2(-1, 0) * dt * 100;
			//tf->m_vPos = Vec2(TILESIZEX + ((WINSIZEX - TILESIZEX) / 2), tf->m_vPos.y);
		}
		if (!MoveCheck2())
		{
			tf->m_vPos += Vec2(-1, 0) * dt * 100;
			GAME.m_Stage1Tile[xPos - 1][yPos] = 0;
		}
	}
}

int CPlayer::MoveCheck()
{
	int xTemp = tf->m_vPos.x - ((WINSIZEX - TILESIZEX) / 2) + 1;
	int yTemp = tf->m_vPos.y - ((WINSIZEY - TILESIZEY) / 2) + 1;

	if ((yTemp < 1 || yTemp > TILESIZEY || xTemp < 1 || xTemp > TILESIZEX))
	{
		return 1;
	}

	//switch (moveRot)
	//{
	//case CPlayer::Up:
	//	if (GAME.m_Stage1Tile[xTemp][yTemp - 1] == 2) { return 1; }
	//	break;
	//case CPlayer::Down:
	//	if (GAME.m_Stage1Tile[xTemp][yTemp + 1] == 2) { return 1; }
	//	break;
	//case CPlayer::Left:
	//	if (GAME.m_Stage1Tile[xTemp - 1][yTemp] == 2) { return 1; }
	//	break;
	//case CPlayer::Right:
	//	if (GAME.m_Stage1Tile[xTemp + 1][yTemp] == 2) { return 1; }
	//	break;
	//}
	else
	{
		return 0;
	}
}

bool CPlayer::MoveCheck2()
{
	//int xTemp = tf->m_vPos.x - ((WINSIZEX - TILESIZEX) / 2) + 1;
	//int yTemp = tf->m_vPos.y - ((WINSIZEY - TILESIZEY) / 2) + 1;

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

	//switch (moveRot)
	//{
	//case MoveRot::Up:
	//	if (GAME.m_Stage1Tile[xPos][yPos - 2] == 2)
	//	{
	//		return false;
	//	}
	//case MoveRot::Down:
	//	if (GAME.m_Stage1Tile[xPos][yPos + 2] == 2)
	//	{
	//		return false;
	//	}
	//case MoveRot::Left:
	//	if (GAME.m_Stage1Tile[xPos - 2][yPos] == 2)
	//	{
	//		return false;
	//	}
	//case MoveRot::Right:
	//	if (GAME.m_Stage1Tile[xPos + 2][yPos] == 2)
	//	{
	//		return false;
	//	}
	//}

	return true;
}

void CPlayer::DrawLine()
{
	int xLine = xPos - 1/* + 1*/;
	int yLine = yPos - 1/* + 1*/;

	if (GAME.m_Stage1Tile[xPos][yPos] == 0)
	{
		GAME.m_Stage1Tile[xPos][yPos] = 2;

		SPRITE("Stage1FrontBG")->m_pTexture->LockRect(0, &GAME.m_lockRect, 0, D3DLOCK_DISCARD);

		//GAME.m_Stage1Tile[xPos][yPos] = 2;

		DWORD* pColor = (DWORD*)GAME.m_lockRect.pBits;
		D3DXCOLOR color = { 1, 0, 0, 1 };
		if (moveRot == MoveRot::Up)
		{
			GAME.m_Stage1Tile[xLine/* - 1*/][yLine + 1] = 2;
			//GAME.m_Stage1Tile[xLine + 1][yLine] = 2;

			pColor[yLine * TILESIZEX + xLine] = color;
			pColor[(yLine + 1) * TILESIZEX + xLine] = color;
		}
		if (moveRot == MoveRot::Down)
		{
			GAME.m_Stage1Tile[xLine/* + 1*/][yLine - 1] = 2;
			//GAME.m_Stage1Tile[xLine - 1][yLine/* - 1*/] = 2;

			pColor[yLine * TILESIZEX + xLine] = color;
			pColor[(yLine - 1) * TILESIZEX + xLine] = color;
		}
		if (moveRot == MoveRot::Left)
		{
			GAME.m_Stage1Tile[xLine + 1][yLine/* - 1*/] = 2;
			//GAME.m_Stage1Tile[xLine/* + 1*/][yLine + 1] = 2;

			pColor[(yLine)*TILESIZEX + xLine] = color;
			pColor[(yLine)*TILESIZEX + (xLine + 1)] = color;
		}
		if (moveRot == MoveRot::Right)
		{
			GAME.m_Stage1Tile[xLine - 1][yLine/* + 1*/] = 2;
			//GAME.m_Stage1Tile[xLine/* - 1*/][yLine - 1] = 2;

			pColor[(yLine)*TILESIZEX + xLine] = color;
			pColor[(yLine)*TILESIZEX + (xLine - 1)] = color;
		}

		SPRITE("Stage1FrontBG")->m_pTexture->UnlockRect(0);
	}
}

void CPlayer::CheckFloodFill()
{
	switch (moveRot)
	{
	case CPlayer::Up:
		if (GAME.m_Stage1Tile[xPos][yPos] == 2 && GAME.m_Stage1Tile[xPos][yPos - 1] == 1)
		{
			CheckFloodFillGrid();
		}
		break;
	case CPlayer::Down:
		if (GAME.m_Stage1Tile[xPos][yPos] == 2 && GAME.m_Stage1Tile[xPos][yPos + 1] == 1)
		{
			CheckFloodFillGrid();
		}
		break;
	case CPlayer::Left:
		if (GAME.m_Stage1Tile[xPos][yPos] == 2 && GAME.m_Stage1Tile[xPos - 1][yPos] == 1)
		{
			CheckFloodFillGrid();
		}
		break;
	case CPlayer::Right:
		if (GAME.m_Stage1Tile[xPos][yPos] == 2 && GAME.m_Stage1Tile[xPos + 1][yPos] == 1)
		{
			CheckFloodFillGrid();
		}
		break;
	}
}

void CPlayer::CheckFloodFillGrid()
{
	if (GAME.m_Stage1Tile[xPos - 1][yPos - 1] == 0)
	{
		FloodFill(xPos - 1, yPos - 1);
		FillColor();
	}

	if (GAME.m_Stage1Tile[xPos + 1][yPos - 1] == 0)
	{
		FloodFill(xPos + 1, yPos - 1);
		FillColor();
	}

	if (GAME.m_Stage1Tile[xPos - 1][yPos + 1] == 0)
	{
		FloodFill(xPos - 1, yPos + 1);
		FillColor();
	}

	if (GAME.m_Stage1Tile[xPos + 1][yPos + 1] == 0)
	{
		FloodFill(xPos + 1, yPos + 1);
		FillColor();
	}
}

void CPlayer::FillColor()
{
	SPRITE("Stage1FrontBG")->m_pTexture->LockRect(0, &GAME.m_lockRect, 0, D3DLOCK_DISCARD);

	DWORD* pColor = (DWORD*)GAME.m_lockRect.pBits;
	D3DXCOLOR color = { 0, 0, 0, 0 };

	for (int x = 0; x < TILESIZEX; x++)
	{
		for (int y = 0; y < TILESIZEY; y++)
		{
			if (GAME.m_Stage1Tile[x][y] == 3)
			{
				pColor[(y + 1) * TILESIZEX + (x + 1)] = color;
				GAME.m_Stage1Tile[x + 1][y + 1] = 1;
			}

			//if (GAME.m_Stage1Tile[x][y] == 2)
			//{
			//	GAME.m_Stage1Tile[x][y] = 1;
			//}
		}
	}

	SPRITE("Stage1FrontBG")->m_pTexture->UnlockRect(0);
}

void CPlayer::FloodFill(int x, int y)
{
	for (int x = 0; x < TILESIZEX + 2; x++)
	{
		for (int y = 0; y < TILESIZEY + 2; y++)
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

		if (gridTemp[(int)vTemp.x + 1][(int)vTemp.y] == 0 && vTemp.x + 1 > 0 && vTemp.x + 1 < 1800 && vTemp.y > 0 && vTemp.y < 960)
		{
			fillQueue.push(Vec2(vTemp.x + 1, vTemp.y));
			gridTemp[(int)vTemp.x + 1][(int)vTemp.y] = 3;
		}

		if (gridTemp[(int)vTemp.x - 1][(int)vTemp.y] == 0 && vTemp.x - 1 > 0 && vTemp.x - 1 < 1800 && vTemp.y > 0 && vTemp.y < 960)
		{
			fillQueue.push(Vec2(vTemp.x - 1, vTemp.y));
			gridTemp[(int)vTemp.x - 1][(int)vTemp.y] = 3;
		}

		if (gridTemp[(int)vTemp.x][(int)vTemp.y + 1] == 0 && vTemp.x > 0 && vTemp.x < 1800 && vTemp.y + 1 > 0 && vTemp.y + 1 < 960)
		{
			fillQueue.push(Vec2(vTemp.x, vTemp.y + 1));
			gridTemp[(int)vTemp.x][(int)vTemp.y + 1] = 3;
		}

		if (gridTemp[(int)vTemp.x][(int)vTemp.y - 1] == 0 && vTemp.x > 0 && vTemp.x < 1800 && vTemp.y - 1 > 0 && vTemp.y - 1 < 960)
		{
			fillQueue.push(Vec2(vTemp.x, vTemp.y - 1));
			gridTemp[(int)vTemp.x][(int)vTemp.y - 1] = 3;
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

void CPlayer::ReturnFill(int x, int y)
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
