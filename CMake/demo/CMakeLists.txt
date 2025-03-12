cmake_minimum_required(VERSION 3.29)
project(demo VERSION 1.0)   # 1

message("in ./")

# 设置安装路径
#set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/calc)   # 0
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/out)     # 1
message(${CMAKE_INSTALL_PREFIX})

message(${PROJECT_NAME})
message(${CMAKE_PROJECT_NAME})

message(${PROJECT_SOURCE_DIR})
message(${CMAKE_SOURCE_DIR})
message(${CMAKE_CURRENT_SOURCE_DIR})

message(${PROJECT_BINARY_DIR})
message(${CMAKE_BINARY_DIR})
message(${CMAKE_CURRENT_BINARY_DIR})

# 设置动态库 静态库 运行时目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
message(${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
message(${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})



# 设置编译器标准
set(CMAKE_CXX_STANDARD 20)

# 子目录
#add_subdirectory(calc)  # 0

# 1
add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
                           ${PROJECT_SOURCE_DIR}/calc/include)

target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/calc/bin/libsubtract.dll
                                      ${PROJECT_SOURCE_DIR}/calc/lib/libaddition.a)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)

message("out ./")
