#pragma once

#include "element.h"
#include <cassert>

class Line : public Element
{
public:
    Line(Position from, Position to) : Element(from) {
        _to = to;
    }

    Line(Position from, Position to, COLORREF color) : Element(from, color) {
        _to = to;
    }

    Position from() {
        return _position;
    }

    Position to() {
        return _to;
    }

private:
    Position _to;

public:
    void drow() override;
};

