#include "Render.h"
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

size_t Render::getPxlValue(size_t i, size_t j)
{
    // if (m_pxls.at(i))
    // {

    //     auto row = m_pxls[i];
    // }
    return 0;
}

void Render::addShapes(Shape* s)
{
    // shapes.push_back(s);
}

void Render::printShapes()
{
    // std::cout << "Shapes: " << shapes.size() << std::endl;
    // for (Shape* shape : shapes)
    // {
    //     shape->printTops();
    // }
}

void Render::update()
{
    // for (auto shape : shapes)
    // {
    //     for (auto top : shape->getTops())
    //     {
    //         double x = top.getX();
    //         double y = top.getY();
    //         double z = top.getZ();
    //     }
    // }
}

void Render::show()
{
    // m_out.open(m_file_name, std::ios::out | std::ios::trunc);

    // for (auto& row : m_pxls)
    // {
    //     for (auto& point : row)
    //     {
    //         m_out << point << ' ';
    //     }
    //     m_out << std::endl;
    // }

    // m_out << "Frame: " << m_frame_counter;
    // ++m_frame_counter;

    // m_out.close();
    // pause((1 / m_FPS) * 1000); // in milliseconds
}

void Render::pause(size_t delay) const
{
    // std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}