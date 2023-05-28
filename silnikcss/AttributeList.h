#pragma once
#include "Attribute.h"

class AttributeList
{
public:
	AttributeList();
	~AttributeList();

	Attribute* head, * tail;

	Attribute* find(const String& s);
	void add(Attribute* attribute);
	void remove(Attribute* attribute);

	std::size_t size;
};

