cmake_minimum_required (VERSION 2.6)
project (UNIKEY_ENGINE)

# Add the source directory
add_subdirectory (src)

add_executable (unikey_playing test/playing.cpp)
add_executable (unikey_test test/unikey_test.cpp)

include_directories (src)
# Of course, our executable must be linked against the unikey-engine
target_link_libraries (unikey_playing unikey-engine)
target_link_libraries (unikey_test unikey-engine gtest)
