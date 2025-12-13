#include "WinApp.h"
void WinApp::Initialize()
{
	//ウィンドウプロシージャ
	wc.lpfnWndProc = WindowProc;

	//ウィンドウクラス名(なんでも良い)
	wc.lpszClassName = L"CG2WindowClass";

	//インスタンスハンドル
	wc.hInstance = GetModuleHandle(nullptr);

	//カーソル
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

	//ウィンドウクラスを登録する
	RegisterClass(&wc);

		L"CG2",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		wrc.right - wrc.left,
		wrc.bottom - wrc.top,
		nullptr,
		nullptr,
		wc.hInstance,
		nullptr);
	ShowWindow(hwnd, SW_SHOW);
}
void WinApp::Update()
{

}
void WinApp::Finalize()
{
	CloseWindow(hwnd);
	CoUninitialize();
}
bool WinApp::ProcessMessage()
{
	MSG msg{};
	if (PeekMessage(msg,nullptr,0,0,PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	if (msg.message==WM_QUIT)
	{
		return true;
	}
	return false;
}