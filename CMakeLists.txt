# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)


# https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD.html
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# expected behaviour
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++lastest")

# gdb
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -pthread")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -pthread")


# 项目信息
project (FHdb)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)
aux_source_directory(test/. DIR_TEST)
aux_source_directory(basic/. DIR_BASIC)
aux_source_directory(skiplist/. DIR_SKIPLIST)

# 添加 math 子目录
# add_subdirectory(basic)
# add_subdirectory(skiplist)

add_subdirectory(log)

# 指定生成目标 
add_executable(FHdb ${DIR_SRCS} ${DIR_TEST} ${DIR_SKIPLIST} ${DIR_BASIC})

target_link_libraries(FHdb LOG)

# 添加链接库
# target_link_libraries(Demo basic)
# target_link_libraries(Demo SKIPLIST)

