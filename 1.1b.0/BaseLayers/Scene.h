#pragma once
#include <string>

class Scene abstract
{
	friend class SceneManager;
public:

	struct SceneProperty
	{
	public:
		bool AutoUpdate			= true;
		bool AutoSort			= true;
		bool AutoRender			= true;
		bool AutoCollisionCheck = true;
		bool AutoClearOnReleaseScene = true;
	};

	SceneProperty m_SceneProperty;

protected:
	Scene() {}
	virtual ~Scene() {}

	virtual void Initialize() = 0;
	virtual void Update() {}
	virtual void Render() {}
	virtual void Release() {}

private:

	void UpdateBase();
	void RenderBase();
	void ReleaseBase();

public:

	template<class T>
	static void RegisterScene(const std::string& key);
	static void ChangeScene(const std::string& key);
};

#include "Scene.hpp"