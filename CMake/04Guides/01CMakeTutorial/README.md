## Environment

安装 `Clion`

将 `Clion` 中 `CMake` `Ninja` `Mingw` 配置进系统路径

安装 `VS Code`

安装 `LLVM` （通过 `CMAKE_C_COMPILER=clang`  `CMAKE_CXX_COMPILER=clang++` 指定，需要`MSVC`库，安装`Visual Studio` 社区版即可 选择 使用C++的桌面开发）

使用`Visual Studio`的`Developer Command Prompt`可以通过如下命令 查看动态库的依赖项目 `dumpbin /DEPENDENTS xxx.dill` 
常用命令 `dir`  `cd /d your/path/to`

`cmake --build . -v`添加`-v`以查看具体编译指令

## find_package

用法，以`OpenCV`为例，`find_package(OpenCV REQUIRED)`

`Module`模式	解析`Findxxx.cmake`文件，是默认工作模式

`Config`模式	解析`xxxConfig.cmake`文件或`xxx-config.cmake`文件



### module模式

```cmake
find_package(OpenCV REQUIRED)
foreach(m ${OpenCV_LIBS})
	get_target_property(m_include_dir ${m} INTERFACE_INCLUDE_DIRECTORIES)
	get_target_property(m_location ${m} INTERFACE_LOCATION)
	message(STATUS "OpenCV: ${m}")
	message(STATUS " include dir: ${m_include_dir}")
	message(STATUS " location: ${m_location}")
endforeach()
```

该文件的查找过程只涉及到两个路径    `CMAKE_MODULE_PATH`    `CMAKE_ROOT`

先在`CMAKE_MODULE_PATH`变量对应的路径中查找，若路径为空，则在`Cmake`安装目录（`CMAKE_ROOT`变量）下的`Modules`目录中查找

`cmake --help-module-list`，查看`CMAKE_ROOT`路径下的包

Findxxx.cmake文件的编写

/opt/camera/
{include
    CameraApi.h
    CameraDefine.h
    CameraStatus.h
lib
    libMVSDK.so}



FindCamera.cmake

```cmake
set(camera_root "/opt/camera") # 如上路径所示

find_library(
    Camera_LIB # 返回值
    NAMES libMVSDK.so
    PATHS ${camera_root}/lib
    NO_DEFAULT_PATH #不搜索其他默认路径
)

find_path(
    Camera_INCLUDE_DIR
    NAMES CameraApi.h CameraDefine.h CameraStatus.h
    PATHS ${camera_root}/include
    NO_DEFAULT_PATH #不搜索其他默认路径
)

if(NOT TARGET camera)
    add_library(camera SHARED IMPORTED)
    set_target_properties(camera PROPERTIES
        IMPORTED_LOCATION ${Camera_LIB}
        INTERFACE_INCLUDE_DIRECTORIES ${Camera_INCLUDE_DIR}
    )
endif()

# 校验
find_package_handle_standard_args(
    Camera
    REQUIRED_VARS Camera_LIB Camera_INCLUDE_DIR
)
```

### Config模式

照如下顺序查找`xxxConfig.cmake`

`<PackageName>_DIR` 这个变量默认为空，需要直接指定到`<PackageName>Config.cmake`或`<lower-case-package-name>-config.cmake`文件所在的目录才能找到

`CMAKE_PREFIX_PATH`	`CMAKE_FRAMEWORK_PATH`	`CMAKE_APPBUNDLE_PATH` 这些变量指定的路径将作为查找时的根目录，默认都为空

`PATH`环境变量路径

`CMAKE_SYSTEM_PREFIX_PATH` 等系统变量路径

[编写](xxxConfig.cmake.pdf)

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

双引号可加可不加，字符串中间有空格必须加

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

foreach(item IN LISTS <installable_libs>) # list 打印
  message(${item})
endforeach()
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

`$<...>`表示生成器表达式（Generator Expressions）,在生成构建系统（如Makefile或Ninja文件）时被动态求值，而不是在配置阶段（运行cmake命令时）

条件表达式，如`$<CONFIG:Debug>`，如果当前构建配置是`Debug`，返回`1`，否则返回`0`。如`$<PLATFORM_ID:Windows>`，如果目标平台是`Windows`,返回`1`

目标属性访问，如`$<TARGET_FILE:my_target>`，获取目标文件的完整路径。如`$<TARGET_LINKER_FILE:my_lib>`，获取库目标的链接文件

字符串操作，如`$<JOIN:list,delimiter>`，将列表用分隔符连接。如`$<LOWER_CASE:STRING>`,转换为小写

条件选择，如`$<IF:$<CONFIG:Debug>,DEBUG_FLAG,RELEASE_FLAG>`，根据配置选择值



构建配置相关的动态值等功能

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

## Step5
```shell
mkdir build
cd build

cmake ../ -G Ninja
cmake --build .
cmake --install .

ctest
```

设置安装路径(以防止安装到系统默认路径)

```cmake
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/out)
```
安装命令
```cmake
install(TARGETS ${<installable_libs>} DESTINATION <lib>)
install(FILES <MathFunctions.h> DESTINATION <include>)
```

设置测试

```cmake
enable_testing()
add_test(NAME <Runs> COMMAND <./Tutorial 25>)
```

## Step6
```shell
mkdir build
cd build

cmake ../ -G Ninja
cmake --build .
cmake --install .

ctest
```

导入`.cmake`文件

```cmake
include(xxx.cmake)文件或者 include(<module name>)
```

## Step7

```cmake
mkdir build
cd build

cmake ../ -G Ninja
cmake --build .
cmake --install .

ctest
```

`include()`用于将另一个CMake脚本文件，（通常是`.cmake`文件）加载到当前CMake脚本中。

```cmake
include(<file|module> [OPTIONAL] [RESULT_VARIABLE <var>] [NO_POLICY_SCOPE])
```

`<file|module>` 可以是文件路径(`cmake/xxx.cmake`)或模块名如(`FindPackageHandleStandardArgs`)，如果是模块名，`CMake`会在 `CMAKE_MODULE_PATH`中查找对应的(`Find<module>.cmake`)文件

`OPTIONAL` 如果文件不存在，不报错（静默跳过）

`RESULT_VARIABLE <var>`    将文件是否成功加载的结果(`TRUE`/`FALSE`)存储到变量`<var>`中

`NO_POLICY_SCOPE`    默认情况下会创建一个新的的策略作用域，使用此选项禁止此行为。(`cmake_policy()` 是 `CMake` 中用于管理策略(`Policy`)的核心命令，控制CMake在不同版本间的行为变更，确保项目在不同`CMake`版本下构建时行为一致)



