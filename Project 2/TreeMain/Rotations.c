//// TestTreeNode.c
//// Written by Group L
//// Gruop Membeers: 박지호 김경동 석찬희 오승민 윤민수 이재형

#include <stdlib.h>

#include "TreeNode.h"
#include "Rotations.h"

TreeNode * singleLeftRotation(TreeNode * node){
    TreeNode * rightChild;

    if (node == NULL) return node;
    if (node->rightChild == NULL) return node;

    rightChild = node->rightChild;

    node->rightChild = rightChild->leftChild;
    rightChild->leftChild = node;

    return rightChild;
}

TreeNode * singleRightRotaion(TreeNode * node){
    TreeNode * leftChild;

    if (node == NULL) return node;
    if (node->leftChild == NULL) return node;

    leftChild = node->leftChild;

    node->leftChild = leftChild->rightChild;
    leftChild->rightChild = node;

    return leftChild;
}

TreeNode * doubleLeftRightRotation(TreeNode * node){
    if (node == NULL) return node;
    if (node->leftChild == NULL) return node;
    if (node->leftChild->rightChild == NULL) return node;

    node->leftChild = singleLeftRotation(node->leftChild);
    return singleRightRotaion(node);
}

TreeNode * doubleRightLeftRotation(TreeNode * node){
    if (node == NULL) return node;
    if (node->rightChild == NULL) return node;
    if (node->rightChild->leftChild == NULL) return node;

    node->rightChild = singleRightRotaion(node->rightChild);
    return singleLeftRotation(node);
}

TreeNode * doubleLeftLeftRotation(TreeNode * node){
    if (node == NULL) return node;
    if (node->rightChild == NULL) return node;
    if (node->rightChild->rightChild == NULL) return node;

    node = singleLeftRotation(node);
    return singleLeftRotation(node);

}

TreeNode * doubleRightRightRotation(TreeNode * node){
    if (node == NULL) return node;
    if (node->leftChild == NULL) return node;
    if (node->leftChild->leftChild == NULL) return node;

    node = singleRightRotaion(node);
    return singleRightRotaion(node);
}