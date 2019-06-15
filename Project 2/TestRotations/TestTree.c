// TestTreeNode.c
// Written by Group L
// Gruop Membeers: 박지호 김경동 석찬희 오승민 윤민수 이재형

#include <stdio.h>
#include <stdlib.h>

#include "TreeNode.h"
#include "TestTree.h"

TestTree * createTestTree(){
    TestTree * newTree = malloc(sizeof(TestTree));

    newTree->root = NULL;
    return newTree;
}

void destroyTestTree(TestTree * tree){
    destroyTestTreeNode(tree->root);
    free(tree);
}

void insertTestTree(TestTree * tree, long num){
    tree->root = insertTestTreeNode(tree->root, num);
}