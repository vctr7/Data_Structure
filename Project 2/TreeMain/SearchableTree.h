// SearchableTree.h
// Header file for SearchableTree.c

typedef enum { XTREE, YTREE, ZTREE } TreeType;

typedef
struct SEARCHABLETREE
{
	TreeType type;
	TreeNode * root;

}SearchableTree;

SearchableTree * createSearchableTree(TreeType newType);
void destroyTree(SearchableTree * tree);
void insert (SearchableTree * tree, long num);
TreeNode * search (SearchableTree * tree, long num);
void print (SearchableTree * tree);
long getSize (SearchableTree * tree);
long getMax (SearchableTree * tree);


