#pragma once
#include "singletonclass.h"
#include "SceneClass.h"

class SceneManagerClass :
	public SingletonClass<SceneManagerClass>
{
public:
	friend class SingletonClass<SceneManagerClass>;	//�V���O���g������̃C���X�^���X������������

private:
	static BaseSceneClass *m_Scene;	//�V�[���I�u�W�F�N�g

protected:
	SceneManagerClass(void);
	virtual ~SceneManagerClass(void);

public:
	//�V�[���񋓌^
	enum _SCENE
	{
		E_GAME_MAIN,
	};

	static void ChangeScene(_SCENE scene);	//�V�[���̑J��
	static void Render();	//�V�[���̕`��
};

