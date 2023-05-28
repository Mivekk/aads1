#pragma once
#include "String.h"

class Selector
{
public:
	Selector();
	Selector(const String& name);
	Selector(String&& name) noexcept;
	~Selector();

	String name;
	Selector* next, * prev;
};

