#include<iostream>
#include<queue>
class BST{
	private:
		int data;
		BST *left=NULL;
		BST *right=NULL;
		BST *root=NULL;
	public:
		BST();
		BST(int);
		~BST();
		void Insert(int);
		BST* ParentFind(int);
		void Delete(int);
		BST* Search(int);
		void LevelOrder();
};
