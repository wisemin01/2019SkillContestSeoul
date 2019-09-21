#include "DXUT.h"
#include "MainProcess.h"

void MainProcess::ManagerUpdate()
{
	Timer::UpdateTimers();

	INPUTMANAGER.Update();
	SCENEMANAGER.Update();
}

void MainProcess::ManagerRender()
{
	SCENEMANAGER.Render();
}

void MainProcess::ManagerRelease()
{
	RELEASE_INSTANCE_SINGLETON(SceneManager);
	RELEASE_INSTANCE_SINGLETON(ActorManager);
	RELEASE_INSTANCE_SINGLETON(CollisionManager);
	RELEASE_INSTANCE_SINGLETON(RenderManager);
	RELEASE_INSTANCE_SINGLETON(ResourceManager);
	RELEASE_INSTANCE_SINGLETON(InputManager);

	Timer::Clear();
}

void MainProcess::ManagerOnLostDevice()
{
	RENDERMANAGER.OnResetDevice();
}

void MainProcess::ManagerOnResetDevice()
{
	RENDERMANAGER.OnLostDevice();
}
