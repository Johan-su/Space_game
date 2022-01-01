cmake_minimum_required (VERSION 3.18.4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ") ## add -v for verbose output
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ")

project(Space_game VERSION 1.0.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

## if (MSVC)
## # warning level 4 and all warnings as errors
## add_compile_options(/W4 /WX)
## else()
##     # lots of warnings
##     add_compile_options(-Wall -Wextra -pedantic)
## endif()

if(WIN32)
endif()

if(UNIX AND NOT APPLE)
endif()

find_package(SDL2 REQUIRED)


FILE(GLOB SRCFILES ./src/*.cpp ./src/ecs/*.cpp ./src/ecs/systems/*.cpp)
FILE(GLOB HEADFILES ./src/*.hpp ./src/ecs/*.hpp ./src/ecs/systems/*.hpp)

FILE(GLOB TESTSRCFILES ./test/*.cpp)
FILE(GLOB TESTHEADFILES ./test/*.hpp)


add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>")
add_executable(Space_game ./src/main/Main.cpp ${SRCFILES} ${HEADFILES})
target_include_directories(Space_game PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(Space_game PUBLIC ${SDL2_LIBRARIES})


add_executable(Space_game_test ${TESTSRCFILES} ${TESTHEADFILES} ${SRCFILES} ${HEADFILES})
#target_include_directories(Space_game_tests PUBLIC ${SDL2_INCLUDE_DIRS})
#target_link_libraries(Space_game_tests PUBLIC ${SDL2_LIBRARIES})