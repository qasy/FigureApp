#pragma once

#include "Shape.h"
#include <fstream>
#include <vector>

struct Render
{
public:
    explicit Render(size_t width = 10, size_t height = 10, double fps = 10.0);

    void update();
    void show();
    void addShapes(Shape* s);

    void printShapes();

    std::vector<double> m_depth_map;
    std::vector<char> m_pxls;

private:
    void pause(double seconds) const;

    std::vector<char> m_pxls_code;
    std::vector<Shape*> shapes;
    std::ofstream m_out;
    size_t m_max_width;
    size_t m_max_height;
    size_t m_max_depth;
    size_t m_size;
    double m_FPS;
    size_t m_frame_counter;

    std::string m_file_name;
};
