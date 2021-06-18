cmake_minimum_required(VERSION 3.17)

project(bomberman)

set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

include(Findraylib.cmake)

include_directories(include)

file(GLOB SOURCES "src/*.cpp" "src/*/*.cpp")

add_executable(bomberman ${SOURCES})

target_link_libraries(bomberman raylib)
