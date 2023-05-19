#include<iostream>
struct stack{
		private:	
			int data;
			stack *next;
			stack *start;
		public:
			stack();
			stack(int);
			~stack();
			void Push(int);
			void Pop();
			void Display();
			int Peek();
			void IsEmpty();
};
