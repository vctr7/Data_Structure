cmake_minimum_required(VERSION 3.13)
project(TreeMain)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TreeMain
        Experiment.c
        XYZTreeNode_MacOSX.o
        Experiment.h
        SearchableTree.c
        SearchableTree.h
        Timer.h
        Timer_MacUnix.c
        TreeIO.c
        TreeIO.h
        Rotations.c
        Rotations.h
        TreeNode.h
        TreeMain.c
        TreeNode.c)
