set(libsim_SRC
 simulator.cpp
 object.cpp
 logger.hpp
 simulator.hpp
 object.hpp
  vec2.hpp)
#set(libsim_HEADERS logger.hpp simulator.hpp object.hpp vec2.hpp)

add_library(libsim STATIC
    ${libsim_SRC}
    #${libsim_HEADERS}
)

target_include_directories(libsim PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
