cmake_minimum_required(VERSION 3.17)
project(SisRefugio33)

# Establece el estándar de C++ a utilizar
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Recopila todos los archivos fuente dentro del directorio src
file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Define el ejecutable y sus archivos fuente
add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})

# Establece el directorio de inclusión para los archivos de cabecera usando target_include_directories
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include")
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include/dataStructures")

# Mensaje para indicar el inicio de la compilación
message(STATUS "Compilando el proyecto ${CMAKE_PROJECT_NAME}")
