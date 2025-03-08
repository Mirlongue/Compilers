cmake_minimum_required(VERSION 3.29)
project(demo VERSION 1.0)

message(${PROJECT_SOURCE_DIR})
message(${CMAKE_SOURCE_DIR})
message(${CMAKE_CURRENT_SOURCE_DIR})

message(${PROJECT_BINARY_DIR})
message(${CMAKE_BINARY_DIR})
message(${CMAKE_CURRENT_BINARY_DIR})

message(${PROJECT_NAME})
message(${CMAKE_PROJECT_NAME})


#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#message(${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
#message(${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})




option(DATE_ENABLE "output date" ON)
if(DATE_ENABLE)
    set(DATE "\"2025/01/19\"")
    message(${DATE})
endif()


configure_file(config.h.in config.h )


set(CMAKE_CXX_STANDARD 20)

add_subdirectory(calc)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
                            ${PROJECT_BINARY_DIR}
                            ${PROJECT_SOURCE_DIR}/calc
                            ${PROJECT_SOURCE_DIR}/otherLib)
target_link_libraries(${PROJECT_NAME}   addition
                                        subtract
                                        ${PROJECT_SOURCE_DIR}/otherLib/libmultiply.a
                                        ${PROJECT_SOURCE_DIR}/otherLib/libdivition.dll)

set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/out")
message(${CMAKE_INSTALL_PREFIX})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)


#install(EXPORT tmp NAMESPACE me DESTINATION lib/tmp)

#install(FILES ${PROJECT_SOURCE_DIR}/otherLib/libdivition.dll DESTINATION bin)
#install(FILES ${PROJECT_SOURCE_DIR}/otherLib/divition.h DESTINATION include)
#
#install(FILES ${PROJECT_SOURCE_DIR}/otherLib/libmultiply.a DESTINATION lib)
#install(FILES ${PROJECT_SOURCE_DIR}/otherLib/multiply.h DESTINATION include)

install(FILES ${PROJECT_BINARY_DIR}/config.h DESTINATION include)
