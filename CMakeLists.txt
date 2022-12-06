cmake_minimum_required(VERSION 3.21)

project(FigureApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC src/main.cpp
        src/Shape.cpp        
        src/Render.cpp        
)


# include_directories(src/)

add_executable(${PROJECT_NAME} ${SRC})