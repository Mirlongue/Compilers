## Environment

安装 `Clion`

将 `Clion` 中 `CMake` `Ninja` `Mingw` 配置进系统路径

安装 `VS Code`

安装 `LLVM` （通过 `CMAKE_C_COMPILER=clang`  `CMAKE_CXX_COMPILER=clang++` 指定，需要`MSVC`库，安装`Visual Studio` 社区版即可 选择 使用C++的桌面开发）

使用`Visual Studio`的`Developer Command Prompt`可以通过如下命令 查看动态库的依赖项目 `dumpbin /DEPENDENTS xxx.dill` 
常用命令 `dir`  `cd /d your/path/to`

`cmake --build . -v`添加`-v`以查看具体编译指令

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
# output 默认相对路径于 CMAKE_CURRENT_BINARY_DIR
```

`link_directories` 链接库目录
`link_libraries` 链接库  内填完整库文件名`<libxxx.dll>`，库名`<xxx>` 均可

设置目标名称

```cmake
set_target_properties(<target> PROPERTIES OUTPUT_NAME <name>)
```

命令行`-D<xxx>`优先级最高，其次是`CMakeList`中设置的变量，然后是`CACHE`变量

`add_subdirectory` 中 `target`信息会返回

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
set(<MY_LIST> <item1> <item2> <item3>) # 直接定义列表

list(APPEND <MY_LIST> <item>)
list(INSERT <MY_LIST> <index> <item>)
list(REMOVE <MY_LIST> <item>)
list(POP_BACK <MY_LIST>)
list(LENGTH <MY_LIST> <output_var>)
list(GET <MY_LIST> <output_var>)
list(JOIN <MY_LIST> <glue> <output_var>) # 用指定分隔符连接列表元素为字符串
```

`target_compile_definitions`

```shell
target_compile_definitions(<MathFunctions> PRIVATE <USE_MYMATH>) # 编译 MathFunctions 定义USE_MYMATH 配合文件中如下定义部分
# #ifdef USE_MYMATH
# ...
# #endif
```

## Step3

```shell
mkdir build
cd build

cmake ../ -G Ninja
cmake --build .
```

设置接口库传递属性

`add_library(<tutorial_compiler_flags> INTERFACE)`

设置目标的编译特性，如`c`标准等

`target_compile_features(<xxx> INTERFACE cxx_std_11)`

## Step4
```shell
mkdir build
cd build

cmake ../ -G Ninja
cmake --build .
```

`target_compile_options` 是一个用于为特定目标（如可执行文件或库）设置编译选项的命令，可以控制编译器在构建目标时使用的选项，如启用或禁用警告、设置优化级别、定义宏等

生成器表达式，符合其中条件为真

```cmake
"$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>"
```

`$<BUILD_INTERFACE:...>` 是一个生成器表达式，用于在构建接口中包含特定内容，特别适用于设置目标属性，如编译选项、包含目录等，以便这些属性仅在构建目标时应用，而不影响使用该目标的其他项目
`-Wall` 启用大多数警告
`-Wextra`启用额外的警告
`-Wshadow`警告变量遮蔽
`-Wformat=2`更严格的格式字符串检查
`-Wunused` 警告未使用的变量和函数
`-W3` 是 Microsoft Visual C++（MSVC）编译器提供的一个警告级别选项

```cmake
$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>
$<BUILD_INTERFACE:-W3>
```





