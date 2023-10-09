cmake_minimum_required(VERSION 3.5)

project(Test_Task_CAD LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Test_Task_CAD main.cpp
    threedcurve.h threedcurve.cpp
    circles.h circles.cpp
    ellipses.h ellipses.cpp
    helixes.h helixes.cpp)

include(GNUInstallDirs)
install(TARGETS Test_Task_CAD
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
