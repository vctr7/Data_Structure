typedef struct TREENODE{
    long data;
    long size;
    long height;
    long max;
    struct TREENODE * leftChild;
    struct TREENODE * rightChild;
}TreeNode;

TreeNode * createTreeNode(long newData);
void destroyTreeNode(TreeNode * node);
long getSizeTreeNode(TreeNode * node);
long getHeightTreeNode(TreeNode * node);
long getMaxTreeNode(TreeNode * node);
void updateNodeInfo(TreeNode * node);
TreeNode * findChildNode(TreeNode * node, long num);
void printTreeNode(TreeNode * node);

TreeNode * searchXTreeNode(TreeNode * node, long num, TreeNode ** searchResult);
TreeNode * insertXTreeNode(TreeNode * node, long num);
TreeNode * searchYTreeNode(TreeNode * node, long num, TreeNode ** searchResult);
TreeNode * insertYTreeNode(TreeNode * node, long num);
TreeNode * searchZTreeNode(TreeNode * node, long num, TreeNode ** searchResult);
TreeNode * insertZTreeNode(TreeNode * node, long num);