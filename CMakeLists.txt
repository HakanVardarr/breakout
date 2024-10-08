cmake_minimum_required(VERSION 3.29)
project(breakout)

set(CMAKE_C_FLAGS "-Wall -Wextra")

if (APPLE) 
    set(CMAKE_EXE_LINKER_FLAGS "-framework Cocoa -framework OpenGL -framework IOKit -framework QuartzCore")
endif()


link_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*.c)

add_executable(${PROJECT_NAME} breakout.c ${SOURCES})
target_link_libraries(${PROJECT_NAME} glfw3)