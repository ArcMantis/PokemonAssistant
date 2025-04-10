cmake_minimum_required(VERSION 3.5)

project(PokemonAssistant LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)




# 让 CMake 去查找系统中安装的 glog 库，如果找不到，由于指定了 REQUIRED，CMake 会抛出一个致命错误。
find_package(glog REQUIRED)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)


add_executable(PokemonAssistant PokemonAssistant.cpp)

# 先指定搜索路径
target_include_directories(PokemonAssistant
    PRIVATE
       ${CMAKE_CURRENT_LIST_DIR}/include  # 这里添加了 include 文件夹中的头文件目录
       ${CMAKE_CURRENT_LIST_DIR}/src
)

# 链接外部库和内部库到可执行目标
target_link_libraries(PokemonAssistant
    PRIVATE
        glog        #外部库，系统库
        PokemonRom    #自己的库
)

# 查找src目录下所有的.cpp文件，生成动态库
file(GLOB SRC_FILES "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

# 生成每个.cpp文件对应的动态库
foreach(SRC_FILE ${SRC_FILES})
    # 获取文件名（不带扩展名）
    get_filename_component(LIB_NAME ${SRC_FILE} NAME_WE)
    message(STATUS "Generating shared library: ${LIB_NAME}")

    #message(STATUS "Generating Cfile library: ${SRC_FILE}")
    # 创建动态库
    add_library(${LIB_NAME} SHARED ${SRC_FILE})

    # 设置每个动态库的输出目录
    set_target_properties(${LIB_NAME} PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
    )

    # 添加头文件目录（如果需要，可以进一步指定头文件目录）
    target_include_directories(${LIB_NAME}
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src
        ${CMAKE_CURRENT_LIST_DIR}/include
    )

    # 链接外部库（如需要的话，也可以链接到其它依赖）
    target_link_libraries(${LIB_NAME} PRIVATE glog)
endforeach()

