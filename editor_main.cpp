#include"editor.h"
int main()
{
	editor e;
	e.InsertNode("this is sample text");
	e.InsertNode("this is text");
	e.InsertNode("this is text 4");
	e.InsertNode("this is text 5");
	e.InsertNode("this is text 8");
	e.display();
}
