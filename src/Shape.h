#pragma once

#include <vector>

struct Point3D;
struct Shape;

struct Point3D
{
    Point3D(double x = 0.0, double y = 0.0, double z = 0.0);

    void printXYZ() const;
    double x;
    double y;
    double z;

private:
};

struct Shape
{
    Shape(Point3D center, const std::vector<Point3D>& local_tops);

    void printTops();

    std::vector<Point3D> getLocalTops() const;
    std::vector<Point3D> getGlobalTops() const;

    void setCenter(const Point3D& new_point);
    void shiftCenter(const Point3D& bias);

    void rotateAroundPoint()

    void setTop(size_t number, const Point3D& new_value);
    void setTops(const std::vector<Point3D>& new_tops);

private:
    Point3D m_center;
    std::vector<Point3D> m_local_tops;
};