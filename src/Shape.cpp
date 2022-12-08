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

void Shape::printTops()
{
    std::cout << "Center: " << std::endl;
    m_center.printXYZ();
    std::cout << "Tops: " << m_local_tops.size() << std::endl;
    for (auto p : m_local_tops)
    {
        p.printXYZ();
    }
    std::cout << std::endl;
}

void Shape::shiftCenter(const Point3D& new_point3d)
{
    m_center.x = m_center.x + new_point3d.x;
    m_center.y = m_center.y + new_point3d.y;
    m_center.z = m_center.z + new_point3d.z;
}

std::vector<Point3D> Shape::getGlobalTops() const
{

    std::vector<Point3D> global_tops;
    global_tops.resize(m_local_tops.size());

    for (size_t i = 0; i < m_local_tops.size(); ++i)
    {
        double x       = m_center.x + m_local_tops[i].x;
        double y       = m_center.y + m_local_tops[i].y;
        double z       = m_center.z + m_local_tops[i].z;
        global_tops[i] = Point3D(x, y, z);
    }

    // // double x = m_center.getX() + m_lo Point3D global_tops = Point3D(m_center.x + m_local_tops);
    return global_tops;
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