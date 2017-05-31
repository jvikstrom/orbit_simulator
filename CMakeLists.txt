cmake_minimum_required(VERSION 3.5)
project(crawler)

set(CMAKE_CXX_STANDARD 11)

if(MSVC)
  # Force to always compile with W4
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  # Update if necessary
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif()

#set(BOOST_ROOT /opt/boost)
#set(Boost_USE_STATIC_LIBS ON)
#find_package(Boost COMPONENTS system)
#find_package (Threads)

# Download and unpack googletest at configure time
#configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
#execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
#  RESULT_VARIABLE result
#  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
#if(result)
#  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
#endif()
#execute_process(COMMAND ${CMAKE_COMMAND} --build .
#  RESULT_VARIABLE result
#  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
#if(result)
#  message(FATAL_ERROR "Build step for googletest failed: ${result}")
#endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
#add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
#                 ${CMAKE_BINARY_DIR}/googletest-build)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
#if (CMAKE_VERSION VERSION_LESS 2.8.11)
#  include_directories("${gtest_SOURCE_DIR}/include")
#endif()

# Now simply link against gtest or gtest_main as needed. Eg
#add_executable(example example.cpp)
#target_link_libraries(example gtest_main)
#add_test(NAME example_test COMMAND example)


#include_directories(${Boost_INCLUDE_DIR})
#set(SOURCE_FILES main/main.cpp main/simulator.cpp main/object.cpp)
#set(HEADERS main/logger.hpp main/simulator.hpp main/object.hpp main/vec2.hpp)
#add_executable(crawler ${SOURCE_FILES} ${HEADERS})
#target_link_libraries(crawler ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} gtest_main)

#add_test(NAME example_test COMMAND example)

cmake_minimum_required(VERSION 3.5)
project(simulator)

enable_testing()

add_subdirectory(main)
add_subdirectory(simulation)
add_subdirectory(test)
