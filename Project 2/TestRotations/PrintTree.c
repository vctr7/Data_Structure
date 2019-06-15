// PrintTree.c
// Written by David Wagner
// This file contains function which can print a binary tree

#include <stdio.h>
#include <stdlib.h>

#include "TreeNode.h"
#include "TestTree.h"
#include "PrintTree.h"

// Print the numbers of the Tree Nodes stored in the Frontier
void printFrontier(TreeNode ** frontier, int frontierSize)
{
	int i;
	for (i=0; i<frontierSize; i++) {
		if (frontier[i] == NULL) printf ("  ");
		else printf("%ld ", frontier[i]->data);
	}
	printf("\n");
}

// Advance the Frontier to the Children of the Nodes in the Frontier
void advanceFrontier(TreeNode ** frontier, int frontierSize, int gap)
{
	int i;
	TreeNode ** newFrontier = malloc(frontierSize * sizeof(TreeNode *));
	for (i=0; i<frontierSize; i++) newFrontier[i] = NULL;
	for (i=0; i<frontierSize; i++)
		if (frontier[i] != NULL) {
			newFrontier[i - gap] = frontier[i]->leftChild;
			newFrontier[i + gap] = frontier[i]->rightChild;
		}
	for (i=0; i<frontierSize; i++) frontier[i] = newFrontier[i];
	free(newFrontier);
}

// Print the Tree by repeatedly printing each row of Nodes in the Tree
void printTestTree(TestTree * tree)
{
	const int frontierSize = 16;
	int i, gap = frontierSize / 2;
	TreeNode ** frontier = malloc(frontierSize * sizeof(TreeNode *));
	for (i=0; i<frontierSize; i++) frontier[i] = NULL;
	frontier[gap] = (tree->root);
	for (i=0; i<4; i++) {
		printFrontier(frontier, frontierSize);
		gap /= 2;
		advanceFrontier(frontier, frontierSize, gap);
	}
	free(frontier);
}




