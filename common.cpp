#include "DxLib.h"
#include "common.h"

int White;
bool gameexit = true;
int framerate = 60;
int PAD1;
int key[256]; // 0:入力されていない 1:入力された瞬間 2:入力されている
int keyall;

XINPUT_STATE Xinput;
DINPUT_JOYSTATE Dinput;


void InputKey()
{
	static int input = 1;//0:キーボード　1:ゲームパッド
	static char buf[256];

	switch (input)
	{
	case 0:			
		GetHitKeyStateAll(buf);
		for (int i = 0; i < 256; i++)
		{
			if (buf[i])
			{
				if (key[i] == 0) key[i] = 1;
				else if (key[i] >= 1) key[i]++;
			}
			else key[i] = 0;
		}
		break;
	case 1:
		if (GetJoypadXInputState(DX_INPUT_PAD1, &Xinput) == -1)
		{
			if (GetJoypadDirectInputState(DX_INPUT_PAD1, &Dinput) == -1)
			{
				input = 0;
			}
		}


		if (Xinput.ThumbLX > 20000 || Xinput.Buttons[3] == 1 || Dinput.X > 500 || Dinput.POV[0] == 9000)
		{
			key[KEY_INPUT_RIGHT]++;
		}
		else
		{
			key[KEY_INPUT_RIGHT] = 0;
		}

		if (Xinput.ThumbLX < -20000 || Xinput.Buttons[2] == 1 || Dinput.X < -500 || Dinput.POV[0] == 27000)
		{
			key[KEY_INPUT_LEFT]++;
		}
		else
		{
			key[KEY_INPUT_LEFT] = 0;
		}

		if (Xinput.Buttons[14] == 1 || Dinput.Buttons[0] == 128)
		{
			key[KEY_INPUT_A]++;
		}
		else
		{
			key[KEY_INPUT_A] = 0;
		}

		if (Xinput.Buttons[13] == 1 || Dinput.Buttons[2] == 128)
		{
			key[KEY_INPUT_D]++;
		}
		else
		{
			key[KEY_INPUT_D] = 0;
		}

		if (Xinput.Buttons[12] == 1 || Dinput.Buttons[1] == 128)
		{
			key[KEY_INPUT_SPACE]++;
		}
		else
		{
			key[KEY_INPUT_SPACE] = 0;
		}
		
		if (Xinput.Buttons[4] == 1 || Dinput.Buttons[9] == 128)
		{
			key[KEY_INPUT_0]++;
		}
		else
		{
			key[KEY_INPUT_0] = 0;
		}
		break;
	default:
		break;
	}

}

void InputJoypad()
{
	PAD1 = GetJoypadInputState(DX_INPUT_PAD1);
}

void InputAllKey()//←→↑↓,escapeを省く
{
	if (key[KEY_INPUT_ESCAPE] >0|| key[KEY_INPUT_RIGHT] >0 || key[KEY_INPUT_LEFT]>0 || key[KEY_INPUT_UP]>0 || key[KEY_INPUT_DOWN]>0 )
	{
		return;
	}
	if (CheckHitKeyAll()!=0)
	{
		if (keyall == 0) keyall = 1;
		else if (keyall >= 1)keyall++;
	}
	else keyall = 0;
}

double ToRadian(double deg)
{
	//return deg*atan(1.0) *4.0 / 180.0;
	return deg * PI / 180.0;
}
