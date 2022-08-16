cmake_minimum_required (VERSION 3.16.3)



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D _CRT_SECURE_NO_WARNINGS" ) ## add -v for verbose output
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D _CRT_SECURE_NO_WARNINGS")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D _DEBUG ")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D _DEBUG ")

project(Space_game VERSION 1.0.0) ### PROJECT

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # using Clang

    
    
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}     -std=c++20 -Wall -Wpedantic -g -Wno-language-extension-token -Wno-missing-braces")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall -Wpedantic -g -Wno-language-extension-token -Wno-missing-braces")
    
    #set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address")
    #set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fsanitize=address")
    
    
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # using GCC

    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}     -std=c++20 -Wall -Wpedantic -g -Wno-language-extension-token -Wno-missing-braces")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall -Wpedantic -g -Wno-language-extension-token -Wno-missing-braces")


elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    # using Intel C++
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # using Visual Studio C++
    
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++20  /Z7 /EHsc /W4 " ) ## add -v for verbose output
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /std:c++20  /Z7 /EHsc /W4 ") 

    #set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ")
    #set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ")

    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /MTd /analyze /fsanitize=address")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd /analyze /fsanitize=address")
endif()



if(WIN32)
endif()

if(UNIX AND NOT APPLE)



        #set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}           -fsanitize=address")
        #set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}       -fsanitize=address")
        #set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fsanitize=address")

endif()


find_package(OpenGL REQUIRED)
include_directories(./lib/khronos)


add_subdirectory(./lib/GLFW) # https://www.glfw.org/docs/3.0/build.html
include_directories(./lib/GLFW/include)



FILE(GLOB_RECURSE ENGINESRCFILES ./src/files/*.cpp )
FILE(GLOB_RECURSE ENGINEHEADFILES ./src/files/*.hpp)

FILE(GLOB_RECURSE GAMESRCFILES ./src/Game/*.cpp )
FILE(GLOB_RECURSE GAMEHEADFILES ./src/Game/*.hpp)



add_executable(Space_game ${ENGINESRCFILES} ${ENGINEHEADFILES} ${GAMESRCFILES} ${GAMEHEADFILES})

target_link_libraries(Space_game glfw ${GLFW_LIBRARIES})
target_link_libraries(Space_game opengl32)

