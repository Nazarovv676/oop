#pragma once

#include "element.h"
#include <cassert>

class Line : public Element
{
public:
    Line(Position position, int length) : Element(position) 
    {
       assert(length > 0);

       _length = length;
    }

private:
    int _length;

public:
    void drow() override;
};

