#pragma once

#include "element.h"
#include <cassert>

class RectangleV2 : public Element
{
public:
    RectangleV2(Position position, int height, int width) : Element(position)
    {
        assert(height >= 0);
        assert(width >= 0);
        
        _height = height;
        _width = width;
    }

private:
    int _height;
    int _width;

public:
    void drow() override;
};

