## Environment

安装 `Clion`

将 `Clion` 中 `CMake` `Ninja` `Mingw` 配置进系统路径

安装 `VS Code`

安装 `LLVM` （可选， 通过 `CMAKE_C_COMPILER=clang`  `CMAKE_CXX_COMPILER=clang++` 指定）

## MyDemo

```shell
mkdir build
cd build

cmake ../ -G Ninja -DPRE_BUILD=ON
cmake --build .
cmake --install .

cmake ../ -G Ninja
cmake --build .
cmake --install .
```

引号可加可不加，字符串中间有空格必须加

设置输出文件位置

```shell
# 设置运行时目标文件（exec dll）的输出位置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# 设置存档目标文件（lib a）的输出位置
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
```

`option` 中默认`OFF`

`configure_file`

```shell
configure_file(<input> <output>)
# 输入文件中形如 @VAR@ ${VAR}的字符串会被替换为这些变量当前值，未定义则被替换为空字符串
# #cmakedefine VAR ... 会被替换为以下两行之一，取决于VAR是否被设置
# #define VAR ...
# /* #undef VAR */
```

`link_directories` 链接库目录 `link_libraries` 链接库

## Step1

```shell
mkdir build
cd build

cmake ../ -G Ninja
cmake --build .
```

## Step2

```shell
mkdir build
cd build

cmake ../ -G Ninja
cmake --build .
```

`list`

```shell
set(MY_LIST item1 item2 item3) # 直接定义列表

list(APPEND MY_LIST item)
list(INSERT MY_LIST index item)
list(REMOVE MY_LIST item)
list(POP_BACK MY_LIST)
list(LENGTH MY_LIST output_var)
list(GET MY_LIST output_var)
list(JOIN MY_LIST glue output_var) # 用指定分隔符连接列表元素为字符串
```

`target_compile_definitions`

```shell
target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH") # 编译 MathFunctions 定义 USE_MYMATH 配合文件中如下定义部分
# #ifdef USE_MYMATH
# ...
# #endif

```

## Step3

<<<<<<< HEAD
```shell
mkdir build
cd build

cmake ../ -G Ninja
cmake --build .
```
=======

>>>>>>> 24cc72ab82105fbadf1d285fa291beabe006791f







