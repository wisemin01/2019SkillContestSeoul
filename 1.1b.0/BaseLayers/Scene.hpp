#pragma once
#include "Scene.h"
#include "../Managers/SceneManager.h"

template<class T>
inline void Scene::RegisterScene(const std::string& key)
{
	SCENEMANAGER.Register<T>(key);
}