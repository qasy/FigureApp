#include "Render.h"
#include <iostream>
#include <thread>

Render::Render(size_t width, size_t height, size_t depth, double fps)
    : m_max_width(width)
    , m_max_height(height)
    , m_max_depth(depth)
    , m_FPS(fps)

{
    m_frame_counter = 0;
    m_file_name     = "frame.txt";
    m_base_symbol   = 0;

    m_pxls.resize(height);
    for (auto& row : m_pxls)
    {
        row.resize(width);
        for (auto& point : row)
        {
            point = m_base_symbol;
        }
    }
}

size_t Render::getPxl(size_t i, size_t j)
{
    // if (m_pxls.at(i))
    // {

    //     auto row = m_pxls[i];
    // }
    return 0;
}

void Render::setPxl(size_t i, size_t j, size_t value)
{
    if (i >= 0 && i < m_pxls.size())
    {
        if (j >= 0 && j < m_pxls[i].size())
        {
            m_pxls[i][j] = value;
            std::cout << "m_pxls[i][j]: " << i << " " << j << " " << value << std::endl;
        }
    }
}

void Render::addShapes(Shape* shape)
{
    for (Shape* s : shapes)
    {
        if (s == shape)
        {
            return;
        }
    }
    shapes.push_back(shape);
}

void Render::printShapes()
{
    std::cout << "Shapes: " << shapes.size() << std::endl;
    for (Shape* shape : shapes)
    {
        shape->printTops();
    }
}

void Render::update()
{
    for (Shape* shape : shapes)
    {
        for (const Point3D& top : shape->getTops())
        {
            top.printXYZ();
            double x = top.getX();
            double y = top.getY();
            double z = top.getZ();

            setPxl(x, y, z);
        }
    }
}

void Render::show()
{
    m_out.open(m_file_name, std::ios::out | std::ios::trunc);

    for (auto& row : m_pxls)
    {
        for (auto& point : row)
        {
            m_out << point << ' ';
        }
        m_out << std::endl;
    }

    // display stats
    m_out << "Frame: " << m_frame_counter;
    ++m_frame_counter;

    m_out.close();
    pause(1 / m_FPS);
}

void Render::pause(double seconds) const
{
    // milliseconds -> seconds
    std::this_thread::sleep_for(std::chrono::milliseconds((int)(seconds * 1000)));
}