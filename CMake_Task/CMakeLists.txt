cmake_minimum_required(VERSION 3.22)
project(Calc)
set(SRC_FILES main.c Source/Dio.c)
add_executable(Calc ${SRC_FILES})
target_include_directories(Calc INTERFACE Include )
message (STATUS ${SRC_FILES})
add_subdirectory(${CMAKE_HOME_DIRECTORY}/Lib)
target_link_libraries(Calc PUBLIC operation)


