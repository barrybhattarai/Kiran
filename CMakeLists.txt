cmake_minimum_required(VERSION 3.21)
project(Sage VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)

add_executable(Sage main.cpp glad.c)
target_link_directories(Sage PUBLIC lib)
target_include_directories(Sage PUBLIC include)
target_link_libraries(Sage glfw3)
configure_file(config.h.in ${PROJECT_SOURCE_DIR}/include/config.h)
set(resources vertex_shader.glsl fragment_shader.glsl)

foreach(item IN LISTS resources)
    add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/${item}
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_CURRENT_SOURCE_DIR}/shaders/${item}
            ${CMAKE_BINARY_DIR}
            DEPENDS shaders/${item}
            )
endforeach()
add_custom_target(copyConfig ALL DEPENDS ${resources} )
add_dependencies(Sage copyConfig)


