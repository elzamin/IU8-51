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
		head = &START;
		*way = *head;
	}

	void add_(string *text) 
	{
		POINT A = {};
		*A.date = *text;
		A.weight = size(*text);
		weight = weight + A.weight;
		way->weight = way->weight + A.weight;
		int h = 0;

		do 
		{
			if (!way->left)
				way->left = &A;
			if (!way->right)
				way->right = &A;
			way->right;
			h++;
		} while (way->date != nullptr || !way->right);
		*way = *head;

		for (int i = 0; i < h; i++)
		{
			way->right;
			way->weight = way->weight + A.weight;
		}
		way->right;
		if (way->left != nullptr)
		{
			way->right = &A;
			way->weight = way->weight + A.weight;
		}
		else
		{
			*way = *head;
			for (int i = 0; i < h; i++)
				way->right;
			POINT B = {};
			*B.left = *way->right;
			B.right = &A;
			way->right = &B;
			B.weight = B.left->weight + B.right->weight;
		}
		*way = *head;
	}
	
	void delete_(int key) {}
	
	char search_(int key) 
	{
		POINT * secret;
		char value;
		do
		{
			*way = *secret;
			if (way->left == nullptr && way->right == nullptr)
			{
				value = way->date[key];
				return date[key];
			}
			else 
			{
				if (way->left != nullptr && way->right != nullptr)
				{
					way->left;
					if (key >= way->weight)
						secret->left;
					else
						secret->right;
				}
				if (way->right == nullptr)
					secret->left;
				if (way->left == nullptr)
					secret->right;
			}
		} while (key == key);
	}
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
