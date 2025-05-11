
cmake_minimum_required(VERSION 3.17)
project(SisRefugio33)

# Establece el estándar de C++ a utilizar
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Soporte para VCPKG
if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "")
endif()

# Recopila todos los archivos fuente dentro del directorio src
file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Define el ejecutable y sus archivos fuente
add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES}
        include/Personaje.h
        src/Enemigos.h
        include/dataStructures/queue.cpp
        include/dataStructures/stack.cpp
)

# Establece el directorio de inclusión para los archivos de cabecera usando target_include_directories
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include")
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include/dataStructures")
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include/characters")

# Copia todos los archivos de la carpeta assets al directorio de ejecución
add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/assets" "$<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/assets"
)

if (ENABLE_TESTS)
    # Si ENABLE_TESTS está habilitado, añade el subdirectorio de pruebas
    message(STATUS "Habilitando pruebas unitarias")

    find_package(GTest CONFIG REQUIRED)
    include(CTest)
    include(GoogleTest)
    
    set(TEST_SRC_DIR "${CMAKE_SOURCE_DIR}/tests")
    set(UNIT_SRC_DIR "${TEST_SRC_DIR}/unit")

    add_executable(unit_tests
        ${UNIT_SRC_DIR}/wrapperVector_test.cpp
    )

    target_include_directories(unit_tests PRIVATE "${CMAKE_SOURCE_DIR}/include")
    target_include_directories(unit_tests PRIVATE "${CMAKE_SOURCE_DIR}/include/dataStructures")
    target_include_directories(unit_tests PRIVATE "${CMAKE_SOURCE_DIR}/include/characters")  

    enable_testing()

    target_link_libraries(unit_tests PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock)
    gtest_discover_tests(unit_tests)
else()
    message(STATUS "Pruebas unitarias deshabilitadas")
endif(ENABLE_TESTS)