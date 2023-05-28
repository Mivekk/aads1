#pragma once
#include "Selector.h"

class SelectorList
{
public:
	SelectorList();
	~SelectorList();

	Selector* head, * tail;

	Selector* find(const String& s);
	void add(Selector* selector);

	std::size_t size;
};

