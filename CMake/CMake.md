# CMake

## 1. Introduction

### 1.1 [User Interaction Guide]([User Interaction Guide — CMake 4.0.0-rc2 Documentation](https://cmake.org/cmake/help/latest/guide/user-interaction/index.html#guide:User Interaction Guide))

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

