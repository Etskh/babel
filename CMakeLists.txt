cmake_minimum_required (VERSION 2.6)

project (Babel)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
	if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()
endif()

#FIND_LIBRARY(AWESOMIUM_LIBRARY awesomium-1-7 )
FIND_LIBRARY(AWESOMIUM_LIBRARY Awesomium )
FIND_LIBRARY(SDL2_LIBRARY SDL2)
SET(EXTRA_LIBS ${AWESOMIUM_LIBRARY} ${SDL2})

#set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(extern)
include_directories(src)

file(GLOB_RECURSE SOURCES "src/**.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")

add_subdirectory(extern/duktape-1.3.1)

target_link_libraries(${PROJECT_NAME} duktape)
target_link_libraries(${PROJECT_NAME} ${AWESOMIUM_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
