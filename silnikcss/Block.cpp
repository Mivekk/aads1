#include "Block.h"

Block::Block()
	: selectorList(new SelectorList), attributeList(new AttributeList)
{
}

Block::Block(SelectorList* selectorList, AttributeList* attributeList)
	: selectorList(selectorList), attributeList(attributeList)
{
}

Block::~Block()
{
	delete selectorList, attributeList;
}
