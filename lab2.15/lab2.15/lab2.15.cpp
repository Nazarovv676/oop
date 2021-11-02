#include <iostream>
#include "Map.h"
#include <string>

int main()
{
    Map<std::string, int>* am = new Map<std::string, int>();

    am->getByIndex(0);
    am->operator[]("1");
    am->operator[]("1") = 12;
    int* value = &am->operator[]("1");
   
    std::cout << std::to_string(*value) << std::endl;

    value = &am->getByIndex(0);
    std::cout << std::to_string(*value) << std::endl;

    am->operator[]("2") = 11;

    std::cout << std::to_string(am->getByIndex(0)) << std::to_string(am->getByIndex(1)) << std::endl;

    std::function<bool(_MapEntry<std::string, int>, _MapEntry<std::string, int>)> comparator = [](_MapEntry<std::string, int> a, _MapEntry<std::string, int> b) {
        return a.value < b.value;
    };
    am->sort(comparator);

    std::cout << std::to_string(am->getByIndex(0)) << std::to_string(am->getByIndex(1)) << std::endl;
}