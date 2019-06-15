// TestTreeNode.c
// Written by Group L
// Gruop Membeers: 박지호 김경동 석찬희 오승민 윤민수 이재형

#include <stdio.h>
#include <stdlib.h>

#include "TreeNode.h"
#include "TestTree.h"

TreeNode * createTestTreeNode(long newData){
    TreeNode * newNode = malloc(sizeof(TreeNode));

    newNode->data = newData;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    return newNode;
}


void destroyTestTreeNode(TreeNode * node){
    if(node ==NULL) return;
    destroyTestTreeNode(node->leftChild);
    destroyTestTreeNode(node->rightChild);
    free(node);
}


TreeNode * insertTestTreeNode(TreeNode * node, long num){
    if(node == NULL) return createTestTreeNode(num);
    if(num < node->data)
        node->leftChild = insertTestTreeNode(node->leftChild, num);
    if(num > node->data)
        node->rightChild = insertTestTreeNode(node->rightChild, num);
    return node;

}