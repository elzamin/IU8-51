#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

int main() {
	
	system("pause");
	return 0;
}

class ROPE
{
private:
	int weight;
	POINT *way;
	POINT *head;
public:
	ROPE() 
	{
		weight = 0;
		POINT START = {};
		way = &START;
	}
	void add_(string *text) 
	{
		POINT A = {};
		*A.date = *text;
		A.weight = size(*text);
		weight = weight + A.weight;

		int h = 0;
		do 
		{
			if (!way->left)
			{
				way->left = &A;
			}
			if (!way->right)
			{
				way->right = &A;
			}
			way->right;
			h++;
		} while (way->date != nullptr || !way->right);
		*way = *head;
		for (int i = 0; i < h + 1; i++)
			head->right;
		if (way->left != nullptr)
			way->right = &A;
		else
		{
			*way = *head;
			for (int i = 0; i < h; i++)
				head->right;
			POINT B = {};
			*B.left = *way->right;
			B.right = &A;
			way->right = &B;
		}
	}
	void delete_(int key) {}
	void search_(int key) {}
	void min_(int key) {}
	void max_(int key) {}
	void print_() {}
	~ROPE() {}
};

struct POINT
{
	int weight;
	POINT *left;
	POINT *right;
	string *date;

};
