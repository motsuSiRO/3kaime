#include "DxLib.h"
#include "scene.h"



BaseScene *sceneManager::m_pScene = nullptr;
bool sceneManager::start;

void sceneManager::changeScene(SCENE scene)
{
	if (m_pScene)
	{
		delete m_pScene;
		start = true;
	}

	switch (scene)
	{
	case TITLE:
		//m_pScene = new TitleScene();
		break;
	case SCENE::GAME:
		//m_pScene = new GameScene();
		break;
	case SCENE::RESULT:
		//m_pScene = new ResultScene();
		break;
	default:
		break;
	}
}

void sceneManager::Init()
{
	m_pScene->Init();
}
void sceneManager::unInit()
{
	m_pScene->unInit();
}
void sceneManager::Update()
{
	m_pScene->Update();
}
void sceneManager::Draw()
{
	m_pScene->Draw();
	m_pScene->Debug();
}

void sceneManager::execute()
{
	if (m_pScene == nullptr)return;

	if (start)
	{
		Init();
		start = false;
	}

	Update();

	Draw();

}

