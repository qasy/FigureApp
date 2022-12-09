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

    m_pxls_code = {'@', 'G', 'Q', 'O', 'o', '+', ':', ',', '.', '-'};

    m_max_depth = m_pxls_code.size();
    m_size      = m_max_width * m_max_height;

    m_depth_map.resize(m_max_height);
    m_pxls.resize(m_max_height);
    for (size_t i = 0; i < m_max_height; ++i)
    {
        m_depth_map[i].resize(m_max_width);
        m_pxls[i].resize(m_max_width);
        for (size_t j = 0; j < m_max_width; ++j)
        {
            m_depth_map[i][j] = m_max_depth - 1;
            m_pxls[i][j]      = m_pxls_code[m_max_depth - 1];
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
    for (size_t i = 0; i < m_max_height; ++i)
    {
        m_depth_map[i].resize(m_max_width);
        for (size_t j = 0; j < m_max_width; ++j)
        {
            m_depth_map[i][j] = m_max_depth - 1;
        }
    }

    for (Shape* shape : shapes)
    {
        for (const Point3D& top : shape->getGlobalTops())
        {
            top.printXYZ();
            double x = top.x;
            double y = top.y;
            double z = top.z;
            int row  = (int)x;
            int col  = (int)y;

            if (row >= 0 && row < m_max_height && col >= 0 && col < m_max_width)
            {
                m_depth_map[row][col] = z;
            }
        }
    }
}

void Render::show()
{
    m_out.open(m_file_name, std::ios::out | std::ios::trunc);

    for (size_t i = 0; i < m_max_height; ++i)
    {
        for (size_t j = 0; j < m_max_width; ++j)
        {
            int depth_value    = (int)m_depth_map[i][j];
            bool inRenderRange = (depth_value >= 0 && depth_value < m_max_depth);
            m_pxls[i][j]       = inRenderRange ? m_pxls_code[depth_value] : m_pxls_code[m_max_depth - 1];

            m_out << m_pxls[i][j] << ' ';
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