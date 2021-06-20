cmake_minimum_required(VERSION 3.17)

project(bomberman)

include(Findraylib.cmake)

include_directories(include)

file(GLOB SOURCES "src/*.cpp" "src/*/*.cpp")

add_executable(bomberman ${SOURCES})

if (WIN32)
set_target_properties(bomberman PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY_DEBUG <./>
)
endif (WIN32)

target_link_libraries(bomberman raylib)
