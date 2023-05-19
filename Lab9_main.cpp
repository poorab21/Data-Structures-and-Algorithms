#include"Task2.h"
int main()
{
	BST *t=new BST;
	t->InsertNode(21);
	t->InsertNode(16);
	t->InsertNode(2);
	t->InsertNode(25);
	t->InsertNode(30);
	t->InsertNode(14);
	t->InsertNode(60);
	t->InsertNode(8);
	t->InsertNode(15);
	t->InsertNode(35);
	t->InsertNode(40);
	t->InsertNode(100);
	t->InsertNode(55);
	t->LevelOrder();
	std::cout<<std::endl;
	t->InsertNode(2);
	t->InsertNode(55);
	t->InsertNode(35);
	t->LevelOrder();
	std::cout<<std::endl<<"Height = "<<t->Height_Find(t->root)<<std::endl;
	t->Right_Subtree_Order_Display();
}
