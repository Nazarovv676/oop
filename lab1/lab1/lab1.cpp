#include <windows.h>
#include <stdio.h>
#include "graphics.h"

int main()
{
    Element* element;

    Position rectanglePosition(100, 100);
    int rectangleWidth = 300;
    int rectangleHeight = 200;

    Position lineStartPosition(40, 110);

    element = new Line(lineStartPosition, rectanglePosition);
    element->drow();
    delete element;

    element = new Line(lineStartPosition, Position(rectanglePosition.x() + rectangleWidth, rectanglePosition.y()));
    element->drow();
    delete element;

    element = new Line(lineStartPosition, Position(rectanglePosition.x() + rectangleWidth, rectanglePosition.y() + rectangleHeight));
    element->drow();
    delete element;

    element = new Line(lineStartPosition, Position(rectanglePosition.x(), rectanglePosition.y() + rectangleHeight));
    element->drow();
    delete element;

    element = new RectangleV2(rectanglePosition, rectangleHeight, rectangleWidth);
    element->drow();
    delete element;

    getchar();
}