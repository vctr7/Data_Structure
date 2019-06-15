// SearchableTree.c
// Written by David Wagner
// This file has functions used by a Searchable Tree

#include <stdio.h>
#include <stdlib.h>

#include "TreeNode.h"
#include "SearchableTree.h"

// Create a new Searchable Tree and return it
SearchableTree * createSearchableTree(TreeType newType)
{
	SearchableTree * newTree = malloc(sizeof(SearchableTree));

	newTree->type = newType;
	newTree->root = NULL;
	return newTree;
}

// Remove a Searchable Tree from memory
void destroyTree(SearchableTree * tree)
{
	destroyTreeNode(tree->root);
	free(tree);
}

// Insert num into a Searchable Tree
void insert (SearchableTree * tree, long num) {
	switch(tree->type) {
		case XTREE: tree->root = insertXTreeNode(tree->root, num); break;
		case YTREE: tree->root = insertYTreeNode(tree->root, num); break;
		case ZTREE: tree->root = insertZTreeNode(tree->root, num); break;
	}
}

// Search for num in a Searchable Tree
TreeNode * search (SearchableTree * tree, long num) {
	TreeNode * result;

	switch(tree->type) {
		case XTREE: tree->root = searchXTreeNode(tree->root, num, &result); break;
		case YTREE: tree->root = searchYTreeNode(tree->root, num, &result); break;
		case ZTREE: tree->root = searchZTreeNode(tree->root, num, &result); break;
	}

	return result;
}

// Print a Searchable Tree
void print (SearchableTree * tree) {
	printf("{");
	printTreeNode(tree->root);
	printf("}");
}

// Return the size of a Searchable Tree
long getSize (SearchableTree * tree) {
	return getSizeTreeNode(tree->root);
}

// Return the maximum number in a Searchable Tree
long getMax (SearchableTree * tree) {
	return getMaxTreeNode(tree->root);
}

