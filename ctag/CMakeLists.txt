include(cmake/bin2h.cmake)
include(cmake/JSONParser.cmake)

# get all sound processor files
file(GLOB SOUND_PROCESSORS ctagSoundProcessor*.cpp)
# clean generated directory
file(REMOVE_RECURSE gen_include)
# convert JSON descriptors to c headers and extract processor IDs
foreach(VAR ${SOUND_PROCESSORS})
    # check if JSON file for sound processor exists
    get_filename_component(MYFILE_WITHOUT_EXT ${VAR} NAME_WLE)
    set(MYFILE_JSON ${CMAKE_CURRENT_SOURCE_DIR}/json/${MYFILE_WITHOUT_EXT}.json)
    if(NOT EXISTS ${MYFILE_JSON})
        message(FATAL_ERROR "JSON sound processor descriptor does not exist:${MYFILE_JSON}")
    endif()
    # convert JSON descriptor in header
    bin2h(SOURCE_FILE ${MYFILE_JSON}
        HEADER_FILE ${CMAKE_CURRENT_SOURCE_DIR}/gen_include/${MYFILE_WITHOUT_EXT}_JSN.h
        VARIABLE_NAME ${MYFILE_WITHOUT_EXT}_JSN
        NULL_TERMINATE
    )  
    # create include file for sound processor factory
    file(APPEND ${CMAKE_CURRENT_SOURCE_DIR}/gen_include/ctagSoundProcessors.h
        "#include \"${MYFILE_WITHOUT_EXT}.hpp\"\n"
        "#include \"${MYFILE_WITHOUT_EXT}_JSN.h\"\n"
    )
    # read JSON descriptor and append ID and if stereo to header file
    file(READ ${MYFILE_JSON} JSON_DATA)
    sbeParseJson(JSON_DATA_PARSED JSON_DATA)
    string(TOUPPER ${MYFILE_WITHOUT_EXT} MYFILE_WITHOUT_EXT_UC)
    file(APPEND ${CMAKE_CURRENT_SOURCE_DIR}/gen_include/${MYFILE_WITHOUT_EXT}_JSN.h
        "const unsigned char ${MYFILE_WITHOUT_EXT_UC}_ID[] = \"${JSON_DATA_PARSED.id}\\0\";\n\n"
    )
    file(APPEND ${CMAKE_CURRENT_SOURCE_DIR}/gen_include/${MYFILE_WITHOUT_EXT}_JSN.h
        "const bool ${MYFILE_WITHOUT_EXT_UC}_ISSTEREO = ${JSON_DATA_PARSED.isStereo};\n\n"
    )
    sbeClearJson(example)
endforeach()

# 

file(GLOB SRCS
    *.cpp
    *.hpp
    ./gen_include/*.h
)

add_library(ctag ${SRCS})

target_include_directories(ctag PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/gen_include
)