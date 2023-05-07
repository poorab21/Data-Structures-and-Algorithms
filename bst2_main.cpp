#include"bst.h"
int main()
{
	BST *t=new BST;
	t->Insert(21);
	t->Insert(16);
	t->Insert(2);
	t->Insert(25);
	t->Insert(30);
	t->Insert(14);
	t->Insert(60);
	t->Insert(8);
	t->Insert(15);
	t->Insert(35);
	t->Insert(40);
	t->Insert(100);
	t->Insert(55);
	t->LevelOrder();
	std::cout<<std::endl;
	t->Insert(2);
	t->Insert(55);
	t->Insert(35);
	t->LevelOrder();
	std::cout<<std::endl<<"Height = "<<t->find_height(t->root)<<std::endl;
	t->Right_Sub_Tree(t->root);
}
