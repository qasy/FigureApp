#include "Render.h"
#include "Shape.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#include <vector>

int main()
{

    double FPS    = 2;
    size_t width  = 30;
    size_t height = 30;
    Render window = Render(width, height, FPS);

    Point3D pc;
    Point3D p1(5, 0, 1);
    Point3D p2(0, 3, 1);
    Point3D p3(5, 5, 1);
    Point3D p4(10, 5, 1);

    Point3D p11(6, 0, 2);
    Point3D p22(7, 2, 3);
    Point3D p33;

    Shape* triangle1 = new Shape(pc, {p1, p2, p3, p4});
    // // Shape* triangle2 = new Shape(pc, {p11, p22, p33});

    window.addShapes(triangle1);
    // // window.addShapes(triangle2);

    // // window.printShapes();
    // // window.show();
    // window.update();
    // // window.show();

    bool isPlay = true;
    for (; isPlay;)
    {
        window.show();
        triangle1->shiftCenter(Point3D(0, 0, 1));
        window.update();
    }

    delete triangle1;
    triangle1 = nullptr;

    // delete triangle2;
    // triangle2 = nullptr;
}
