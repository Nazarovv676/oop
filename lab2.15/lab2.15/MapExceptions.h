#pragma once

#include <stdexcept>

class MapLengthException : public std::logic_error {
public:
    MapLengthException() : std::logic_error("Invalig length of array") {}
};

class MapRangeException : public std::logic_error {
public:
    MapRangeException() : std::logic_error("Out of range") {}
};
