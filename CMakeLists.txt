cmake_minimum_required(VERSION 3.27)

project(cses VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_TESTING "Enable a Unit Testing Build" ON)
option(ENABLE_WARNINGS "Enable to add warnings to a target." ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable to treat warnings as errors." ON)
option(ENABLE_SANITIZE_ADDR "Enable to detect memory errors." ON)
option(ENABLE_SANITIZE_UNDEF "Enable to detect/trace undefined behavior errors." ON)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(AddGitSubmodule)
include(FetchContent)

if (ENABLE_WARNINGS)
    include(Warnings)
endif ()

if (ENABLE_SANITIZE_ADDR OR ENABLE_SANITIZE_UNDEF)
    include(Sanitizers)
    add_sanitizer_flags()
endif ()

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG v1.14.x
        GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(src)
add_subdirectory(targets)
add_subdirectory(tests)
