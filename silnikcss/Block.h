#pragma once
#include "SelectorList.h"
#include "AttributeList.h"

class Block
{
public:
	Block();
	Block(SelectorList* selectorList, AttributeList* attributeList);
	~Block();

	SelectorList* selectorList;
	AttributeList* attributeList;
};

