#pragma once

#include <vector>

struct Point3D;
struct Shape;

struct Point3D
{
    Point3D(double x = 0.0, double y = 0.0, double z = 0.0);

    double getX() const;
    double getY() const;
    double getZ() const;

    void printXYZ();

private:
    double x;
    double y;
    double z;
};

struct Shape
{
    Shape(Point3D center = Point3D(0, 0, 0), std::vector<Point3D> const& tops = {});

    void printTops();

    const std::vector<Point3D>& getTops() const;

    void setTop(size_t number, Point3D const& new_value);
    void setTops(const std::vector<Point3D>& new_tops);

private:
    Point3D center;
    std::vector<Point3D> tops;
};