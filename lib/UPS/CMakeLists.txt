aux_source_directory(. DIR_UPS_SRCS)
include_directories(../Config)
add_library(UPS ${DIR_UPS_SRCS})
target_link_libraries(UPS PUBLIC Config)
