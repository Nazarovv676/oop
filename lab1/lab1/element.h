#pragma once

#include "position.h"

class Element
{
protected:
	Element(Position position) : _position(position) {}

private:
	Position _position;

public:
	virtual void drow() = 0;
};

