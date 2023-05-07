#include<iostream>
struct linkedlist{
	int data;
	linkedlist();
	linkedlist(int);
	~linkedlist();
	linkedlist *next;
	void InsertStart(int);
	void InsertEnd(int);
	void InsertPosition(int,int);
	void Forward_Traversing();
	void DeleteFirst();
	void DeleteLast();
	void DeletePosition(int);
	void Search(int);
	void Reverse_Traversing();
	void DeleteNode(int);
	int Size();
	linkedlist *start=NULL;
};
