// UnitTest.c
// Written by David Wagner
// This file contains the assert functions used during unit testing

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TreeNode.h"
#include "TestTree.h"
#include "UnitTest.h"

#define FALSE 0
#define TRUE 1

static char testFailed = FALSE;

// Check is testValue is TRUE or FALSE.  If it is
// FALSE, then print a message, and update testFailed
char assert(char testValue, char * testString)
{
	testFailed = testFailed | !testValue;

//	if (testValue)
//		printf("Test Passed: %s\n", testString);
	if (!testValue)
//		printf("Test FAILED: ");
		printf("%s ", testString);
	return testValue;
}

// Check if num1 is equal to num2
char assertEquals(long num1, long num2, char * testString)
{
	return assert(num1 == num2, testString);
}


// Check if two subtrees, rooted at node1 and node2, are equal
char assertEqualNodes(TreeNode * node1, TreeNode * node2, char * testString)
{
	char result = TRUE;

	if (node1 == NULL && node2 == NULL) return result;
	if (node1 == NULL || node2 == NULL) {
		return assert(FALSE, testString); 
	}
	result &= assertEquals(node1->data, node2->data, testString);
	if (node1->data == node2->data) {
		result &= assertEqualNodes(node1->leftChild, node2->leftChild, testString);
		result &= assertEqualNodes(node1->rightChild, node2->rightChild, testString);
	}
	return result;
}

// Check if two trees are equal
void assertEqualTrees(TestTree * tree1, TestTree * tree2, char * testString)
{
	if (assertEqualNodes(tree1->root, tree2->root, testString))
		printf("Test Passed.\n");
	else
		printf("TEST FAILED!\n");
}

// Print the Results of all previous asserts.
void printTestResults()
{
	if (!testFailed)
		printf("\nAll tests PASSED!\n");
	else
		printf("\nTests FAILED!\n");
}

