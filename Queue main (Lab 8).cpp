#include"Queue.h"
int main()
{
	queue q1;
	q1.Enqueue(12);
	q1.Enqueue(22);  // 12  22
	q1.Peek();      //front value =12
	q1.IsEmpty();    //not empty
	q1.Display();   // 12  22
	q1.Dequeue();   // 22
	q1.Display();   //22
	q1.Dequeue();  // no value in list
	q1.IsEmpty();  // list is empty
	q1.Enqueue(100);  //100
	q1.Enqueue(120); //100 120
	q1.Dequeue();    //120
	q1.Peek();    //front value = 120
	q1.Display(); //120
}
