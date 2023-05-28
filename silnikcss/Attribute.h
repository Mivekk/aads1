#pragma once
#include "String.h"

class Attribute
{
public:
	Attribute();
	Attribute(const String& name, const String& value);
	Attribute(String&& name, String&& value);
	~Attribute();

	String name, value;
	Attribute* next, * prev;
};

