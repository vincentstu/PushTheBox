cmake_minimum_required(VERSION 3.30)
project(2D_PushTheBox)

include(FetchContent)
FETCHCONTENT_DECLARE(sfml GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG master)
FETCHCONTENT_MAKEAVAILABLE(SFML)

set(CMAKE_CXX_STANDARD 20)

# Include header files
include_directories(include)

# Gather all .cpp files from src
file(GLOB SOURCES "src/*.cpp")

# Create executable
add_executable(2D_PushTheBox ${SOURCES})

# If you're using SFML, link it like this (optional)
target_link_libraries(2D_PushTheBox sfml-graphics)