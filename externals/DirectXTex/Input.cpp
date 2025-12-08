#include"Input.h"
#include <wrl.h>
#include <dinput.h>
#define DIRECTINPUT_VERSION 0x0800
void Input::Initialize()
{
	//DirectInputのインスタンス生成
	ComPtr<IDirectInput8>directInput = nullptr;
	result = DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInputput8, (void**)&directInput, nullptr);
	assert(SUCCEDED(result));
	//キーボードデバイス生成
	ComPtr<IDirectInputDevice8>keyboard;
	result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
	assert(SUCCEEDED(result));
	//入力データ形式のセット
	result = keyboard->SetDataFormat(&c_dfDIKeyboard);
	assert(SUCCEEDED(result));
	//排他制御レベルのセット
	result = keyboard->SetCooperativeLevel(hwnd, DISCLFOREGROUND | DISCL_NOWINKEY);
	assert(SUCCEEDED(result));
}
void Input::Update()
{

}