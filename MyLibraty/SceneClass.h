#pragma once
class BaseSceneClass
{
public:
	//�R���X�g���N�^
	BaseSceneClass(void);
	//�f�X�g���N�^
	virtual ~BaseSceneClass(void);

	//�����o�֐�

	virtual void Render() = 0;	//�V�[���̕`��
};

class SceneTitleClass :
	public BaseSceneClass
{
public:
	//�R���X�g���N�^
	SceneTitleClass();
	//�f�X�g���N�^
	~SceneTitleClass();
	
	void Render();	//�V�[���̕`��
};

class SceneMainClass :
	public BaseSceneClass
{
public:
	//�R���X�g���N�^
	SceneMainClass ();
	//�f�X�g���N�^
	~SceneMainClass ();

	void Render();	//�V�[���̕`��
};