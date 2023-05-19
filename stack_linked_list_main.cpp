#include"stack_linked_list.h"
int main()
{
	stack s1;
	s1.Push(1);
	s1.Push(2);
	s1.Display();
	s1.Pop();
	s1.Display();
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);
	s1.Push(6);
	s1.Push(7);
	s1.Push(8);
	s1.Push(9);
	s1.Push(10);
	s1.Display();
	s1.Pop();
	s1.Pop(); 
	s1.Pop();
	std::cout<<s1.Peek()<<"\n";
	s1.Display();
}
