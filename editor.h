#include"node.h"
class editor{
	public:
		editor();
		~editor();
		node *start=NULL;
		node *next=NULL;
		void InsertNode(std::string);
		void display();
};
