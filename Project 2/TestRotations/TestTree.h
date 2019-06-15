typedef struct TESTTREE{
    TreeNode * root;
}TestTree;

TreeNode * insertTestTreeNode(TreeNode * node, long num);
TreeNode * createTestTreeNode(long newData);
void destroyTestTreeNode(TreeNode * node);
TestTree * createTestTree();
void destroyTestTree(TestTree * tree);
void insertTestTree(TestTree * tree, long num);
