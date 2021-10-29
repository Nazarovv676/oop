#include <windows.h>
#include <stdio.h>

int main()
{
    HDC hdc = GetDC(GetConsoleWindow());

    HPEN hPenOld;

    // Draw a red line
    HPEN hLinePen;
    COLORREF qLineColor;
    qLineColor = RGB(255, 0, 0);
    hLinePen = CreatePen(PS_SOLID, 1, qLineColor);
    hPenOld = (HPEN)SelectObject(hdc, hLinePen);

    MoveToEx(hdc, 100, 100, NULL);
    LineTo(hdc, 500, 250);

    SelectObject(hdc, hPenOld);
    DeleteObject(hLinePen);

    getchar();
}