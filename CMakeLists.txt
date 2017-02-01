cmake_minimum_required(VERSION 3.2)
project (wnjson11)

add_definitions(-std=c++11)
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
  /usr/local/lib/libglog.a
  /usr/local/lib/libgflags.a
)

