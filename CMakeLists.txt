cmake_minimum_required(VERSION 2.8)
project(untitled C)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS"-std=c99-fdump-rtl-expand")

add_executable(untitled book_management.h main.c Main.c saveLoad.c Register.c Login.c BorrowSystem.c Admin.c libraries.txt Users.txt)
