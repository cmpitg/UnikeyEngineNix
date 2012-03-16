cmake_minimum_required (VERSION 2.6)

# Add the source directory
add_subdirectory (src)

# Add executable file for testing
add_executable (tim_playing src/tim_playing.cpp)

# Of course, our executable must be linked against the unikey-engine
target_link_libraries (tim_playing unikey-engine)
