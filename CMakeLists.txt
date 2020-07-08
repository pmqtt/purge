cmake_minimum_required(VERSION 3.16)
project(purge)

set(CMAKE_CXX_STANDARD 20)
include(GNUInstallDirs)
add_compile_options(-fstack-check)
#add_compile_options(-g -fsanitize=address -fno-omit-frame-pointer)

add_link_options(-fsanitize=address -fno-omit-frame-pointer)



add_executable(main main.cpp)