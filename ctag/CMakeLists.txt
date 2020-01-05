include(cmake/bin2h.cmake)
include(cmake/JSONParser.cmake)

file(GLOB SOUND_PROCESSORS ctagSoundProcessor*.cpp)
foreach(VAR ${SOUND_PROCESSORS})
    get_filename_component(MYFILE_WITHOUT_EXT ${VAR} NAME_WLE)
    set(MYFILE_JSON ${CMAKE_CURRENT_SOURCE_DIR}/json/${MYFILE_WITHOUT_EXT}.json)
    if(NOT EXISTS ${MYFILE_JSON})
        message(FATAL_ERROR "JSON sound processor descriptor does not exist:${MYFILE_JSON}")
    endif()
    bin2h(SOURCE_FILE json/${MYFILE_WITHOUT_EXT}.json
        HEADER_FILE ../gen_include/${MYFILE_WITHOUT_EXT}_JSN.h
        VARIABLE_NAME ${MYFILE_WITHOUT_EXT}_JSN
        NULL_TERMINATE
    )  
endforeach()


file(GLOB SRCS
    *.cpp
    *.hpp
)

add_library(ctag ${SRCS})