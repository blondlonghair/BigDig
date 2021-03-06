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
	LoadSprite("Stage1FrontBG", "배경1");
	LoadSprite("Stage1BackBG", "뒤배경1");
	LoadSprite("Stage2FrontBG", "배경2");
	LoadSprite("Stage2BackBG", "뒤배경2");
	LoadSprite("Stage3FrontBG", "배경3");
	LoadSprite("Stage3BackBG", "뒤배경3");
	
	LoadSprite("PLAYER", "디그민1");
	LoadSprite("Stage1Boss", "우는거인");
	LoadSprite("Stage2Boss", "뱀");
	LoadSprite("leftHand", "왼손");
	LoadSprite("flippedLeftHand", "왼손_flip");
	LoadSprite("rightHand", "오른손");
	LoadSprite("flippedRightHand", "오른손_flip");
	
	LoadSprite("stamp", "도장/도장", 12);
	LoadSprite("papers", "서류와 테이프/서류와 테이프", 10);
	LoadSprite("TitleText", "TitleText");
	LoadSprite("TitleBG", "TitleBG");
	LoadSprite("Persent", "숫자/Persent");

	LoadSprite("number0", "숫자/0");
	LoadSprite("number1", "숫자/1");
	LoadSprite("number2", "숫자/2");
	LoadSprite("number3", "숫자/3");
	LoadSprite("number4", "숫자/4");
	LoadSprite("number5", "숫자/5");
	LoadSprite("number6", "숫자/6");
	LoadSprite("number7", "숫자/7");
	LoadSprite("number8", "숫자/8");
	LoadSprite("number9", "숫자/9");
	
	LoadSprite("Heart", "heart");
	LoadSprite("BrokenHeart", "brokenHeart");
	LoadSprite("continueText", "TitleContinueText");
	LoadSprite("Bullet", "Bullet1");
	LoadSprite("Bullet2", "Bullet2");
}

void CLoadScene::Update()
{
	if (m_listLoadData.empty() == true)
	{
		// 로딩이 끝나면 타이틀 씬으로 넘어가기
		SCENE.ChangeScene("TITLE");
	}
	else
	{
		// 리스트 앞 부분을 가져와서 스프라이트들을 추가 후 리스트에서 빼주기
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
