cmake_minimum_required(VERSION 3.1)

project(PasswordCracker)
set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/built")


if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(SFML_STATIC_LIBRARIES FALSE)
    set(SFML_DIR "${PROJECT_SOURCE_DIR}/libs/SFML_${CMAKE_SYSTEM_NAME}/lib/cmake/SFML")
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(SFML_STATIC_LIBRARIES FALSE)
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_DIR "${PROJECT_SOURCE_DIR}/libs/SFML/lib/cmake/SFML")
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()


file(GLOB SOURCE_FILES
        "src/*.cpp"
        "src/App Engine/*.cpp"
        "src/App Engine/User Input Module/*.cpp"
        "src/App Custom Objects/*.cpp"
        "src/App States/*.cpp"
        "src/App States/Diagram State/*.cpp")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

include_directories("src")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}_${CMAKE_SYSTEM_NAME}_${CMAKE_BUILD_TYPE}")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio tmxlite)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio tmxlite)
endif()
