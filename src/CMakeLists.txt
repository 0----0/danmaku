cmake_minimum_required (VERSION 2.6)
project (danmaku)

add_executable (danmaku main.cpp Game.cpp BulletArray.cpp)

add_subdirectory (fileio)
add_subdirectory (Graphics)
target_link_libraries (danmaku fileio Graphics)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
find_package(GLEW REQUIRED)
target_link_libraries(danmaku ${GLFW_STATIC_LIBRARIES} ${GLEW_LIBRARIES})
