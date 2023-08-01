cmake_minimum_required(VERSION 3.25)
project(checkpoint_YehudaNevo C)

set(CMAKE_C_STANDARD 11)

add_executable(checkpoint_YehudaNevo
        main.c Class.c Student.c School.h School.c Group.c main_util.h)
