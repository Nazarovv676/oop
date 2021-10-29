#pragma once

#include "position.h"
#include <windows.h>

class Element
{
protected:
	Element(Position position) : _position(position) {
		_color = RGB(255, 255, 255);
		_prepareGDI();
	}

	Element(Position position, COLORREF color) : _position(position) {
		_color = color;
		_prepareGDI();
	}

	Position _position;
	COLORREF _color;

	HDC _hdc;
	HPEN _pen;

private:
	void _prepareGDI() {
		_hdc = GetDC(GetConsoleWindow());
		_pen = CreatePen(PS_SOLID, 1, _color);
	}

	void _applyPosiiton() {
		MoveToEx(_hdc, _position.x(), _position.y(), NULL);
	}

	void _selectPen() {
		SelectObject(_hdc, _pen);
	}

public:
	virtual void drow() {
		_applyPosiiton();
		_selectPen();
	};

	~Element() {
		DeleteObject(_pen);
	}
};

