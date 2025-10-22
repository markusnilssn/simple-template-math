# Tests for Application

add_executable(${PROJECT_NAME}_tests test_main.cpp)

# Link the static library
target_link_libraries(${PROJECT_NAME}_tests PRIVATE ${PROJECT_NAME})

# Make sure it can include Application headers
target_include_directories(${PROJECT_NAME}_tests PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

# Optional: register the test with CTest
add_test(NAME ${PROJECT_NAME}_run_tests COMMAND ${PROJECT_NAME}_tests)
