#include "SceneManagerClass.h"

//////////////////////////////////////////////////////////////////////////////
//Ã“I•Ï”
//////////////////////////////////////////////////////////////////////////////

BaseSceneClass *SceneManagerClass::m_Scene;

SceneManagerClass::SceneManagerClass(void)
{
}


SceneManagerClass::~SceneManagerClass(void)
{
}

//////////////////////////////////////////////////////////////////////////////
//publicŠÖ”
//////////////////////////////////////////////////////////////////////////////

void SceneManagerClass::ChangeScene(_SCENE scene)
{
	static SceneTitleClass SceneTitle;
	static SceneMainClass SceneMain;

	switch (scene)
	{
	case SceneManagerClass::E_GAME_TITLE:
		m_Scene = &SceneTitle;
		break;

	case SceneManagerClass::E_GAME_MAIN:
		m_Scene = &SceneMain;
		break;
	}

}

void SceneManagerClass::Render()
{
	m_Scene->Render();
}