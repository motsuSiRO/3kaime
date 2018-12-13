#ifndef _COMMON_H_
#define	_COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <time.h>
#include <math.h>
#include <memory>
#include <vector>
#include <algorithm>


#define PI	(3.141592f)

//--------------------------------
//	�萔
//--------------------------------



extern bool gameexit;
extern int framerate;

void InputKey();
void InputJoypad();
void InputAllKey();
double ToRadian(double deg);

//--------------------------------
//	�}�N���֐�
//--------------------------------
#define SCREEN_WIDTH	(480)
#define SCREEN_HEIGHT	(270)

/* ==========  ���͊֌W�i�g���K�[�j  ========== */
// �L�[����
extern int key[256]; // 0:���͂���Ă��Ȃ� 1:���͂��ꂽ�u�� 2:���͂���Ă���
extern int keyall;
extern int PAD1;
extern bool slow_flg;

/* ==========  �p�x�ϊ��p  ========== */
//#define ToRadian(x) FromDgreeToRadian(x)
#define ToDegree(x) XMConvertToDegrees(x)

#endif // !_COMMON_H_