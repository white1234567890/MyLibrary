#pragma once
class BaseSceneClass
{
public:
	//コンストラクタ
	BaseSceneClass(void);
	//デストラクタ
	virtual ~BaseSceneClass(void);

	//メンバ関数

	virtual void Render() = 0;	//シーンの描画
};

class SceneTitleClass :
	public BaseSceneClass
{
public:
	//コンストラクタ
	SceneTitleClass();
	//デストラクタ
	~SceneTitleClass();
	
	void Render();	//シーンの描画
};

class SceneMainClass :
	public BaseSceneClass
{
public:
	//コンストラクタ
	SceneMainClass ();
	//デストラクタ
	~SceneMainClass ();

	void Render();	//シーンの描画
};