#pragma once
#include<Windows.h>
#include<iostream>
#include"KeyEvent.h"

using namespace std;

KeyEvent::KeyEvent()
{
	hln = GetStdHandle(STD_INPUT_HANDLE);
	EventCount = 1;
}

int KeyEvent::getKey()
{
	ReadConsoleInput(hln, &InRec, 1, &NumRead);
	if (InRec.EventType == KEY_EVENT)
	{
		if (InRec.Event.KeyEvent.bKeyDown)
		{
			downKey = InRec.Event.KeyEvent.wVirtualKeyCode;
			return downKey;
		}
		else
			return -1;
	}
	return -1;
}