cmake_minimum_required(VERSION 3.29)
project(demo VERSION 1.0)


option(PRE_BUILD "pre build" OFF)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/out)


# 设置动态库 静态库 运行时目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
message(${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
message(${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})



# 设置编译器标准
set(CMAKE_CXX_STANDARD 20)

if(PRE_BUILD)
    add_subdirectory(calc)
else()

    add_executable(${PROJECT_NAME} main.cpp) 

    target_include_directories(${PROJECT_NAME} PUBLIC
                           ${PROJECT_SOURCE_DIR}/out/include)

    target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/out/bin/libsubtract.dll
                                      ${PROJECT_SOURCE_DIR}/out/lib/libaddition.a)

    install(TARGETS ${PROJECT_NAME} DESTINATION bin)

endif()


