// TestRotations.c
// Written by David Wagner
// This program performs tests of the Rotations in Rotations.c

#include <stdio.h>
#include <stdlib.h>

#include "TreeNode.h"

#include "TestTree.h"
#include "BuildTestTree.h"
#include "Rotations.h"
#include "UnitTest.h"
#include "PrintTree.h"

#define FALSE 0
#define TRUE 1

// These are the different possible Rotations
typedef enum { SINGLELEFT, SINGLERIGHT, DOUBLELEFTLEFT, DOUBLELEFTRIGHT,
		DOUBLERIGHTLEFT, DOUBLERIGHTRIGHT, ALL } RotationType;

// These are the strings describing each Rotation
char * rotationString[7] = {"Single Left", "Single Right", "Double Left Left",
	"Double Left Right", "Double Right Left", "Double Right Right", "All"};

// This creates a Start Tree and a Target tree for a test of this Rotation
void buildStartAndTargetTrees(TestTree * startTree, TestTree * targetTree,
			RotationType rotationType)
{
	switch(rotationType){
		case SINGLELEFT: 
			buildSingleRightTree(startTree); 
			buildSingleLeftTree(targetTree); break;
		case SINGLERIGHT: 
			buildSingleLeftTree(startTree); 
			buildSingleRightTree(targetTree); break;
		case DOUBLELEFTLEFT: 
			buildDoubleRightRightTree(startTree); 
			buildDoubleLeftLeftTree(targetTree); break;
		case DOUBLELEFTRIGHT: 
			buildDoubleLeftRightTree(startTree); 
			buildDoubleBalancedTree(targetTree); break;
		case DOUBLERIGHTLEFT: 
			buildDoubleRightLeftTree(startTree); 
			buildDoubleBalancedTree(targetTree); break;
		case DOUBLERIGHTRIGHT: 
			buildDoubleLeftLeftTree(startTree); 
			buildDoubleRightRightTree(targetTree); break;
	}
}

// Perform the Rotation on the Root of the Test Tree
void performRotation(TestTree * tree, RotationType rotationType)
{
	switch(rotationType){
		case SINGLELEFT: 
			tree->root = singleLeftRotation(tree->root); break;
		case SINGLERIGHT: 
			tree->root = singleRightRotaion(tree->root); break;
		case DOUBLELEFTLEFT: 
			tree->root = doubleLeftLeftRotation(tree->root); break;
		case DOUBLELEFTRIGHT: 
			tree->root = doubleLeftRightRotation(tree->root); break;
		case DOUBLERIGHTLEFT: 
			tree->root = doubleRightLeftRotation(tree->root); break;
		case DOUBLERIGHTRIGHT: 
			tree->root = doubleRightRightRotation(tree->root); break;
	}

}

// Perform a test of the Rotation
void testRotation(RotationType rotationType, char printTrees)
{
	TestTree * startTree = createTestTree();
	TestTree * targetTree = createTestTree();

	buildStartAndTargetTrees(startTree, targetTree, rotationType);

	if (printTrees) printf("Before Rotation:\n");
	if (printTrees) printTestTree(startTree);
	performRotation(startTree, rotationType);
	if (printTrees) printf("After Rotation:\n");
	if (printTrees) printTestTree(startTree);
	assertEqualTrees(startTree, targetTree, rotationString[rotationType]);

	destroyTestTree(startTree);
	destroyTestTree(targetTree);
}

// Test every kind of Rotation, and print whether they all passed or not
void testAllRotations()
{
	RotationType rotationType;

	for (rotationType = SINGLELEFT; rotationType <= DOUBLERIGHTRIGHT; 
		rotationType++)
	{
		printf("Testing %s Rotation...", rotationString[rotationType]);
		testRotation(rotationType, FALSE);
	}
	printTestResults();
}

// Print a list of all tests, and return the chosen test number
int chooseTest()
{
	int testChoice;

	printf("\n1) Demo and Test Single Left Rotation\n");
	printf("2) Demo and Test Single Right Rotation\n");
	printf("3) Demo and Test Double Left Left Rotation\n");
	printf("4) Demo and Test Double Left Right Rotation\n");
	printf("5) Demo and Test Double Right Left Rotation\n");
	printf("6) Demo and Test Double Right Right Rotation\n");
	printf("\n7) Test all Rotations\n\n");
	printf("Choose the Test or Demo (0 to quit):");

	scanf("%d", &testChoice);

	return testChoice;
}

// The main function of this program repeatedly asks the user 
// to choose a test or demo and it performs the test or demo
int main()
{
	int testChoice = chooseTest();
	
	while (testChoice > 0) {
		printf("\n");
		switch (testChoice) {
			case 1: testRotation(SINGLELEFT, TRUE); break;
			case 2: testRotation(SINGLERIGHT, TRUE); break;
			case 3: testRotation(DOUBLELEFTLEFT, TRUE); break;
			case 4: testRotation(DOUBLELEFTRIGHT, TRUE); break;
			case 5: testRotation(DOUBLERIGHTLEFT, TRUE); break;
			case 6: testRotation(DOUBLERIGHTRIGHT, TRUE); break;
			case 7: testAllRotations(); break;
			default: printf("Error: Invalid Test or Demo\n"); 
		}
		testChoice = chooseTest();
	}
	return 0;
}

