## Init

安装`Clion`，配置其中的`CMake` `Ninja` `Mingw` 到系统路径

 `LLVM`（`CMAKE_C_COMPILER=clang`  `CMAKE_CXX_COMPILER=clang++` ），需要`MSVC`库（安装 `Visual Studio` 社区版本即可 选择 使用C++的桌面开发 组件）

[`CMake_Tutorial`]([Mirlongue/CMake_Tutorial](https://github.com/Mirlongue/CMake_Tutorial))

`cmake -D<variable> = <value>` ，覆盖`CMakeList.txt`中默认值（`option()` ，带`CACHE`的`set()`）

 `cmake --build . -v`   `-v`用于查看具体编译指令

`set(CMAKE_RUNTIME_OUTPUT_DIRECTORY <out_dir>/bin)` 设置运行时目标文件（`.exec` `.dill`）输出位置

`set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY <out_dir>/lib)` 设置存档目标文件（`.lib` `.a`）输出位置

## Generator Expression

`$<...>`表示生成器表达式（Generator Expressions）,在生成构建系统（如Makefile或Ninja文件）时被动态求值，而不是在配置阶段（运行cmake命令时）

条件表达式，如`$<CONFIG:Debug>`，如果当前构建配置是`Debug`，返回`1`，否则返回`0`。如`$<PLATFORM_ID:Windows>`，如果目标平台是`Windows`,返回`1`

目标属性访问，如`$<TARGET_FILE:my_target>`，获取目标文件`my_target`的完整路径。如`$<TARGET_LINKER_FILE:my_lib>`，获取库目标`my_lib`的链接文件

字符串操作，如`$<JOIN:list,delimiter>`，将列表用分隔符连接。如`$<LOWER_CASE:STRING>`,转换为小写

条件选择，如`$<IF:$<CONFIG:Debug>,DEBUG_FLAG,RELEASE_FLAG>`，根据配置选择值

生成器表达式，符合其中条件为真 `"$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>"`

`$<BUILD_INTERFACE:...>` 是一个生成器表达式，用于在构建接口中包含特定内容，特别适用于设置目标属性，如编译选项、包含目录等，以便这些属性仅在构建目标时应用，而不影响使用该目标的其他项目
`-Wall` 启用大多数警告
`-Wextra`启用额外的警告
`-Wshadow`警告变量遮蔽
`-Wformat=2`更严格的格式字符串检查
`-Wunused` 警告未使用的变量和函数
`-W3` 是 Microsoft Visual C++（MSVC）编译器提供的一个警告级别选项

## `option`

`option(<feature> "<describe>" <state>)`

提供一个可配置的选项，默认`OFF`（`ON`/`OFF`）

`option()`定义的变量存储在`CMakeCache.txt`中，其属性为全局，可以在整个项目中访问

## `configure_file`

`configure_file(<input> <output>)`

`@<variable>@` `${<variable>}`会被替换为变量当前值，未定义则被替换为空字符串

`#cmakedefine <variable> [<value>]` 根据`<variable>` 设置情况被替换为`#define <variable> [<value>]` 或`/* #undef <variable> */`

`<output>` 默认相对路径于 `CMAKE_CURRENT_BINARY_DIR`

## `link_libraries`

`link_libraries([debug|optimized|general] <item>)`

`debug` 仅在`debug`配置时链接

`optimized`仅在`release`配置时链接

`general`所以配置都链接

## `link_directories`

`link_directories([AFTER|BEFORE] [<dir1>] [<dir2>])`

类似编译器中 `-L`选项，告诉链接器在哪些路径下查找库文件

`AFTER`或`BEFORE`，控制目录被添加的顺序，默认`BEFORE`

相对路径基于`CMAKE_CURRENT_SOURCE_DIR`解析

使得`link_libraries()`可以直接通过库名链接库文件

## set_target_properties

`set_target_properties(<target> PROPERTIES <prop> <value>)`

允许自定义属性然后`get_target_property(<value> <target> <prop>)`获取

`set_target_properties`的设置会覆盖`target_*`系列命令

常用目标属性

​	`OUTPUT_NAME` 修改生成的文件名

​	`VERSION` 库的完整版本号

​	`SOVERSION` 库的ABI版本号

​	`LINK_FLAGS`/`LINK_OPTIONS` 链接器标志，如`-Wl,--as-needed`

​	`COMPILE_FLAGS`/`COMPILE_OPTONS` 编译器标志，如`-Wall`

​	`CXX_STANDARD` `C++`标志

​	`POSITION_INDEPENDENT_CODE` 是否生成位置无关代码

​	`PREFIX` 修改库文件前缀

​	`SUFIX` 修改库文件后缀

## `add_subdirectory`

`add_subdirectory(<source_dir> [<binary_dir>] [EXCLUDE_FROM_ALL])`

`source_dir` 目录路径，相对于当前`CMakeLists.txt`所在目录

`binary_dir` 可选，默认是`source_dir` 目录路径

`EXECLUDE_FROM_ALL` 可选，如果设置，不会默认构建，除非显式依赖或手动指定

子目录中定义的目标，全局可见

## `list`

`set(<my_list> <item1> <item2> <item3>)`

`list(LENGTH <my_list> <len>)`

`list(APPEND <my_list> <item>)`

`list(INSERT <my_list> <item>)`

`list(POP_BACK <my_list>)`

`list(GET <my_list> <index> <out_var>)`

`list(JOIN <my_list> <glue> <out_var>)`

```cmake
foreach(<item> IN LISTS <my_list>)
	message(${item})
endforeach()
```

## `target_compile_definitions`

`target_compile_definitions(<math_function> PRIVATE <USE_MYMATH>)`

配合代码中如下定义使用

```cmake
#ifdef <USE_MYMATH>
...
#endif
```

## `target_compile_features`

`target_compile_features(<demo> PUBLIC|INTERFACE|PRIVATE cxx_std_11)`

设置目标的编译特性，如`c`标志等

