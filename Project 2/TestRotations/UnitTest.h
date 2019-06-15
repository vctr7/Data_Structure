// UnitTest.h

char assert(char testValue, char * testString);
char assertEquals(long num1, long num2, char * testString);
char assertEqualNodes(TreeNode * node1, TreeNode * node2, char * testString);
void assertEqualTrees(TestTree * tree1, TestTree * tree2, char * testString);
void printTestResults();

