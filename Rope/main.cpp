//By Elzamin Usubaliev
//Project "Rope"
#include <iostream>
#include <string>
#include "Rope.h"

using namespace std;

int main()
{
	string b = "hello";
	string *a = &b;
	string c = "bbbbbbb";
	string *d = &c;
	string e = "ccccccccc";
	string *f = &e;
	string search;
	std::cout << ">----------------<\n|Created new rope|\n>----------------<\n";
	Node *root = new Node();
	root->Add(a);
	root->Add(d);
	root->Add(f);
	root->Add(a);
	root->Add(d);
	root->Add(f);



	root->PrintString();

	root->DeleteOne(6);
	root->PrintString();
	/*search = root->SearchStr(32);
	std::cout << search << std::endl;*/
	//root->Check();
	system("pause");
	return 0;
}
