#include"doubly_linked_list.h"
int main()
{
/*	doubly l1;
	l1.InsertAfter(1);
	l1.InsertBefore(2);
	l1.InsertPosition(5,1);
	l1.InsertAfter(5);
	l1.Forward_Traversing();
	l1.Reverse_Traversing();
	l1.DeleteNode(5);
	l1.InsertAfter(3);
	l1.DeleteFirst();
	l1.DeleteLast();
	std::cout<<std::endl;
	l1.Forward_Traversing(); */
	doubly l2,l3;
	l2.InsertAfter(1);
	l2.InsertAfter(2);
	l2.InsertAfter(3);
	l2.InsertAfter(4);
	l2.InsertAfter(5);
	l2.InsertAfter(10);
	
	l3.InsertAfter(7);
	l3.InsertAfter(8);
	l3.InsertAfter(9);
	l3.InsertAfter(10);
	l3.InsertAfter(11);
	l3.InsertAfter(10);
//	l2.Merge(l3);
	l2.InsertBefore(100);
	l3.InsertAfter(100);
//	l2.DeleteFirst();
//	l2.InsertPosition(4,13);
//	l2.Forward_Traversing(); */
/*	l1.Forward_Traversing();
	l2.Forward_Traversing();
	std::cout<<"After Merging"<<std::endl;
	l1.Merge(l2);
	l1.Forward_Traversing(); */
	l2.CommonElements(l3);
}
