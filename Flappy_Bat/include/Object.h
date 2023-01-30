#pragma once

#include <olcConsoleGameEngineOOP.h>
#include "Vec2d.h"

class Object
{
protected:
	virtual void draw(CHAR_INFO* screenBuff) = 0;
	void writeToBuffer(CHAR_INFO* buffer, std::wstring fig, COLOUR col, Vec2d dim, Vec2d pos, wchar_t except = L' ');
};

