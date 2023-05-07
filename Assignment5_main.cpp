#include"linked_list.h"
int main()
{
	linkedlist l1;
	l1.InsertStart(1);
	l1.Forward_Traversing();
	l1.InsertEnd(2);
	l1.Forward_Traversing();
	l1.InsertEnd(3);
	l1.Forward_Traversing();
	l1.InsertEnd(4);
	l1.Forward_Traversing();
	l1.InsertPosition(3,1);
	l1.Forward_Traversing();
	l1.InsertPosition(7,5);
	l1.Forward_Traversing();
	l1.DeleteFirst();
	l1.Forward_Traversing();
	l1.DeleteLast();
	l1.Forward_Traversing();
	l1.DeletePosition(2);
	l1.Forward_Traversing();
	l1.DeleteLast();
	l1.Forward_Traversing();
	l1.Reverse_Traversing(); 
}
