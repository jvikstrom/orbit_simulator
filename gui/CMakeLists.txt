set(libgui_SRC
window.hpp
window.cpp
simulation_display.hpp
simulation_display.cpp
shape.hpp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_library(libgui STATIC
    ${libgui_SRC}
    #${libsim_HEADERS}
)
target_link_libraries(libgui ${SDL2_LIBRARY} libsim)

target_include_directories(libgui PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}

)
