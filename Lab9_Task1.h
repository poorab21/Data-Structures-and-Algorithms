#include<iostream>
#include<queue>
#include<stack>
struct BST{
	char data;
	std::string PostFix_Expression;
	BST *left;
	BST *right;
	BST *root;
	BST();
	BST(const char);
	~BST();
	void LevelOrder();
	BST* InsertNode(const char);
	void PostOrder_Conversion(BST*);
};
