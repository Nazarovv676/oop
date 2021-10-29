#include "line.h"
#include <iostream>

void Line::drow() 
{
	Element::drow();
    LineTo(_hdc, _to.x(), _to.y());
}
