## Init

安装`Clion`，配置其中的`CMake` `Ninja` `Mingw` 到系统路径

 `LLVM`（`CMAKE_C_COMPILER=clang`  `CMAKE_CXX_COMPILER=clang++` ），需要`MSVC`库（安装 `Visual Studio` 社区版本即可 选择 使用C++的桌面开发 组件）

[`CMake_Tutorial`]([Mirlongue/CMake_Tutorial](https://github.com/Mirlongue/CMake_Tutorial))

`cmake -D<variable> = <value>` ，覆盖`CMakeList.txt`中默认值（`option()` ，带`CACHE`的`set()`）

 `cmake --build . -v`   `-v`用于查看具体编译指令

`set(CMAKE_RUNTIME_OUTPUT_DIRECTORY <out_dir>/bin)` 设置运行时目标文件（`.exec` `.dill`）输出位置

`set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY <out_dir>/lib)` 设置存档目标文件（`.lib` `.a`）输出位置

## `option`

`option(<feature> "<describe>" <state>)`

提供一个可配置的选项，默认`OFF`（`ON`/`OFF`）

`option()`定义的变量存储在`CMakeCache.txt`中，其属性为全局，可以在整个项目中访问

## `configure_file`

`configure_file(<input> <output>)`

`@<variable>@` `${<variable>}`会被替换为变量当前值，未定义则被替换为空字符串

`#cmakedefine <variable> [value]` 根据`<variable>` 设置情况被替换为`#define <variable> [value]` 或`/* #undef <variable> */`

`<output>` 默认相对路径于 `CMAKE_CURRENT_BINARY_DIR`

## `link_libraries`

`link_libraries([debug|optimized|general] <item>)`

`debug` 仅在`debug`配置时链接

`optimized`仅在`release`配置时链接

`general`所以配置都链接

## `link_directories`

`link_directories([AFTER|BEFORE] [dir1] [dir2])`

类似编译器中 `-L`选项，告诉链接器在哪些路径下查找库文件

`AFTER`或`BEFORE`，控制目录被添加的顺序，默认`BEFORE`

相对路径基于`CMAKE_CURRENT_SOURCE_DIR`解析

使得`link_libraries()`可以直接通过库名链接库文件

## set_target_properties

`set_target_properties(<target> PROPERTIES <prop> <value>)`

允许自定义属性然后`get_target_property(<value> <target> <prop>)`获取

`set_target_properties`的设置会覆盖`target_*`系列命令

常用目标属性

​	`OUTPUT_NAME`			    		修改生成的文件名

​	`VERSION`						     库的完整版本号

​	`SOVERSION`				   	      库的ABI版本号

​	`LINK_FLAGS`/`LINK_OPTIONS`         	  链接器标志，如`-Wl,--as-needed`

​	`COMPILE_FLAGS`/`COMPILE_OPTONS`	 编译器标志，如`-Wall`

​	`CXX_STANDARD`					   `C++`标志

​	`POSITION_INDEPENDENT_CODE`		是否生成位置无关代码

​	`PREFIX`							修改库文件前缀

​	`SUFIX`						           修改库文件后缀

​	

























