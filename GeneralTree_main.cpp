#include"GeneralTree.h"
int main()
{
	Tree *t=new Tree();
	t->root=t->Insert(5);
	t->root->child.push_back(t->Insert(12));
	t->root->child.push_back(t->Insert(55));
	t->root->child.push_back(t->Insert(25));
	t->root->child[0]->child.push_back(t->Insert(55));
	t->root->child[0]->child.push_back(t->Insert(61));
	t->root->child[1]->child.push_back(t->Insert(33));
	t->root->child[1]->child.push_back(t->Insert(23));
	t->root->child[2]->child.push_back(t->Insert(44));
	t->LevelOrder();
}
