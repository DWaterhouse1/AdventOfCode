cmake_minimum_required(VERSION 3.20.2)
project(CodeAdvent)

add_executable (
  CodeAdvent
  CodeAdvent.cpp
  CodeAdvent.h
  Helpers/DataReader.h
  Day1.h)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CodeAdvent PROPERTY CXX_STANDARD 20)
endif()

add_custom_target(copy_resources ALL
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${PROJECT_SOURCE_DIR}/Resources
  ${PROJECT_BINARY_DIR}/Resources
  COMMENT "Copying resources into binary directory")

add_dependencies(CodeAdvent
  copy_resources)

# TODO: Add tests and install targets if needed.
