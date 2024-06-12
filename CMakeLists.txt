cmake_minimum_required(VERSION 3.15)
project(purge)

set(CMAKE_CXX_STANDARD 20)
include(GNUInstallDirs)
#add_compile_options(-fstack-check)
#add_link_options(-fsanitize=address -fno-omit-frame-pointer)

add_library(purge INTERFACE)
target_include_directories(purge INTERFACE include)

install(
        DIRECTORY
        "include/"
        DESTINATION
        "${CMAKE_INSTALL_INCLUDEDIR}/purge"
)
add_executable(main main.cpp)
