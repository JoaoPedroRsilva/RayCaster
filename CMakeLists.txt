cmake_minimum_required(VERSION 3.16)
project(RayCaster LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W3)
else()
    add_compile_options(-Wall -Wextra)
endif()

find_package(OpenGL REQUIRED)
find_package(X11 REQUIRED)
find_package(PNG REQUIRED)

add_executable(RayCaster
  source/ray/ray.cpp
  source/game/game.cpp
  source/map/map.cpp
  source/player/player.cpp
)

target_include_directories(RayCaster PRIVATE
  source/ray
  source/game
  source/map
  source/player
)

target_link_libraries(RayCaster PRIVATE
    OpenGL::GL
    ${X11_LIBRARIES}
    PNG::PNG
    pthread
)

target_compile_definitions(RayCaster PRIVATE PROJ_DIR="${CMAKE_SOURCE_DIR}")
