#pragma once
#include <string>

struct Node
{
	std::string *date;
	int weight;
	Node *left;
	Node *right;
	bool itstr;
	Node()
		: date(nullptr)
	{};
	Node(std::string *a)
		:date(a)
	{};
	~Node()
	{
		delete left, right, itstr, date, weight, this;
	};
};
