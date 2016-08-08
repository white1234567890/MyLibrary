#include "SceneManagerClass.h"

//////////////////////////////////////////////////////////////////////////////
//�ÓI�ϐ�
//////////////////////////////////////////////////////////////////////////////

BaseSceneClass *SceneManagerClass::m_Scene;

SceneManagerClass::SceneManagerClass(void)
{
}


SceneManagerClass::~SceneManagerClass(void)
{
}

//////////////////////////////////////////////////////////////////////////////
//public�֐�
//////////////////////////////////////////////////////////////////////////////

void SceneManagerClass::ChangeScene(_SCENE scene)
{
	static SceneMainClass SceneMain;

	switch (scene)
	{
	case SceneManagerClass::E_GAME_MAIN:
		m_Scene = &SceneMain;
		break;
	}

}

void SceneManagerClass::Render()
{
	m_Scene->Render();
}