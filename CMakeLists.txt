# v3.14 required for FetchContent_MakeAvailable
cmake_minimum_required(VERSION 3.14)
  # Project information
  project(Types
    VERSION 0.4.0
    DESCRIPTION "BFS data types library"
    LANGUAGES CXX
  )
  # Add the library target
  add_library(types INTERFACE)

  # Setup include directories 
  target_include_directories(types INTERFACE src/)
