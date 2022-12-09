#include "Render.h"
#include "Shape.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#include <vector>

int main()
{

    double FPS    = 10;
    size_t width  = 30;
    size_t height = 30;
    Render window = Render(width, height, FPS);

    Point3D p0;
    Point3D p1(15, 15, 0);
    Point3D p2(10, 15, 1);
    Point3D p3(15, 10, 0);

    Shape* triangle1 = new Shape(p0, {p1, p2, p3});

    window.addShapes(triangle1);

    // window.printShapes();
    // window.update();
    // window.show();

    // // window.show();

    bool isPlay = true;
    for (; isPlay;)
    {
        window.show();
        // triangle1->shiftCenter(Point3D(0, 1, 0));
        window.update();
    }

    // delete triangle1;
    // triangle1 = nullptr;

    // delete triangle2;
    // triangle2 = nullptr;
}
