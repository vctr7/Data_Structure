// TreeNode.c
// Written by David Wagner
// This file has functions used by a single Tree Node

#include <stdio.h>
#include <stdlib.h>

#include "TreeNode.h"

// Create a new Tree Node and return the node
TreeNode * createTreeNode(long newData)
{
	TreeNode * newNode = malloc(sizeof (TreeNode));
	
	newNode->data = newData;
	newNode->size = 1;
	newNode->height = 0;
	newNode->max = newData;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	return newNode;
}

// Remove a Tree Node from memory
void destroyTreeNode(TreeNode * node)
{ 
	if (node == NULL) return;
	destroyTreeNode(node->leftChild);
	destroyTreeNode(node->rightChild);
	free(node);
}

// Return the Size of the subtree rooted at this Tree Node
long getSizeTreeNode (TreeNode * node)
{
	if (node == NULL) return 0;
	return node->size;
}

// Return the Height of the subtree rooted at this Tree Node
long getHeightTreeNode (TreeNode * node)
{
	if (node == NULL) return -1;
	return node->height;
}

// Return the Maximum number inside the subtree rooted at this Tree Node
long getMaxTreeNode (TreeNode * node)
{
	if (node == NULL) return 0;
	return node->max;
}

// Return the larger number between num1 and num2
long max(long num1, long num2)
{
	if (num1 > num2) return num1;
	return num2;
}

// Update the Size of this Tree Node, based on its children
void updateSizeTreeNode(TreeNode * node)
{
	if (node == NULL) return;
	node->size = getSizeTreeNode(node->leftChild) + 
			getSizeTreeNode(node->rightChild) + 1;
}

// Update the Height of this Tree Node, based on its children
void updateHeightTreeNode(TreeNode * node)
{
	if (node == NULL) return;
	node->height = max(getHeightTreeNode(node->leftChild), 
		getHeightTreeNode(node->rightChild)) + 1;
}

// Update the Maximum number of this Tree Node, base on its children
void updateMaxTreeNode(TreeNode * node)
{
	if (node == NULL) return;
	node->max = max (max (getMaxTreeNode(node->leftChild), 
			getMaxTreeNode(node->rightChild)), node->data);
}

// Update all three: Size, Height, and Maximum, inside this Tree Node
void updateNodeInfo(TreeNode * node)
{
	if (node == NULL) return;
	updateSizeTreeNode(node);
	updateHeightTreeNode(node);
	updateMaxTreeNode(node);
}

// Return the child of this Tree Node to search, when searching for num 
TreeNode * findChildNode(TreeNode * node, long num)
{
	if (node == NULL) return NULL;
	if (num < node->data) return node->leftChild;
	else return node->rightChild;
}

// Print this subtree rooted at this Tree Node
void printTreeNode(TreeNode * node)
{
	if (node == NULL) return;
	printf("(");
	printTreeNode(node->leftChild);
	printf(" %ld ", node->data);
	printTreeNode(node->rightChild);
	printf(")");
}
		

