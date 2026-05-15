set(srcs src/dbg.cc)
set(platform_srcs "")
include("${CMAKE_CURRENT_LIST_DIR}/../../source_filter.cmake" OPTIONAL)

if(COMMAND idf_component_register)
idf_component_register(
    SRCS ${srcs} 
    INCLUDE_DIRS "./include"
)

 
target_compile_options(${COMPONENT_LIB} PRIVATE "SHELL:-include sdkconfig.h")
else()

add_library(utils_debug STATIC ${srcs})
target_include_directories(utils_debug PUBLIC ./include)

endif()
