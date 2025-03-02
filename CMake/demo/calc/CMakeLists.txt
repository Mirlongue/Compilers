
message(${PROJECT_SOURCE_DIR})
message(${CMAKE_SOURCE_DIR})
message(${CMAKE_CURRENT_SOURCE_DIR})

message(${PROJECT_BINARY_DIR})
message(${CMAKE_BINARY_DIR})
message(${CMAKE_CURRENT_BINARY_DIR})




add_library(addition STATIC addition.cpp)
install(TARGETS addition DESTINATION lib)
install(FILES addition.h DESTINATION include)

add_library(subtract SHARED subtract.cpp)
install(TARGETS subtract DESTINATION bin)
install(FILES subtract.h DESTINATION include)