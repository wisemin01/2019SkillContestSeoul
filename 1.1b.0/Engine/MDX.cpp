#include "DXUT.h"
#include "MDX.h"

#define MDX_EXCEPTION_HANDLING() \
catch (const already_exists_exception& e)\
	{\
	Debug::ShowMessage("[MDX] [!] already_exists_exception", e.what(), MessageBoxType::Ok);\
	}\
	catch (const exception& e)\
	{\
		Debug::ShowMessage("[MDX] [!] std::exception", e.what(), MessageBoxType::Ok);\
	}\


bool CALLBACK MDX::IsD3D9DeviceAcceptable(D3DCAPS9* pCaps, D3DFORMAT AdapterFormat, D3DFORMAT BackBufferFormat,
	bool bWindowed, void* pUserContext)
{
	IDirect3D9* pD3D = DXUTGetD3D9Object();

	if (FAILED(pD3D->CheckDeviceFormat(pCaps->AdapterOrdinal, pCaps->DeviceType,
		AdapterFormat, D3DUSAGE_QUERY_POSTPIXELSHADER_BLENDING,
		D3DRTYPE_TEXTURE, BackBufferFormat)))
		return false;

	return true;
}


bool CALLBACK MDX::ModifyDeviceSettings(DXUTDeviceSettings* pDeviceSettings, void* pUserContext)
{
	return true;
}


HRESULT CALLBACK MDX::OnD3D9CreateDevice(IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc,
	void* pUserContext)
{
	g_pMainProcess->OnInitialize();

	return S_OK;
}


HRESULT CALLBACK MDX::OnD3D9ResetDevice(IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc,
	void* pUserContext)
{
	g_pMainProcess->OnResetDevice();
	g_pMainProcess->ManagerOnResetDevice();
	return S_OK;
}


void CALLBACK MDX::OnFrameMove(double fTime, float fElapsedTime, void* pUserContext)
{
	g_pMainProcess->OnFrameUpdate();
	g_pMainProcess->ManagerUpdate();
}


void CALLBACK MDX::OnD3D9FrameRender(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext)
{
	HRESULT hr;

	V(pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_ARGB(0, 45, 50, 170), 1.0f, 0));

	if (SUCCEEDED(pd3dDevice->BeginScene()))
	{
		g_pMainProcess->OnFrameRender();
		g_pMainProcess->ManagerRender();
		V(pd3dDevice->EndScene());
	}
}


LRESULT CALLBACK MDX::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam,
	bool* pbNoFurtherProcessing, void* pUserContext)
{
	if (g_pMainProcess)
		g_pMainProcess->OnWindowMsgProc(hWnd, uMsg, wParam, lParam);

	return 0;
}


void CALLBACK MDX::OnD3D9LostDevice(void* pUserContext)
{
	g_pMainProcess->OnLostDevice();
	g_pMainProcess->ManagerOnLostDevice();
}


void CALLBACK MDX::OnD3D9DestroyDevice(void* pUserContext)
{
	g_pMainProcess->OnRelease();
	g_pMainProcess->ManagerRelease();

	SAFE_DELETE(g_pMainProcess);
}

void MDX::CursorSetting(bool isShowCursorInFullScreen, bool isClipCursorInFullScreen)
{
	::DXUTSetCursorSettings(isShowCursorInFullScreen, isClipCursorInFullScreen);
}

void MDX::SetHotkeyHandling(bool isAltEnterToFullScreen, bool isEscapeToQuitApp, bool isPauseToTimeTogglePause)
{
	::DXUTSetHotkeyHandling(isAltEnterToFullScreen, isEscapeToQuitApp, isPauseToTimeTogglePause);
}

void MDX::RegisterMainProcess(MainProcess* mainProcess)
{
	if (mainProcess == nullptr)
		throw std::exception("mainProcess is nullptr");

	g_pMainProcess = mainProcess;
}

void MDX::Initialize(const std::wstring& title, bool isWindowed, int width, int height, int x, int y, bool isParseCommandLine, bool isShowD3D9ErrorInMessageBox)
{
	if (g_pMainProcess == nullptr)
	{
		throw exception("g_pMainProcess is nullptr");
	}

	try
	{
		::DXUTSetCallbackD3D9DeviceAcceptable((LPDXUTCALLBACKISD3D9DEVICEACCEPTABLE)IsD3D9DeviceAcceptable);
		::DXUTSetCallbackD3D9DeviceCreated((LPDXUTCALLBACKD3D9DEVICECREATED)OnD3D9CreateDevice);
		::DXUTSetCallbackD3D9DeviceReset((LPDXUTCALLBACKD3D9DEVICERESET)OnD3D9ResetDevice);
		::DXUTSetCallbackD3D9FrameRender((LPDXUTCALLBACKD3D9FRAMERENDER)OnD3D9FrameRender);
		::DXUTSetCallbackD3D9DeviceLost((LPDXUTCALLBACKD3D9DEVICELOST)OnD3D9LostDevice);
		::DXUTSetCallbackD3D9DeviceDestroyed((LPDXUTCALLBACKD3D9DEVICEDESTROYED)OnD3D9DestroyDevice);
		::DXUTSetCallbackDeviceChanging((LPDXUTCALLBACKMODIFYDEVICESETTINGS)ModifyDeviceSettings);
		::DXUTSetCallbackMsgProc((LPDXUTCALLBACKMSGPROC)MsgProc);
		::DXUTSetCallbackFrameMove((LPDXUTCALLBACKFRAMEMOVE)OnFrameMove);
		::DXUTInit(isParseCommandLine, isShowD3D9ErrorInMessageBox);
		::DXUTSetHotkeyHandling(true, true, true);
		::DXUTSetCursorSettings(true, true);
		::DXUTCreateWindow(title.c_str(), (HINSTANCE)NULL, (HICON)NULL, (HMENU)NULL, x, y);
		::DXUTCreateDevice(isWindowed, width, height);
	}
	MDX_EXCEPTION_HANDLING();
}

void MDX::Run()
{
	try 
	{
		::DXUTMainLoop();
	}
	MDX_EXCEPTION_HANDLING();
}

int __stdcall MDX::GetExitCode()
{
	return ::DXUTGetExitCode();
}
