#pragma once

class MainProcess
{
	friend class MDX;
public:
	virtual void OnInitialize() = 0;
	virtual void OnFrameUpdate() {}
	virtual void OnFrameRender() {}
	virtual void OnRelease() {}

	virtual void OnResetDevice() {}
	virtual void OnLostDevice() {}

	virtual void OnWindowMsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {}

private:
	void ManagerUpdate();
	void ManagerRender();
	void ManagerRelease();

	void ManagerOnLostDevice();
	void ManagerOnResetDevice();
};

