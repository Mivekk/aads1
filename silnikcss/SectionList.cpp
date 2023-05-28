#include "SectionList.h"

SectionList::SectionList()
	: head(nullptr), tail(nullptr), size(0)
{
}

SectionList::~SectionList()
{
	Section* section = head;
	while (section != nullptr) {
		Section* nextSection = section->prev;
		delete section;
		section = nextSection;
	}
}

void SectionList::add(Section* section)
{
	size++;

	if (head == nullptr) {
		head = section;
		tail = section;
		return;
	}

	tail->prev = section;
	section->next = tail;
	tail = section;
}

void SectionList::remove(Section* section)
{
	size--;

	if (head == section) {
		if (tail == section) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			head = section->prev;
		}
	}
	else if (tail == section) {
		tail = section->next;
	}
	else {
		Section* prevSection = section->prev;
		Section* nextSection = section->next;

		nextSection->prev = prevSection;
		prevSection->next = nextSection;

		delete section;
		section = nullptr;
	}
}
