cmake_minimum_required(VERSION 3.0)

set( PROJECT_NAME matrix )
set( PROJECT_LANGUAGES CXX )
project( ${PROJECT_NAME} ${PROJECT_LANGUAGES} )

set( SOURCES
  matrix.hpp
  main.cpp
)

set(HEADERS
  #include/matrix.h
)

add_executable( ${PROJECT_NAME} ${SOURCES} ${HEADERS} )

set_target_properties(${PROJECT_NAME} PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)

target_include_directories( ${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR})

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall -Wextra -pedantic -Werror)
endif()

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
