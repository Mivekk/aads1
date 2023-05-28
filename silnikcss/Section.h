#pragma once
#define T 8
#include <iostream>
#include "Block.h"

class Section
{
public:
	Section();
	~Section();

	void append(Block* block);
	void remove(Block* block);

	Block* blocksArr[T];
	Section* next, * prev;

	std::size_t blocksSize;
};

