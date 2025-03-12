message("in ./calc/")

project(calc VERSION 2.2)
message(${PROJECT_NAME})

# option样例
option(DATE_ENABLE "output date" ON)
if(DATE_ENABLE)
    set(DATE \"2025/01/19\")
    message(${DATE})
endif()

# configure_file样例
configure_file(config.h.in ${PROJECT_BINARY_DIR}/include/config.h)
install(FILES ${PROJECT_BINARY_DIR}/include/config.h DESTINATION include)

message(${PROJECT_SOURCE_DIR})
message(${CMAKE_SOURCE_DIR})
message(${CMAKE_CURRENT_SOURCE_DIR})

message(${PROJECT_BINARY_DIR})
message(${CMAKE_BINARY_DIR})
message(${CMAKE_CURRENT_BINARY_DIR})

# 静态库
add_library(addition STATIC addition.cpp)
install(TARGETS addition DESTINATION lib)
install(FILES addition.h DESTINATION include)

# 动态库
add_library(subtract SHARED subtract.cpp)
install(TARGETS subtract DESTINATION bin)
install(FILES subtract.h DESTINATION include)

message("out ./calc/")