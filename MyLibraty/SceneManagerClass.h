#pragma once
#include "singletonclass.h"
#include "SceneClass.h"

class SceneManagerClass :
	public SingletonClass<SceneManagerClass>
{
public:
	friend class SingletonClass<SceneManagerClass>;	//シングルトンからのインスタンス生成を許可する

private:
	static BaseSceneClass *m_Scene;	//シーンオブジェクト

protected:
	SceneManagerClass(void);
	virtual ~SceneManagerClass(void);

public:
	//シーン列挙型
	enum _SCENE
	{
		E_GAME_MAIN,
	};

	static void ChangeScene(_SCENE scene);	//シーンの遷移
	static void Render();	//シーンの描画
};

