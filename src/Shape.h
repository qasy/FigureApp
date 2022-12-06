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

    void printXYZ() const;

private:
    double x;
    double y;
    double z;
};

struct Shape
{
    Shape(Point3D center = Point3D(0, 0, 0), const std::vector<Point3D>& tops = {});

    void printTops();

    const std::vector<Point3D>& getTops() const;

    void setTop(size_t number, const Point3D& new_value);
    void setTops(const std::vector<Point3D>& new_tops);

private:
    Point3D center;
    std::vector<Point3D> tops;
};