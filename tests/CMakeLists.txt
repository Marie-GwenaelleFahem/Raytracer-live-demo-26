include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.7.1
)
FetchContent_MakeAvailable(Catch2)

add_executable(raytracer_tests
    placeholder_test.cpp
    test_helpers.cpp
    math/vector/vector_test.cpp
    colour/test_colour.cpp
    geometry/test_ray.cpp
    geometry/test_sphere.cpp
    render/test_camera.cpp
    render/test_trace.cpp
)
target_include_directories(raytracer_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(raytracer_tests PRIVATE Catch2::Catch2WithMain raytracer_lib)

include(CTest)
include(Catch)
catch_discover_tests(raytracer_tests)
