#include "line.h"
#include <iostream>

void Line::drow()
{
	for (size_t i = 0; i < _length; i++)
	{
		std::cout << '_';
	}
}
