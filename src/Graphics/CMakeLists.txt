include_directories(${PROJECT_SOURCE_DIR})
add_library(Graphics Graphics.cpp Window.cpp GameProgram.cpp Shader.cpp Texture2d.cpp)
target_link_libraries(Graphics fileio)
