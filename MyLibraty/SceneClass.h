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