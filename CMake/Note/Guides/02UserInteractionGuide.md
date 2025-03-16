

# 1 [User Interaction Guide ](https://cmake.org/cmake/help/latest/guide/user-interaction/index.html#guide:User )

## 1.1 Command Line cmake tool

典型样例

```shell
cd project
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/opt/the/prefix #指定安装路径
cmake --build .
cmake --build . --target install
```

## 1.2 Command line -G option

选择生成器，常用`Ninja` 样例：`cmake .. -G Ninja`

## 1.3 Setting Build Variables

`CMAKE_PREFIX_PATH`	指示库文件，头文件目录，不同目录`;`分隔

`CMAKE_MODULE_PATH`	当CMake执行include()或find_package()命令时，会在这些指定目录中查找相应的.cmake

`CMAKE_BUILD_TYPE`	构建配置（Debug/Release），确定优化程度，与单配置构建系统（Makefile/Ninja）相关，多配置构建系统（Visual Studio/Xcode）会忽略此设置

`CMAKE_INSTALL_PREFIX`	安装构建目标的位置

`CMAKE_TOOLCHAIN_FILE`	包含交叉编译数据如toolchains和sysroots

`BUILD_SHARED_LIBS`	当add_library()未设置类型时为其决定是否使用动态库

`CMAKE_EXPORT_COMPILE_COMMANDS`	生成compile_commands.json供IDE使用如跳转代码等

`CMAKE_EXPORT_BUILD_DATABASE`	生成数据更全面的build_database.json供IDE使用分析

有前缀`CMAKE_`的变量通常指CMake本身提供的选项

## 1.4 Setting variables on the command line

命令行设置变量值样例(-Dxxx)

```shell
cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Debug
```

允许使用-C选项指定用于填充初始缓存的文件

## 1.5 Using presets on the command-line

源文件夹包含`CMakePresents.json`文件，如下形式

```shell
{
  "version": 1,
  "configurePresets": [
    {
      "name": "ninja-release",
      "binaryDir": "${sourceDir}/build/${presetName}",
      "generator": "Ninja",
      "cacheVariables": {
        "CMAKE_BUILD_TYPE": "Release"
      }
    }
  ]
}
```

执行如下

```shell
cmake -S /path/to/source --preset=ninja-release
```

可以通过`cmake -S /path/to/source --list-presets`列出可选的`presets`

