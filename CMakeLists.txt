cmake_minimum_required(VERSION 3.16)
project(arrangatan)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

file(GLOB SRC_FILES src/*.cpp)

add_executable(arrangatan ${SRC_FILES})

target_link_libraries(arrangatan
    SFML::Graphics
    SFML::Window
    SFML::System
)

include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB SRC_FILES src/*.cpp)

