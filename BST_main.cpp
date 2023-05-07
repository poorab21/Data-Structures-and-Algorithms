#include"bst.h"
int main()
{
	BST *b1=new BST;
	b1->Insert(7);
	b1->Insert(9);
	b1->Insert(10);
	b1->Insert(4);
	b1->Insert(5);
	b1->Insert(1);
	b1->SearchParent(10);
}
