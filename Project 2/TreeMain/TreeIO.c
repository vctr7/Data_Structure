// TreeIO.c
// Written by David Wagner
// This file has the input and output functions for Trees

#include <stdio.h>
#include <stdlib.h>

#include "Timer.h"
#include "TreeNode.h"
#include "SearchableTree.h"
#include "Experiment.h"
#include "TreeIO.h"

// Ask the user to choose a Tree Type: XTree, YTree, or ZTree
TreeType chooseTreeType()
{
	int treeType = 0;
	printf("Choose 1)XTree, 2)YTree, 3)ZTree: ");
	scanf("%d", &treeType);
	if (treeType < 1 || treeType > 3)
	{ printf("Error: Invalid Tree Type\n"); return -1; }
	printf("\n");
	switch(treeType) {
		case 1: return XTREE;
		case 2: return YTREE;
		case 3: return ZTREE;
		default: printf("Error: Invalid Tree Type\n"); return -1;
	}
}

// Ask the user to choose the method to build the tree
BuildMethod chooseBuildMethod()
{
	int buildMethod = -1;
	printf("1) Insert the numbers 1..n\n");
	printf("2) Insert n numbers at random\n");
	printf("How should the tree be built: ");
	scanf("%d", &buildMethod);
	switch(buildMethod) {
		case 1: printf("\n"); return INORDER;
		case 2: printf("\n"); return RANDOM;
		default: printf("Error: Invalid Method\n"); return -1;
	}
}

// Ask the user to choose what should be timed
TimingMethod chooseTiming()
{
	int timingMethod = -1;
	printf("1) Total Build time\n");
	printf("2) Time to Search for the largest number\n");
	printf("3) Time to Search for 1\n");
	printf("4) Time to Search for a random number\n");
	printf("Which time do you want to measure: ");
	scanf("%d", &timingMethod);
	switch(timingMethod) {
		case 1: printf("\n"); return TOTALBUILD;
		case 2: printf("\n"); return SEARCHFORMAX;
		case 3: printf("\n"); return SEARCHFORONE;
		case 4: printf("\n"); return RANDOMSEARCH;
		default: printf("Error: Invalid Method\n"); return -1;
	}
	return timingMethod;
}

// Ask the user to choose how many times to repeat the search
RepeatMethod chooseRepeat()
{
	int repeatMethod = -1;
	printf("1) Search once\n");
	printf("2) Repeat the search n times\n");
	printf("How many time to search: ");
	scanf("%d", &repeatMethod);
	switch(repeatMethod) {
		case 1: printf("\n"); return NOREPEAT;
		case 2: printf("\n"); return REPEAT;
		default: printf("Error: Invalid Method\n"); return -1;
	}
}

// Ask the user to choose the size of the tree
int chooseTreeSize()
{
	int size = 0;
	printf("Enter the size of the Tree(Enter 0 to quit): ");
	scanf("%d", &size);
	return size;
}

// Print the total time to build the tree
void printTotalBuildTime(Timer * timer, int numTrees)
{
	printf("Total Build Time: %.8f seconds per tree\n\n",
		getTotalSeconds(timer) / numTrees);
}

// Print the time to Search the tree
void printSearchTime(Timer * timer, ExperimentParameters * params, 
		int numTrees)
{
	if (params->repeatMethod == NOREPEAT) printf("Search Time: ");
	else printf("Total Time for n Searches: ");
	printf("%.8f seconds per tree\n\n", 
		getTotalSeconds(timer) / numTrees);
}

// Print the results of the experiment: Build Time or Search Time
void printResults(Timer * timer, ExperimentParameters * params, int numTrees)
{
	if (params->timingMethod == TOTALBUILD) 
		printTotalBuildTime(timer, numTrees);
	else
		printSearchTime(timer, params, numTrees);
}

