//By Elzamin Usubaliev
//Project Rope

#include <iostream>
#include <string>
#include "Rope.h"
#include "Node.h"

using namespace std;

int main()
{
	string b = "hello";
	string *a = &b;
	Rope *B = new Rope();
	B->Add(a);
	B->Check();
	//B->Print();
	system("pause");
	return 0;
}
