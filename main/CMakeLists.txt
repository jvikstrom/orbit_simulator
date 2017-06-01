#cmake_minimum_required(VERSION 3.5)
#project(crawler)

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
#gtest_main
set(Main_SRC main.cpp)
set(HEADERS)
add_executable(crawler ${Main_SRC})
target_link_libraries(crawler libsim libgui)
#${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}
install(TARGETS crawler DESTINATION bin)
