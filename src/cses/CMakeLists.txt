set(LIBRARY_NAME cses)
set(LIBRARY_SOURCES
        weird_algorithm.cpp
        missing_number.cpp
        repetitions.cpp
        increasing_array.cpp
        permutations.cpp
        number_spiral.cpp
        two_knights.cpp
        two_sets.cpp
        bit_strings.cpp
        trailing_zeros.cpp
        coin_piles.cpp
        palindrome_reorder.cpp)

set(LIBRARY_HEADERS cses.h)

set(LIBRARY_INCLUDES "./" "${CMAKE_BINARY_DIR}/configured_files/include")

add_library(${LIBRARY_NAME} STATIC
        ${LIBRARY_SOURCES}
        ${LIBRARY_HEADER})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_INCLUDES})

if (ENABLE_WARNINGS)
    target_set_warnings(
            ${LIBRARY_NAME}
            ${ENABLE_WARNINGS}
            ${ENABLE_WARNINGS_AS_ERRORS})
endif ()
