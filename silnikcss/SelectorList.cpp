#include "SelectorList.h"

SelectorList::SelectorList()
	: head(nullptr), tail(nullptr), size(0)
{
}

SelectorList::~SelectorList()
{
	Selector* selector = head;
	while (selector != nullptr) {
		Selector* nextSelector = selector->prev;
		delete selector;
		selector = nextSelector;
	}
}

Selector* SelectorList::find(const String& s)
{
	Selector* selector = head;
	while (selector != nullptr) {
		if (selector->name == s) {
			return selector;
		}
		selector = selector->prev;
	}

	return nullptr;
}

void SelectorList::add(Selector* selector)
{
	size++;

	if (head == nullptr) {
		head = selector;
		tail = selector;
		return;
	}

	tail->prev = selector;
	selector->next = tail;
	tail = selector;
} 
