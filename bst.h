#include<iostream>
#include<queue>
class BST{
	private:
		int data;
		BST *left=NULL;
		BST *right=NULL;
	public:
		BST *root=NULL;
		BST();
		BST(int);
		~BST();
		void PreOrder(BST*);
		void PostOrder(BST*);
		void InOrder(BST*);
		void LevelOrder();
		void Insert(int);
		bool Search(int);
		void SearchParent(int);
};
