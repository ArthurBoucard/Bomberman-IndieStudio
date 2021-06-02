cmake_minimum_required(VERSION 3.17)

project(indie)

include(Findraylib.cmake)

include_directories(include)

file(GLOB SOURCES "src/*.cpp" "src/*/*.cpp")

add_executable(bomberman ${SOURCES})

target_link_libraries(bomberman raylib)
