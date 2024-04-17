set(srcs src/periodic.c)

if(${PLATFORM_HOST})
  list(APPEND srcs host/ut_run_time.cc)
endif()

idf_component_register(SRCS ${srcs} 
    INCLUDE_DIRS "./include"
    REQUIRES  esp_timer
    PRIV_REQUIRES  utils_misc
)
component_compile_options(${comp_compile_opts})
component_compile_features(${comp_compile_feats})
