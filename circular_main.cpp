#include"circular.h"
int main()
{
	queue q1;
	q1.Enqueue(14);
	q1.Enqueue(22);
	q1.Enqueue(6);
	q1.Display();
	q1.Dequeue();
	q1.Dequeue();
	q1.Display();
	q1.Enqueue(9);
	q1.Enqueue(20);
	q1.Display();
}
