cmake_minimum_required(VERSION 3.16)
project(llm_eval_examples CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(CURL REQUIRED)

add_executable(basic_eval examples/basic_eval.cpp)
target_include_directories(basic_eval PRIVATE include)
target_link_libraries(basic_eval CURL::libcurl)
