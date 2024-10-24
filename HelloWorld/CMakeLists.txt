cmake_minimum_required(VERSION 3.10)

# Set the project name and specify C++ as the language
project(MyProject LANGUAGES CXX)

# Set C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directories
include_directories(include)

# Add the executable
file(GLOB_RECURSE SOURCES "src/include/*.hpp" "src/*.cpp" )
add_executable(MyExecutable ${SOURCES})

find_package(OpenGL REQUIRED)
target_link_libraries(MyExecutable PRIVATE GLFW ${OPENGL_LIBRARIES} glad)


# Define where to find the textures and levels
file(GLOB TEXTURE_FILES textures/*)
file(GLOB LEVEL_FILES levels/*)

# Message for debugging
message(STATUS "Include directories: ${CMAKE_INCLUDE_PATH}")

# Set the texture and level files as custom properties (optional)
set(TEXTURE_FILES ${TEXTURE_FILES} CACHE INTERNAL "Texture files")
set(LEVEL_FILES ${LEVEL_FILES} CACHE INTERNAL "Level files")
