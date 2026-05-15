set(srcs src/bcd.c  src/stof.c  src/sun.c src/base64.c src/ftoa.c src/cstring_utils.cc)
set(platform_srcs esp32/itoa.c host/itoa.c esp32/mutex.cc)
include("${CMAKE_CURRENT_LIST_DIR}/../../source_filter.cmake")



if(COMMAND idf_component_register)
idf_component_register(SRCS ${srcs} ${srcs} 
    REQUIRES 
    PRIV_REQUIRES utils_debug
    INCLUDE_DIRS "./include"
)

component_compile_options(${comp_compile_opts})
component_compile_features(${comp_compile_feats})

else()
add_library(utils_misc STATIC ${srcs})
target_include_directories(utils_misc PUBLIC ./include)
target_link_libraries(utils_misc PRIVATE utils_debug)

endif()
