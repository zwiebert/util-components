set(srcs src/periodic.c)
set(platform_srcs host/ut_run_time.cc)
include("${CMAKE_CURRENT_LIST_DIR}/../../source_filter.cmake")

idf_component_register(SRCS ${srcs} 
    INCLUDE_DIRS "./include"
    REQUIRES  esp_timer
    PRIV_REQUIRES  utils_misc
)
 
target_compile_options(${COMPONENT_LIB} PRIVATE "SHELL:-include sdkconfig.h")
