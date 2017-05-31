file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testsim ${SRCS})

TARGET_LINK_LIBRARIES(testsim
    libsim
    gtest
)

add_test(NAME testsim
COMMAND testsim)
