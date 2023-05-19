#include<iostream>
#include<queue>
struct BST{
	int data;
	BST();
	BST(int);
	~BST();
	BST *root;
	BST *left;
	BST *right;
	void InsertNode(int);
	void LevelOrder();
	int Height_Find(BST*);
	void InOrder(BST*);
	void PreOrder(BST*);
	void PostOrder(BST*);
	void Right_Subtree_Order_Display();
};
