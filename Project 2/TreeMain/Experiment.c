// Experiment.c
// Written by David Wagner
// This file contains functions to run the experiment

#include <stdio.h>
#include <stdlib.h>

#include "TreeNode.h"
#include "Timer.h"
#include "SearchableTree.h"
#include "Experiment.h"
#include "TreeIO.h"

// Create an array of Searchable Trees and return it
SearchableTree ** createTreeArray(int numTrees)
{
	SearchableTree ** treeArray = malloc(sizeof(SearchableTree) * numTrees);
	return treeArray;
}

// Ask the user how the experiment should be run.  Store the configuration
// parameters in params and return this
ExperimentParameters * configureExperiment()
{
	ExperimentParameters * params = 
		(ExperimentParameters *) malloc(sizeof(ExperimentParameters));

	printf ("\nConfigure the experiment: \n\n");
	while ((params->treeType = chooseTreeType()) == -1) {};
	while ((params->buildMethod = chooseBuildMethod()) == -1) {};
	while ((params->timingMethod = chooseTiming()) == -1) {};
	if (params->timingMethod == TOTALBUILD) params->repeatMethod = NOREPEAT;
	else while ((params->repeatMethod = chooseRepeat()) == -1) {};
	printf ("Experiment configured!\n\n");
	return params;
}

// Increase the size of the tree, using insert, until it is the correct size
void growTree(SearchableTree * tree, ExperimentParameters * params, long size)
{
	int insertNum;
	while(getSize(tree) < size)
	{
		switch(params->buildMethod) {
			case RANDOM: insertNum = rand() % (size * size); break;
			case INORDER: insertNum = getSize(tree) + 1; break;
		}
		insert(tree, insertNum);
	}
}

// Create all of the trees and grow them to the correct size
void buildTrees(SearchableTree ** treeArray, ExperimentParameters * params, 
		long size, int numTrees)
{
	int index;
	
	printf("(00%%)");
	
	for (index = 0; index < numTrees; index++)
	{
		treeArray[index] = createSearchableTree(params->treeType);
		growTree(treeArray[index], params, size);
		printf("\b\b\b\b%02d%%)", 100 * index / numTrees);
	}
	
}

// Remove all trees from memory
void destroyTrees(SearchableTree ** treeArray, int numTrees)
{
	int index;
	for (index = 0; index < numTrees; index++)
		destroyTree(treeArray[index]);
}

// Search for the number indicated in params in one tree
void searchOneTree(SearchableTree * tree, ExperimentParameters * params)
{
	long index;
	long numRepeat;

	switch(params->repeatMethod) {
		case NOREPEAT: numRepeat = 1; break;
		case REPEAT: numRepeat = getSize(tree); break;
		default: printf("Error in repeat method\n");
	}

	for(index = 0; index < numRepeat; index++)
		switch(params->timingMethod) {
			case SEARCHFORMAX: search(tree, getMax(tree)); break;
			case SEARCHFORONE: search(tree, 1); break;
			case RANDOMSEARCH: search(tree, rand() % getMax(tree)); break;
			default: printf("Error in timing method\n");
		}
}

// Search for the number indicated in params in all trees
void searchTrees(SearchableTree ** treeArray, Timer * timer, 
			ExperimentParameters * params, int numTrees)
{
	int index;
	
	startTimer(timer);
	for(index = 0; index < numTrees; index++)
		searchOneTree(treeArray[index], params);
	stopTimer(timer);
}

// Run the Experiment according the the given size and parameters
void runExperiment(SearchableTree ** treeArray, Timer * timer, 
		ExperimentParameters * params, long size, int numTrees)
{
	printf("Building...");
	if (params-> timingMethod == TOTALBUILD) startTimer(timer);
	buildTrees(treeArray, params, size, numTrees);
	if (params-> timingMethod == TOTALBUILD) stopTimer(timer);
	printf(" Finshed!  ");

	if (params-> timingMethod != TOTALBUILD) {
		printf("Searching... ");
		fflush(stdout);
		searchTrees(treeArray, timer, params, numTrees);
		printf("Finished!");
	}
	printf("\n");
//	printSearchableTree(treeArray[rand() % numTrees]);
	destroyTrees(treeArray, numTrees);
}


