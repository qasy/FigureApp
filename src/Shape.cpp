#include "Shape.h"
#include <iostream>
#include <vector>

// clang-format off
Point3D::Point3D(double x, double y, double z) : x(x) , y(y) , z(z) {}

double Point3D::getX() const { return x; }
double Point3D::getY() const { return y; }
double Point3D::getZ() const { return z; }

void Point3D::printXYZ()
{
    std::cout << "x:\t" << x << " y:\t" << y << " z:\t" << z << std::endl;
}
// clang-format on

Shape::Shape(Point3D center, std::vector<Point3D> const& tops)
    : center(center)
    , tops(tops)
{
}

void Shape::printTops()
{
    std::cout << "Center: " << std::endl;
    center.printXYZ();
    std::cout << "Tops: " << tops.size() << std::endl;
    for (auto p : tops)
    {
        p.printXYZ();
    }
    std::cout << std::endl;
}

const std::vector<Point3D>& Shape::getTops() const
{
    return tops;
}

void Shape::setTop(size_t number, Point3D const& new_value)
{
    if (number < tops.size())
    {
        tops[number] = new_value;
    }
}

void Shape::setTops(const std::vector<Point3D>& new_tops)
{
    tops.assign(new_tops.begin(), new_tops.end());
}