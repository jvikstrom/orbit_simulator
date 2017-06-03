file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testgui ${SRCS})

TARGET_LINK_LIBRARIES(testgui
    libgui
    libsim
    gtest
)

add_test(NAME testgui
COMMAND testgui)
