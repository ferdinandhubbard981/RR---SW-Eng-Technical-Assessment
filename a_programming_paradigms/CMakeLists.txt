cmake_minimum_required(VERSION 3.10)

project(programming_paradigms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# GTEST BEGIN

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  base_tests
  tests/base_tests.cpp
)
target_link_libraries(
  base_tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(base_tests)

# GTEST END


add_executable(${PROJECT_NAME}
    "src/main.cpp"
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        "include"
)

target_compile_options(${PROJECT_NAME} PRIVATE
  -Wall
  -Wextra
  -Wshadow
  -Wnon-virtual-dtor
  -Wcast-align -Wunused
  -Woverloaded-virtual
  -Wconversion
  -Wsign-conversion
  -Wduplicated-cond
  -Wnull-dereference
  -Wuseless-cast
  -Wdouble-promotion
  -Wformat=2
  -pedantic)
