# Tests for Application

add_executable(${PROJECT_NAME}_tests test_main.cpp)

target_link_libraries(${PROJECT_NAME}_tests PRIVATE ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}_tests PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

add_test(NAME ${PROJECT_NAME}_run_tests COMMAND ${PROJECT_NAME}_tests)
