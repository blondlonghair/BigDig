#include "DXUT.h"
#include "CLoadScene.h"


CLoadScene::CLoadScene()
{
}


CLoadScene::~CLoadScene()
{
}

void CLoadScene::Init()
{
	LoadSprite("PLAYER", "��׹�1");
	LoadSprite("Stage1FrontBG", "���1");
	LoadSprite("Stage1BackBG", "�ڹ��1");
	LoadSprite("Stage2FrontBG", "���2");
	LoadSprite("Stage2BackBG", "�ڹ��2");
	LoadSprite("Stage3FrontBG", "���3");
	LoadSprite("Stage3BackBG", "�ڹ��3");
	LoadSprite("Button", "��");
	LoadSprite("Stage1Boss", "��°���");
	LoadSprite("�ӽù��", "�ӽù��ȭ��");
	LoadSprite("rightHand", "������");
	LoadSprite("leftHand", "�޼�");
}

void CLoadScene::Update()
{
	if (m_listLoadData.empty() == true)
	{
		// �ε��� ������ Ÿ��Ʋ ������ �Ѿ��
		SCENE.ChangeScene("TITLE");
	}
	else
	{
		// ����Ʈ �� �κ��� �����ͼ� ��������Ʈ���� �߰� �� ����Ʈ���� ���ֱ�
		auto data = m_listLoadData.front();
		if (data.m_Type == 1)
		{
			GRAPHICS.AddSprite(data.m_Key, data.m_Path);
		}
		m_listLoadData.pop_front();
	}
}

void CLoadScene::Render()
{
}

void CLoadScene::Release()
{
}

void CLoadScene::LoadSprite(string _Key, string _Path, int _iCount)
{
	if (_iCount == 0)
	{
		LoadData data;
		data.m_Key = _Key;
		data.m_Path = "./resource/" + _Path + ".png";
		data.m_Type = 1;
		m_listLoadData.push_back(data);
	}
	else
	{
		for (int i = 0; i < _iCount; i++)
		{
			LoadData data;
			data.m_Key = _Key + " (" + to_string(i + 1) + ")";
			data.m_Path = "./resource/" + _Path + " (" + to_string(i + 1) + ")" + ".png";
			data.m_Type = 1;
			m_listLoadData.push_back(data);
		}
	}
}