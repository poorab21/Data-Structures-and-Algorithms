#include<iostream>
struct queue{
	private:
		int data;
		queue *next=NULL;
		queue *front=NULL;
		queue *rear=NULL;
	public:
		queue();
		queue(int);
		~queue();
		void Enqueue(int);
		void Dequeue();
		void Peek();
		void IsEmpty();
		void Display();
};
