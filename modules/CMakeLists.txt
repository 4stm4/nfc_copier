aux_source_directory(. DIR_examples_SRCS)

include_directories(../lib/Config)
include_directories(../lib/GUI)
include_directories(../lib/LCD)

add_library(modules ${DIR_examples_SRCS})
target_link_libraries(modules PUBLIC Config LCD)
