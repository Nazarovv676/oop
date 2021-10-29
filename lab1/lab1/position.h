#pragma once
#include <cassert>
class Position
{
public:
	Position(int x, int y) {
		assert(x >= 0);
		assert(y >= 0);

		_x = x;
		_y = y;
	}

private:
	int _x;
	int _y;
};

