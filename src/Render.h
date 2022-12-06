#pragma once

#include "Shape.h"
#include <fstream>
#include <vector>

struct Render;

struct Render
{
public:
    explicit Render(size_t width = 10, size_t height = 10, size_t depth = 10, double fps = 10.0);
    void addShapes(Shape* s);
    void update();
    void show();

    void printShapes();
    size_t getPxlValue(size_t i, size_t j);

    std::vector<std::vector<int>> m_pxls;

private:
    void pause(size_t delay) const;

    std::vector<Shape*> shapes;
    std::ofstream m_out;
    size_t m_max_width;
    size_t m_max_height;
    size_t m_max_depth;
    double m_FPS;
    size_t m_frame_counter;

    std::string m_file_name;
    char m_base_symbol;
};
