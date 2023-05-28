#pragma once
#include "Section.h"

class SectionList
{
public:
	Section* head, * tail;

	SectionList();
	~SectionList();

	void add(Section* section);
	void remove(Section* section);

	std::size_t size;
};

