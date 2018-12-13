#ifndef _SCENE_H_
#define _SCENE_H_

#define SCREEN_WIDTH (480)
#define SCREEN_HEIGHT (270)

class BaseScene
{
protected:
	int timer;
	int state;
public:
	BaseScene()
	{
		timer = 0;
		state = 0;
	}
	virtual ~BaseScene(){}
	virtual void Init()
	{
		timer = 0;
		state = 0;
	}
	virtual void Update() {};
	virtual void Draw() {};
	virtual void unInit() {};
	virtual void Debug() {};
};

class sceneManager
{
public:
	enum SCENE
	{
		TITLE = 0,//タイトルシーン
		GAME,		//ゲームシーン
		RESULT,
	};

	sceneManager()
	{
		start = true;
	}

	~sceneManager()
	{
		delete m_pScene;
	}

	static void changeScene(SCENE scene);
	static void Init();
	static void unInit();
	static void Update();
	static void Draw();
	static void execute();

private:
	static BaseScene* m_pScene;
	static bool start;

};


#endif