#include<iostream>
struct queue{
	private:
		int data;
		queue *front=NULL;
		queue *rear=NULL;
		queue *next=NULL;
	public:
		queue();
		queue(int);
		~queue();
		void Enqueue(int);
		void Dequeue();
		void IsEmpty();
		void Peek();
		void Display();
};
