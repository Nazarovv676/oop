#pragma once
#include <cassert>
class Position
{
public:
	Position() : Position(0, 0) {}

	Position(int x, int y) {
		assert(x >= 0);
		assert(y >= 0);

		_x = x;
		_y = y;
	}

	Position(const Position& old_obj) {
		_x = old_obj._x;
		_y = old_obj._y;
	}

	int x() {
		return _x;
	}

	int y() {
		return _y;
	}

private:
	int _x;
	int _y;
};

