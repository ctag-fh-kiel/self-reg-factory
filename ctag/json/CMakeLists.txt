include(bin2h.cmake)
include(JSONParser.cmake)

file(GLOB JSON
    *.json
)

foreach(VAR ${JSON})
    get_filename_component(MYFILE_WITHOUT_EXT ${VAR} NAME_WLE)
    message(${MYFILE_WITHOUT_EXT})
    bin2h(SOURCE_FILE ${VAR} 
        HEADER_FILE ${VAR}.h
        VARIABLE_NAME ${MYFILE_WITHOUT_EXT}_JSN
        NULL_TERMINATE
    )  
    file(READ ${JSON} JSON_DATA)
    sbeParseJson(JSON_DATA_PARSED JSON_DATA)
    message(${JSON_DATA_PARSED.id})
    sbeClearJson(example)
endforeach()


