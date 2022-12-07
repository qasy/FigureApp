#include "Render.h"
#include <iostream>
#include <thread>

Render::Render(size_t width, size_t height, double fps)
    : m_max_width(width)
    , m_max_height(height)
    , m_FPS(fps)

{
    m_frame_counter = 0;
    m_file_name     = "../frame.txt";

    m_pxls_code = {'@', 'G', 'Q', 'O', 'o', '+', ':', ',', '.', ' '};
    m_max_depth = m_pxls_code.size() - 1;

    m_depth_map.resize(height);
    m_pxls.resize(height);
    for (size_t i = 0; i < m_depth_map.size(); ++i)
    {
        m_depth_map[i].resize(width);
        m_pxls[i].resize(width);
        for (size_t j = 0; j < m_depth_map[i].size(); ++j)
        {
            m_depth_map[i][j] = m_max_depth;
            m_pxls[i][j]      = m_pxls_code[m_max_depth];
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
            // top.printXYZ();
            double x = top.getX();
            double y = top.getY();
            double z = top.getZ();
            int i    = (int)x;
            int j    = (int)y;
            int d    = (int)z;
            if (i >= 0 && i < m_max_height && j >= 0 && j < m_max_width)
            {
                m_depth_map[i][j] = z;
                m_pxls[i][j] = d;
            }

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