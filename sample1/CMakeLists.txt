cmake_minimum_required(VERSION 3.0.0)
project(sample1 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(sample1 main.cpp)

target_link_libraries(sample1 SDL2)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
