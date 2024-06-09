cmake_minimum_required(VERSION 3.0)
project(RedeSocial)

# Add your source files here
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/RedeSocial/*.cpp")

# Set the C++ standard to use
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Generate the executable
add_executable(MyExecutable ${SOURCES})