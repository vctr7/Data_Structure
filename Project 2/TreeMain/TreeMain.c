// TreeMain.c
// Written by David Wagner
// This program runs various Timing Experiments on Searchable Trees

#include <time.h>
#include <stdlib.h>

#include "TreeNode.h"
#include "Timer.h"
#include "SearchableTree.h"
#include "Experiment.h"
#include "TreeIO.h"

const int numTrees = 10000;

// Initialize the Random Number Generator
void initializeRandomizer()
{
	srand(time(NULL));
}

// The main function asks for the experiment parameters from the user.
// Then it repeatedly asks for a tree size and runs the experiement on
// that size tree.  The timing results are printed after each run.
int main(int argc, char** argv) 
{
	
	SearchableTree ** treeArray = createTreeArray(numTrees);
	Timer * timer = createTimer();
	ExperimentParameters * params = configureExperiment();
	int size = chooseTreeSize();

	initializeRandomizer();
	
	while (size > 0) {
		runExperiment(treeArray, timer, params, size, numTrees);
		printResults(timer, params, numTrees);
		size = chooseTreeSize();
	}

	return 0;
}


