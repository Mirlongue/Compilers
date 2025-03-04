# CMake

## 1. Introduction

### 1.1 [User Interaction Guide ](https://cmake.org/cmake/help/latest/guide/user-interaction/index.html#guide:User )

#### 1.1.1 Command Line cmake tool

典型样例

```shell
cd project
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/opt/the/prefix #指定安装路径
cmake --build .
cmake --build . --target install
```

#### 1.1.2 Command line -G option

选择生成器，常用`Ninja` 样例：`cmake .. -G Ninja`

