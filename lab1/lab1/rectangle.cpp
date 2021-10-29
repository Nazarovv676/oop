#include "rectangle.h"

void RectangleV2::drow()
{
	Element::drow();

	LineTo(_hdc, _position.x() + _width, _position.y());
	LineTo(_hdc, _position.x() + _width, _position.y() + _height);
	LineTo(_hdc, _position.x(), _position.y() + _height);
	LineTo(_hdc, _position.x(), _position.y());
}