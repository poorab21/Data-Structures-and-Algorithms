#include"tree.h"
int main()
{
	BST *b1=new BST();
	b1->Insert(18);
	b1->Insert(15);
	b1->Insert(20);
	b1->Insert(12);
	b1->Insert(16);
	b1->Insert(19);
	b1->Insert(21);
	b1->Insert(1);
	b1->Insert(13);
	b1->Insert(0);
	b1->Insert(14);
	b1->Insert(17);
	b1->Delete(15);
	b1->LevelOrder();
}
