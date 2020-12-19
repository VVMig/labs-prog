#include <windows.h>
#include <conio.h>
#include <cmath>
#include "Line.h"
#include <iostream>

using namespace std;

void line(const HDC& dc, const int x1, const int y1, const int x2, const int y2) {
    HWND hwnd = GetConsoleWindow();

    RECT WinCoord = {}; 
    GetWindowRect(hwnd, &WinCoord);

    MoveToEx(dc, WinCoord.right / 2 - x1 * 50, WinCoord.bottom / 2 + y1 * 50, 0);
    LineTo(dc, WinCoord.right / 2 - x2 * 50, WinCoord.bottom / 2 + y2 * 50);
}
int intersect(Line a, Line b);
void init(Line& a, Line& b);
void draw(Line a, Line b);

void main()
{
    Line a, b;
    init(a, b);

    switch (intersect(a, b))
    {
    case 0:
        cout << "Lines are intersect" << endl;
        break;
    case 1:
        cout << "Lines are the same" << endl;
        break;
    case -1:
        cout << "Lines are parallel" << endl;
    default:
        break;
    }

    draw(a, b);

    _getch();

}

void draw(Line a, Line b) {
    HWND hwnd = GetConsoleWindow();
    HDC dc = GetDC(hwnd);
    RECT window = {};
    HBRUSH brush;
    HPEN p1 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));

    brush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(dc, brush);

    RECT WinCoord = {};
    GetWindowRect(hwnd, &WinCoord);

    Rectangle(dc, 0, 0, WinCoord.right, WinCoord.bottom);

    SelectObject(dc, p1);
    line(dc, a.getX1(), a.getY1(), a.getX2(), a.getY2());

    p1 = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
    SelectObject(dc, p1);
    line(dc, b.getX1(), b.getY1(), b.getX2(), b.getY2());
}

void init(Line& a, Line& b) {
    double x, y;

    cout << "Line 1" << endl;

    cout << "x1,y1:";
    cin >> x >> y;

    a.setX1(x);
    a.setY1(y);

    cout << "x2,y2:";
    cin >> x >> y;

    a.setX2(x);
    a.setY2(y);

    cout << "Line 2" << endl;

    cout << "x1,y1:";
    cin >> x >> y;

    b.setX1(x);
    b.setY1(y);

    cout << "x2,y2:";
    cin >> x >> y;

    b.setX2(x);
    b.setY2(y);
}

int intersect(Line a, Line b) {
    double x1 = a.getX2() - a.getX1();
    double y1 = a.getY2() - a.getY1();  

    double x2 = b.getX2() - b.getX1();
    double y2 = b.getY2() - b.getY1();

    double c1 = -a.getX1() * y1 + a.getY1() * x1;
    double c2 = -b.getX1() * y2 + b.getY1() * x2;


    double tmp = -x1;
    x1 = y1;
    y1 = tmp;

    tmp = -x2;
    x2 = y2;
    y2 = tmp;

    if (abs(x1 * y2 - x2 * y1) < 0.00001) {
        
        return c1 == c2 ? 1 : -1;
    }
    return 0;
}