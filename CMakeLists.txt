cmake_minimum_required(VERSION 3.26)
project(Gobang)

set(CMAKE_CXX_STANDARD 11)
include_directories(EasyX/include)
link_directories(EasyX/lib64)
link_libraries(libeasyx.a)





add_executable(Gobang
        easyx_components.h
        gameplayback.cpp
        headerfile.cpp
	headerfile.h
        homepage.cpp
        main.cpp
	PVPgamepage.cpp
	selection.cpp)