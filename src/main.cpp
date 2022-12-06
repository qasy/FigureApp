#include "Render.h"
#include "Shape.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#include <vector>

int main()
{

    double FPS    = 20;
    size_t width  = 30;
    size_t height = 30;
    size_t depth  = 30;
    // Render window = Render(width, height, depth, FPS);

    Point3D pc;
    Point3D p1(2, 0, 0);
    Point3D p2(0, 2, 0);
    Point3D p3;

    Point3D p11(6, 0, 0);
    Point3D p22(7, 2, 0);
    Point3D p33;

    Shape* triangle1 = new Shape(pc, {p1, p2, p3});
    Shape* triangle2 = new Shape(pc, {p11, p22, p33});

    // window.addShapes(triangle1);
    // window.addShapes(triangle2);
    // window.printShapes();

    delete triangle1;
    triangle1 = nullptr;

    delete triangle2;
    triangle2 = nullptr;

    //     bool isPlay = true;
    // for (; isPlay;)
    // {
    // window.show();
    // }
}