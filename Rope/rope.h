#pragma once
#include "Node.h"
#include <string>

class Rope
{
private:
	Node *root;
public:
	Rope()
		:root(nullptr)
	{
		std::cout << "----------------<\nCreated new rope\n";
	};

	Rope(std::string *a)
	{
		Node *newnode = new Node();
		root = newnode;
		root->date = a;
		int wght = a->length();
		newnode->weight = wght;
		/*newnode->left = nullptr;
		newnode->right = nullptr;*/
		std::cout << "----------------<\nCreated new rope\n";
		std::cout << "+\nAdded new string: \n<" << *(newnode->date) << ">\nWeight: " << newnode->date->length() << std::endl;
	};
	
	/** 
	*	Добавление новой строки в дерево.
	*	Новая строка добавляется правее предыдущих строк.
	*	Консоль информирует о добавлении строки, её содежимом и весе.
	*/
	void Add(std::string *a)
	{
		Node *newnode = new Node();
		Node *ptr;
		Node *back;
		int wght = a->length();;
		newnode->date = a;
		newnode->weight = wght;
		if (!root)
			root = newnode;
		back = ptr = root;
		while (!ptr->right || !ptr->left)
			back = ptr;
			ptr->right;
		if (ptr->date != nullptr)
		{
			Node *knot = new Node();
			knot->left = ptr;
			knot->right = newnode;
			knot->date = nullptr;
			back->right = knot;
			back = ptr = nullptr;
		}
		else
		{
			if (!ptr->right && ptr->left != nullptr)
				ptr->right = newnode;
			else
				ptr->left = newnode;
		}
		std::cout << "+\nAdded new string: \n<"<< *(newnode->date) << ">\nWeight: " <<newnode->date->length() << std::endl;
	}

	/**
	*
	*
	*/
	void Print() 
	{
		if (!root)
			std::cout << "Rope is empty\n";
		else
		{
			Node* a = root;

			Printhelper(a);
		}
	};
	void Printhelper(Node *node)
	{
		if (!node)
			return;
		if (node->left != nullptr)
			Printhelper(node->left);
		if (node->right != nullptr)
			Printhelper(node->right);
		if (!node->date)
			std::cout << '* ';
		else
			std::cout << *(node->date) << ' ';
	}
	void Check()
	{
		std::cout << root->weight << *(root->date);
		/*std::cout << root->left;
		root->left = nullptr;
		std::cout << root->left;
		*/
	}
	/**
	*	
	*	
	*/

	~Rope()
	{
		//delete
	}
};

void Print(Node *node)
{
	if (!node || node->itstr == 0)
		return;
	Print(node->left);
	Print(node->right);
	if (node->itstr == 0)
		std::cout << '* ';
	else
		std::cout << *(node->date) << ' ';
}
