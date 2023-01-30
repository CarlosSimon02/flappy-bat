#include "Object.h"

void Object::writeToBuffer(CHAR_INFO* buffer, std::wstring fig, COLOUR col, Vec2d dim, Vec2d pos, wchar_t except)
{
	for (Vec2d i{}; i.y < dim.y; i.y++)
	{
		for (i.x = 0; i.x < dim.x; i.x++)
		{

			if (fig[i.point(dim.x)] != except &&
				pos.x + i.x > -1 &&
				pos.x + i.x < SWIDTH &&
				pos.y + i.y > -1 &&
				pos.y + i.y < SHEIGHT)
			{
				buffer[pos.point() + i.point()].Char.UnicodeChar = fig[i.point(dim.x)];
				buffer[pos.point() + i.point()].Attributes = col;
			}

		}
	}
}