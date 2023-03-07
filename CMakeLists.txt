cmake_minimum_required(VERSION 3.0)

project(cintolo LANGUAGES C)

add_executable(cintolo main.c ArrayList.c ArrayList.h spcopr.c spcopr.h lib_system.c lib_system.h)

install(TARGETS cintolo RUNTIME DESTINATION bin)
