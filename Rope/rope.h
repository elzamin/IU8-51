#pragma once
#include <string>


class Node
{
private:
	std::string *date;
	int weight;
	Node *left;
	Node *right;
public:
	Node()
	{
		date = nullptr;
		left = nullptr;
		right = nullptr;
		weight = 0;
	};

	Node(std::string *a)
	{
		weight = a->length();
		date = nullptr;
		right = nullptr;
		left = new Node();
		left->date = a;
		left->weight = a->length();
		left->left = nullptr;
		left->right = nullptr;
		std::cout << "+\nAdded new string: <" << *(a) << "> Weight: " << a->length() << std::endl;
	};

	/**
	*	Добавление новой строки в дерево.
	*	Новая строка добавляется правее предыдущих строк.
	*	Консоль информирует о добавлении строки, её содежимом и весе.
	*/
	void Add(std::string *a)
	{
		Node *ptr, *back;
		Node *newone = new Node();

		weight += a->length();
		back = ptr = this;
		newone->date = a;
		newone->weight = a->length();
		newone->left = nullptr;
		newone->right = nullptr;
		while (ptr->right && ptr->left)
		{
			back = ptr;
			ptr->right->weight += a->length();
			ptr = ptr->right;

		}
		if (ptr->date)
		{
			Node *knot = new Node();
			knot->left = ptr;
			knot->right = newone;
			knot->date = nullptr;
			knot->weight += ptr->weight;
			ptr->weight -= a->length();
			back->right = knot;
		}
		else
		{
			if (!ptr->left)
				ptr->left = newone;
			else
				ptr->right = newone;
		}
		//ptr->weight += a->length();
		back = ptr = nullptr;
		std::cout << "+\nAdded new string: <" << *(a) << "> Weight: " << a->length() << std::endl;
	}

	/**
	*	Вывод всех строк из дерева.
	*	Вывод в консоль по порядку слева-направо.
	*/

	void PrintString()
	{
		std::cout << "\nResult:\nTotal weight: " << weight << std::endl;
		if (!(this->date) && !(this->left) && !(this->right))
		{
			std::cout << "\nRope is empty" << std::endl;
			return;
		}
		else
			Printhelper(this);
		std::cout << std::endl << std::endl;
	}

	void Printhelper(Node *temp)
	{
		if (temp == nullptr)
		{
			return;
		}
		if (temp->date)
			std::cout << *(temp->date);
		Printhelper(temp->left);
		Printhelper(temp->right);

	}

	/**
	*	Поиск строки из дерева.
	*	Принимает значение key, далее через сравнение с weight находит и передаёт нужную строку.
	*/
	std::string SearchStr(int key)
	{
		Node *ptr = this;

		if (key > weight)
			return "error #1: key > weight";
		while ((weight - ptr->right->weight) < key && (ptr->right->right != nullptr))
			ptr = ptr->right;
		if (weight - ptr->weight + ptr->left->weight <= key)
			return *(ptr->right->date);
		else
			return *(ptr->left->date);
	}

	/**
	*	Поиск символа из дерева.
	*	Принимает значение key, далее через сравнение с weight находит и передаёт нужную строку.
	*/
	char SearchChar(int key)
	{

	}

	/**
	*	Удаление строки из дерева.
	*	Принимает значение key, далее через сравнение с weight находит и удаляет нужную строку.
	*	Консоль информирует об удалении строки и её содежимом.
	*/
	void DeleteOne(int key)
	{
		Node *ptr = this;
		int i = 0, dweight;

		if (key > weight)
		{
			std::cout << "error #1: key > weight" << std::endl;
			return;
		}
		while ((weight - ptr->right->weight) < key && (ptr->right->right != nullptr))
		{
			ptr = ptr->right;
			i++;
		}
		if (weight - ptr->weight + ptr->left->weight <= key)
			dweight = ptr->right->weight;
		else
			dweight = ptr->left->weight;
		ptr = this;
		for (i; i != 0; i--)
		{
			ptr->weight -= dweight;
			ptr = ptr->right;
		}
		ptr->weight -= dweight;
		if (weight - ptr->weight + ptr->left->weight <= key)
			ptr->right->DeleteHelper();
		else
			ptr->left->DeleteHelper();
	}

	void DeleteHelper()
	{
		std::cout << "-\nDeleted string: <" << *(date) << ">\n";
		date = nullptr;
		left = right = nullptr;
		weight = 0;
	}

	~Node()
	{
		left->~Node();
		right->~Node();
		left = right = nullptr;
		date = nullptr;
		weight = 0;
	}
};
