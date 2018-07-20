cmake_minimum_required(VERSION 2.8)

# Project
project(nimu-matrix-test)

#--------------------------------------------------------------------------------------------------
# Test files
set(nimu_matrix_test_SOURCES
  matrix_static.cpp
)

#--------------------------------------------------------------------------------------------------
# Setup testing
enable_testing()
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

# Test executable
add_executable(nimu-matrix-test ${nimu_matrix_test_SOURCES})
target_link_libraries(nimu-matrix-test Boost::unit_test_framework)
target_include_directories(nimu-matrix-test PUBLIC ../include)
target_compile_definitions(nimu-matrix-test PRIVATE BOOST_TEST_DYN_LINK)

# Test directive 
add_test(NAME nimu-matrix-test-ann-static COMMAND nimu-matrix-test-ann-static)

#--------------------------------------------------------------------------------------------------
# Install
install(TARGETS nimu-matrix-test DESTINATION bin)