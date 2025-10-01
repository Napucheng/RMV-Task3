cmake_minimum_required(VERSION 3.10)
project(ProjectileTracking)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找依赖包
find_package(OpenCV REQUIRED)
find_package(Ceres REQUIRED)

# 打印找到的包信息
message(STATUS "OpenCV version: ${OpenCV_VERSION}")
message(STATUS "OpenCV libraries: ${OpenCV_LIBS}")
message(STATUS "Ceres libraries: ${CERES_LIBRARIES}")

# 包含目录
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CERES_INCLUDE_DIRS})

# 创建可执行文件
add_executable(projectile_tracking main.cpp)

# 链接库
target_link_libraries(projectile_tracking 
    ${OpenCV_LIBS} 
    ${CERES_LIBRARIES}
)

# 设置编译器选项
target_compile_options(projectile_tracking PRIVATE -O2 -Wall)