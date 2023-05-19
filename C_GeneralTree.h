#include<iostream>
#include<vector>
#include<queue>
class Tree{
	private:
		int data;
	public:
		Tree();
		Tree(int);
		~Tree();
		Tree *root=NULL;
		Tree *left=NULL;
		Tree *right=NULL;
		Tree* Insert(int);
		std::vector<Tree*> child;
		void LevelOrder();
};
