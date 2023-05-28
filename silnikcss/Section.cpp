#include "Section.h"

Section::Section()
	: next(nullptr), prev(nullptr), blocksArr{nullptr}, blocksSize(0)
{
}

Section::~Section()
{
}

void Section::append(Block* block)
{
	int firstFree = T - 1;
	for (int i = T - 1; i >= 0; i--) {
		if (blocksArr[i] != nullptr) {
			break;
		}

		firstFree = i;
	}

	blocksArr[firstFree] = block;

	blocksSize++;
}

void Section::remove(Block* block)
{
	for (int i = 0; i < T; i++) {
		if (blocksArr[i] == block) {
			blocksArr[i] = nullptr;
		}
	}

	blocksSize--;
}
