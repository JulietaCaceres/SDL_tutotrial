cmake_minimum_required(VERSION 3.17)
project(SDL_tutorial)

# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
add_executable(SDL_tutorial main.cpp)

set(CMAKE_CXX_STANDARD 11)


find_package(SDL2)
find_package(SDL2IMAGE)

include_directories(${SDL2_INCLUDE_DIR}  ${SDL2IMAGE_INCLUDE_DIR})

target_link_libraries(SDL_tutorial ${SDL2_LIBRARY} ${SDL2IMAGE_LIBRARY})
