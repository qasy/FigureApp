#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

struct Render
{
    Render(size_t width = 10, size_t height = 10, double fps = 10.0);
    void show();

    std::vector<std::vector<char>> m_data;

private:
    std::ofstream m_out;
    double m_FPS;
    size_t m_width;
    size_t m_height;
    size_t m_frame_counter;

    std::string m_file_name;
    char m_base_symbol = '.';

    void pause(size_t delay) const
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
};

int main()
{
    double FPS    = 20;
    size_t width  = 30;
    size_t height = 30;
    Render window = Render(width, height, FPS);

    for (size_t i = 0; i < 100; ++i)
    {
        window.show();
    }
}

Render::Render(size_t width, size_t height, double fps)
    : m_width(width)
    , m_height(height)
    , m_FPS(fps)

{
    m_frame_counter = 0;
    m_file_name     = "frame.txt";

    m_data.resize(height);
    for (auto& row : m_data)
    {
        row.resize(width);
        for (auto& point : row)
        {
            point = m_base_symbol;
        }
    }
}

void Render::show()
{
    m_out.open(m_file_name, std::ios::out | std::ios::trunc);

    for (auto& row : m_data)
    {
        for (auto& point : row)
        {
            m_out << point << ' ';
        }
        m_out << std::endl;
    }

    m_out << "Frame: " << m_frame_counter;
    ++m_frame_counter;

    m_out.close();
    pause((1 / m_FPS) * 1000); // in milliseconds
}