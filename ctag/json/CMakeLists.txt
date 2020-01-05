include(bin2h.cmake)
include(JSONParser.cmake)

file(GLOB JSON
    *.json
)

foreach(VAR ${JSON})
    get_filename_component(MYFILE_WITHOUT_EXT ${VAR} NAME_WLE)
    message(${MYFILE_WITHOUT_EXT})
    bin2h(SOURCE_FILE ${VAR} 
        HEADER_FILE ../gen_include/${MYFILE_WITHOUT_EXT}_JSN.h
        VARIABLE_NAME ${MYFILE_WITHOUT_EXT}_JSN
        NULL_TERMINATE
    )  
    file(READ ${JSON} JSON_DATA)
    sbeParseJson(JSON_DATA_PARSED JSON_DATA)
    string(TOUPPER ${MYFILE_WITHOUT_EXT} MYFILE_WITHOUT_EXT_UC)
    file(APPEND ../gen_include/${MYFILE_WITHOUT_EXT}_JSN.h "const unsigned char ${MYFILE_WITHOUT_EXT_UC}_ID[] = \"${JSON_DATA_PARSED.id}\\0\"")
    message(${JSON_DATA_PARSED.id})
    sbeClearJson(example)
endforeach()


