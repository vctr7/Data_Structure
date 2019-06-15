// BuildTestTree.c
// Written by David Wagner
// This file contains functions which build a Test Tree with several nodes

#include "TreeNode.h"
#include "TestTree.h"
#include "BuildTestTree.h"

// Build a Single Right Test Tree like this:
//   2
// 1   4
//    3 5
// This can be used to test Single Left Rotation
void buildSingleRightTree(TestTree * tree)
{
	insertTestTree(tree, 2);
	insertTestTree(tree, 1);
	insertTestTree(tree, 4);
	insertTestTree(tree, 3);
	insertTestTree(tree, 5);
}

// Build a Single Left Test Tree like this:
//    4
//  2   5
// 1 3
// This can be used to test Single Right Rotation
void buildSingleLeftTree(TestTree * tree)
{
	insertTestTree(tree, 4);
	insertTestTree(tree, 2);
	insertTestTree(tree, 1);
	insertTestTree(tree, 3);
	insertTestTree(tree, 5);
}

// Build a Double Right Right Test Tree like this:
//     2
// 1       4
//       3   6
//          5 7
// This can be used to test Double Left Left Rotation
void buildDoubleRightRightTree(TestTree * tree)
{
	insertTestTree(tree, 2);
	insertTestTree(tree, 1);
	insertTestTree(tree, 4);
	insertTestTree(tree, 3);
	insertTestTree(tree, 6);
	insertTestTree(tree, 5);
	insertTestTree(tree, 7);
}

// Build a Double Right Left Test Tree like this:
//     2
// 1       6
//       4   7
//      3 5
// This can be used to test Double Right Left Rotation
void buildDoubleRightLeftTree(TestTree * tree)
{
	insertTestTree(tree, 2);
	insertTestTree(tree, 1);
	insertTestTree(tree, 6);
	insertTestTree(tree, 4);
	insertTestTree(tree, 3);
	insertTestTree(tree, 5);
	insertTestTree(tree, 7);
}

// Build a Double Left Right Test Tree like this:
//        6
//    2       7
//  1   4
//     3 5
// This can be used to test Double Left Right Rotation
void buildDoubleLeftRightTree(TestTree * tree)
{
	insertTestTree(tree, 6);
	insertTestTree(tree, 2);
	insertTestTree(tree, 7);
	insertTestTree(tree, 1);
	insertTestTree(tree, 4);
	insertTestTree(tree, 3);
	insertTestTree(tree, 5);
}

// Build a Double Left Left Test Tree like this:
//        6
//    4       7
//  2   5
// 1 3
// This can be used to test Double Right Right Rotation
void buildDoubleLeftLeftTree(TestTree * tree)
{
	insertTestTree(tree, 6);
	insertTestTree(tree, 4);
	insertTestTree(tree, 7);
	insertTestTree(tree, 2);
	insertTestTree(tree, 5);
	insertTestTree(tree, 1);
	insertTestTree(tree, 3);
}

// Build a Double Balanced Tree like this:
//       4
//   2       6
// 1   3   5   7
// This is the target after Double Left Right or Right Left Rotation
void buildDoubleBalancedTree(TestTree * tree)
{
	insertTestTree(tree, 4);
	insertTestTree(tree, 2);
	insertTestTree(tree, 6);
	insertTestTree(tree, 1);
	insertTestTree(tree, 3);
	insertTestTree(tree, 5);
	insertTestTree(tree, 7);
}



