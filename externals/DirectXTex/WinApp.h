#pragma once
#include <windows.h>
//WindowsAPI
class WinApp 
{
	//メッセージの処理
	bool ProcessMessage();

	pcblic;//静的メンバ関数
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, lparam);
public://メンバ関数
	//初期化
	void Initialize();

	//更新
	void Update();

	//終了
	voidFinalize();

public://定数

	//クライアント領域のサイズ
	static const int32_t kClientWidth = 1280;
	static const int32_t kCientHeight = 720;
private:
	//ウィンドウサイズ
	HWHD hwnd = nullptr;

	//getter
	HWND GetHwnd() cost { return hwnd; }
private:
	WNDCLASS wc{}
		//ウィンドウクラスの設定
	WNDCLASS wc{};

	HINSTANCE GETHInstance() const {return wc.hInstance}

}