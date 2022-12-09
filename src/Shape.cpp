#include "Shape.h"
#include <iostream>
#include <vector>

// clang-format off
Point3D::Point3D(double x, double y, double z) : x(x) , y(y) , z(z) {}

void Point3D::printXYZ() const
{
    std::cout << "x:\t" << x << " y:\t" << y << " z:\t" << z << std::endl;
}

// clang-format on

Shape::Shape(Point3D center, const std::vector<Point3D>& local_tops)
    : m_center(center)
    , m_local_tops(local_tops)
{
}

std::vector<Point3D> Shape::getLocalTops() const
{
    return m_local_tops;
}

std::vector<Point3D> Shape::getGlobalTops() const
{
    std::vector<Point3D> global_tops;
    global_tops.resize(m_local_tops.size());
    for (size_t i = 0; i < m_local_tops.size(); ++i)
    {
        global_tops[i].x = m_local_tops[i].x + m_center.x;
        global_tops[i].y = m_local_tops[i].y + m_center.y;
        global_tops[i].z = m_local_tops[i].z + m_center.z;
    }

    return global_tops;
}

void Shape::setCenter(const Point3D& new_point)
{
    m_center = new_point;
}

void Shape::printTops()
{
    std::cout << "Center: " << std::endl;
    // m_center.printXYZ();
    std::cout << "Tops: " << m_local_tops.size() << std::endl;
    for (auto p : m_local_tops)
    {
        p.printXYZ();
    }
    std::cout << std::endl;
}

void Shape::shiftCenter(const Point3D& bias)
{
    m_center.x = m_center.x + bias.x;
    m_center.y = m_center.y + bias.y;
    m_center.z = m_center.z + bias.z;
}

void Shape::setTop(size_t number, const Point3D& new_value)
{
    if (number < m_local_tops.size())
    {
        m_local_tops[number] = new_value;
    }
}

void Shape::setTops(const std::vector<Point3D>& new_tops)
{
    m_local_tops.assign(new_tops.begin(), new_tops.end());
}