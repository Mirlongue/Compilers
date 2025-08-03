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

## configure_file































