cmake_minimum_required(VERSION 3.10)

project(MyProject LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Message for debugging
message(STATUS "Include directories: ${CMAKE_INCLUDE_PATH}")

# Define include directories
set(INCLUDE_DIRS
    include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../glad/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../glfw/include/GLFW
)

# Add include directories globally (less preferred for larger projects)
include_directories(${INCLUDE_DIRS})

# Create the executable
file(GLOB_RECURSE SOURCES "*.h" "*.cpp")
add_executable(my_program ${SOURCES})

# Add include directories specifically for my_program
target_include_directories(my_program PRIVATE ${INCLUDE_DIRS})

# Optionally link libraries here if needed
# target_link_libraries(my_program some_library)