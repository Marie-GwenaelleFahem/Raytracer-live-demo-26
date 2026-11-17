include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.7.1
)
FetchContent_MakeAvailable(Catch2)

add_executable(raytracer_tests placeholder_test.cpp vector_test.cpp)
target_link_libraries(raytracer_tests PRIVATE Catch2::Catch2WithMain raytracer_lib)

include(CTest)
include(Catch)
catch_discover_tests(raytracer_tests)
