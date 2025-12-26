#pragma once
#include <windows.h>
#include <cstdint>
//WindowsAPI
class WinApp
{
public://静的メンバ関数
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
public://メンバ関数
	//初期化
	void Initialize();
	//更新
	void Update();
	//終了
	void Finalize();
public://定数
	//クライアント領域のサイズ
	static const int32_t kClientWidth = 1280;
	static const int32_t kClientHeight = 720;
	//getter
	HINSTANCE GETHInstance() const { return wc.hInstance; }
	//getter
	HWND GetHwnd() const { return hwnd; }
	//メッセージの処理
	bool ProcessMessage();
	//ウィンドウクラスの設定
	WNDCLASS wc{};
private:
	//ウィンドウハンドル
	HWND hwnd = nullptr;
};