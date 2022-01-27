cmake_minimum_required(VERSION 3.10)

# set the project name
project(Trial)

set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)

# add the executable
add_executable(Trial dencrypt.c trial.c)
target_link_libraries(${PROJECT_NAME} OpenSSL::Crypto)
