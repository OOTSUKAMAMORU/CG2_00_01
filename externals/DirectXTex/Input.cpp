#include"Input.h"
#include <cassert>
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")
void Input::Initialize(winApp* winApp)
{
	//借りてきたWinAppのインスタンスを記録
	this->winApp = winApp;

	HRESULT result;
	//DirectInputのインスタンス生成
	Microsoft::WRL::ComPtr<IDirectInput8>directInput = nullptr;
	result = DirectInput8Create(winApp->GetHInstance(),DIRECTINPUT_VERSION IID_IDirectInput8, (void**)&diput, nullptr);
	assert(SUCCEDED(result));
	
	//キーボードデバイス生成
	result = diput->CreateDevice(GUID_SysKeyboard, &devkeyboard, NULL);
	assert(SUCCEEDED(result));
	
	//入力データ形式のセット
	result = devkeyboard->SetDataFormat(&c_dfDIKeyboard);
	assert(SUCCEEDED(result));

	//排他制御レベルのセット
	result = devkeyboard->SetCooperativeLevel(winApp->GetH DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
	assert(SUCCEEDED(result));
}
void Input::Update()
{
	//前回のキー入力を保存
	memcpy(keyPre, key, sizeof(key));

	keyboard->Acquire();
	keyboard->GetDeviceState(sizeof(key), key);
}

bool Input::PushKey(BYTE keyNumber)
{
	if (key[keyNumber])
	{

		return true;
	}
	return false;
}
bool Input::TriggerKey(BYTE keyNumber)
{
		if (key[keyNumber]&&!keyPre[keyNumber])
		{
			return true;
		}
		return false;
	return false;
}