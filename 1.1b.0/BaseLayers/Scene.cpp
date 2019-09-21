#include "DXUT.h"
#include "Scene.h"

#include "../Headers/Managers.h"

void Scene::UpdateBase()
{
	if (m_SceneProperty.AutoUpdate)
		ACTORMANAGER.Update();

	if (m_SceneProperty.AutoCollisionCheck)
		COLLISIONMANAGER.Update();

	if (m_SceneProperty.AutoSort)
		RENDERMANAGER.Sort();
}

void Scene::RenderBase()
{
	if (m_SceneProperty.AutoRender)
		RENDERMANAGER.Render();
}

void Scene::ReleaseBase()
{
	if (m_SceneProperty.AutoClearOnReleaseScene)
		ACTORMANAGER.Reset();
}

void Scene::ChangeScene(const std::string& key)
{
	SCENEMANAGER.Change(key);
}
