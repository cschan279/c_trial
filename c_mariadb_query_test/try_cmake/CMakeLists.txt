cmake_minimum_required(VERSION 3.10)

# set the project name
project(Version)

#include_directories(/lib/x86_64-linux-gnu/)
#sudo apt install libmariadb-dev

# add the executable
add_executable(Version version.c)
target_link_libraries(${PROJECT_NAME} mariadb)






