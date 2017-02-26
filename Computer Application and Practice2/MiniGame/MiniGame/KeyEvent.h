#pragma once
#include<Windows.h>
#include<iostream>

using namespace std;

class KeyEvent
{
private:
	HANDLE hln;
	COORD KeyWhere;
	DWORD EventCount;
	INPUT_RECORD InRec;
	DWORD NumRead;
	int downKey;
public:
	KeyEvent();
	int getKey();
};