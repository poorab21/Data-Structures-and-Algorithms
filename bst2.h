#include<iostream>
#include<queue>
#include<math.h>
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
		void Insert(int);
		void LevelOrder();
		void PreOrder(BST*);
		void InOrder(BST*);
		void PostOrder(BST*);
		BST* Search(int);
		void SearchParent(int);
		int find_height(BST*);
		void Right_Sub_Tree(BST*);
};
