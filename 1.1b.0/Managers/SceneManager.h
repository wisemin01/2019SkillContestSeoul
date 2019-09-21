#pragma once
#include "Singleton.h"

class Scene;

class SceneManager :
	public Singleton<SceneManager>
{
	friend class MainProcess;
private:
	std::map< std::string, Scene* > m_mapScenes;

	Scene* m_pNextScene = nullptr;
	Scene* m_pCurrentScene = nullptr;
public:
	SceneManager() {}
	~SceneManager() { Reset(); }

	template <typename T>
	void Register(const std::string& key)
	{
		if (auto find = m_mapScenes.find(key); find == m_mapScenes.end())
		{
			m_mapScenes.insert(std::make_pair(key, new T()));
			return;
		}

		if constexpr (Debug::IsDebuging == true)
		{
			string context = "SceneManager::Register<T>() : It already contains a scene with the same key.\nDuplicate name scene : ";

			context += key;

			throw already_exists_exception(context.c_str());
		}

	}

	void Change(const std::string& targetSceneKey);

private:

	void Update();
	void Render();

	void Reset();
};

#define SCENEMANAGER SceneManager::GetInstance()