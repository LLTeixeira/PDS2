cmake_minimum_required(VERSION 3.0)
project(RedeSocial)

# Add your source files here
set(SOURCES
  ${PROJECT_SOURCE_DIR}/RedeSocial/RedeSocial.cpp
)

# Add any additional include directories here
include_directories(
    include
)

# Add any additional library directories here
link_directories(
    lib
)

# Set the C++ standard to use
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Generate the executable
add_executable(MyExecutable ${SOURCES})

# Link the required libraries
target_link_libraries(MyExecutable
    iostream
    string
    map
)