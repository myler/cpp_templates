cmake_minimum_required(VERSION 3.4)

project(example)

enable_testing()

file(GLOB chapters ${CMAKE_CURRENT_SOURCE_DIR}/chapter*)

foreach(chapter ${chapters})
  add_subdirectory(${chapter})
endforeach()

