cmake_minimum_required(VERSION 3.13)
project(TestRotations C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(TestRotations
        BuildTestTree.c
        BuildTestTree.h
        PrintTree.c
        PrintTree.h
        Rotations.c
        Rotations.h
        TestRotations.c
        TestTree.c
        TestTree.h
        TestTreeNode.c
        TreeNode.h
        UnitTest.c
        UnitTest.h)
