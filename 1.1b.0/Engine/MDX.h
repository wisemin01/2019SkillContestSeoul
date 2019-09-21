#pragma once

class MainProcess;

class MDX
{
private:
	inline static MainProcess* g_pMainProcess = nullptr;

	static bool __stdcall IsD3D9DeviceAcceptable(D3DCAPS9* pCaps, D3DFORMAT AdapterFormat, D3DFORMAT BackBufferFormat, bool bWindowed, void* pUserContext);
	static bool __stdcall ModifyDeviceSettings(DXUTDeviceSettings* pDeviceSettings, void* pUserContext);
	static HRESULT __stdcall OnD3D9CreateDevice(IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc, void* pUserContext);
	static HRESULT __stdcall OnD3D9ResetDevice(IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc, void* pUserContext);
	static void __stdcall OnFrameMove(double fTime, float fElapsedTime, void* pUserContext);
	static void __stdcall OnD3D9FrameRender(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext);
	static LRESULT __stdcall MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, bool* pbNoFurtherProcessing, void* pUserContext);
	static void __stdcall OnD3D9LostDevice(void* pUserContext);
	static void __stdcall OnD3D9DestroyDevice(void* pUserContext);
public:

	static void CursorSetting(bool isShowCursorInFullScreen = false, bool isClipCursorInFullScreen = false);
	static void SetHotkeyHandling(bool isAltEnterToFullScreen = true, bool isEscapeToQuitApp = true, bool isPauseToTimeTogglePause = true);

	static void RegisterMainProcess(MainProcess* mainProcess);

	static void Initialize(const std::wstring& title,
		bool isWindowed,
		int width, int height,
		int x = -2147483648, int y = -2147483648,
		bool isParseCommandLine = true,
		bool isShowD3D9ErrorInMessageBox = true);

	static void Run();

	static HWND GetHWND() { return DXUTGetHWND(); }
	static LPDIRECT3DDEVICE9 GetD3D9Device() { return DXUTGetD3D9Device(); }

	static int __stdcall GetExitCode();
};
