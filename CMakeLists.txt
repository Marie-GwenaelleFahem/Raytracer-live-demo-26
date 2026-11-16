cmake_minimum_required(VERSION 3.20)
project(raytracer VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable maximum compiler warnings
if(MSVC)
  add_compile_options(/W4 /WX)
else()
  add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# Main executable
add_executable(raytracer src/main.cpp)

# Tests
enable_testing()
add_subdirectory(tests)
