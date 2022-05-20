

set(TEST_SOURCES test_file.cpp ${PROJECT_SOURCE_DIR}/File.h)

add_executable(
        test_file
        ${TEST_SOURCES}
)

target_include_directories(test_file PRIVATE ${PROJECT_SOURCE_DIR} )

target_link_libraries(
        test_file
        gtest_main
        gtest
        pthread
)

include(GoogleTest)
gtest_discover_tests(test_file)