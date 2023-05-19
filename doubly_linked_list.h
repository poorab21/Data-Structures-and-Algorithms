#include<iostream>
struct doubly{
	private:
		doubly *start=NULL;
		doubly *last=NULL;
		doubly *next;
		doubly *prev;
	public:
		int value;
		doubly();
		doubly(const int value);
		~doubly();
		int Size();
		void InsertBefore(const int);
		void InsertAfter(const int);
		void InsertPosition(const int,const int);
		void Forward_Traversing();
		void Reverse_Traversing();
		void DeleteFirst();
		void DeleteLast();
		void DeletePosition(const int);
		void DeleteNode(const int);
		void  Merge(doubly);
		void CommonElements(doubly);
};
