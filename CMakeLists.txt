cmake_minimum_required(VERSION 3.0.0)
project(CTAG-Plug VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(ctag)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ctag)

add_executable(CTAG-Plug main.cpp)
target_link_libraries(CTAG-Plug ctag)
target_include_directories(CTAG-Plug PRIVATE ctag)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
