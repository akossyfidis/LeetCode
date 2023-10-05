cmake_minimum_required(VERSION 2.8)
project(LeetCode)


# Export executables to "bin" directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Enable C++11
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
IF(CMAKE_COMPILER_IS_GNUCC)
    SET(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -Wall -std=c17  -pthread -g")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17 -pthread -g")
ENDIF(CMAKE_COMPILER_IS_GNUCC)


add_library(Lib Solution.cpp)
target_include_directories(Lib PUBLIC 
  ${CMAKE_CURRENT_SOURCE_DIR}
  )

  
add_executable(LeetCode main.cpp)
target_link_libraries(LeetCode Lib)

