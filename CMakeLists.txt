cmake_minimum_required (VERSION 3.18.4)

project(Space_game VERSION 1.0.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#set( SDL_STATIC ON CACHE BOOL "" FORCE )
#set( SDL_SHARED OFF CACHE BOOL "" FORCE )

#add_subdirectory(Dependencies)

find_package(SDL2 REQUIRED)

FILE(GLOB SRCFILES ./src/*.cpp ./src/ecs/*.cpp)
FILE(GLOB HEADFILES ./src/*.hpp ./src/ecs/*.hpp)

FILE(GLOB TESTSRCFILES ./test/*.cpp)
FILE(GLOB TESTHEADFILES ./test/*.hpp)


add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>")
add_executable(Space_game ./src/main/Main.cpp ${SRCFILES} ${HEADFILES})
target_include_directories(Space_game PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(Space_game PUBLIC ${SDL2_LIBRARIES})


add_executable(Space_game_test ${TESTSRCFILES} ${TESTHEADFILES} ${SRCFILES} ${HEADFILES})
#target_include_directories(Space_game_tests PUBLIC ${SDL2_INCLUDE_DIRS})
#target_link_libraries(Space_game_tests PUBLIC ${SDL2_LIBRARIES})

