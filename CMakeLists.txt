cmake_minimum_required(VERSION 3.2)
project (wnjson11)

add_definitions(-std=c++14)
add_definitions(-Wall)

set(SOURCES
    main.cpp
    json11.cpp
)

set(HEADERS
    json11.hpp
)

add_executable(
  wnjson
  ${SOURCES}
  ${HEADERS}
)

target_include_directories(
  wnjson SYSTEM
  PUBLIC /usr/local/include
)

target_link_libraries(
  wnjson
  -lglog
  -lgflags
)

