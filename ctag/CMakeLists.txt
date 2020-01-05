file(GLOB SRCS
    *.cpp
    *.hpp
)

add_subdirectory(json)

add_library(ctag ${SRCS})