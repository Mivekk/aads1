#include "AttributeList.h"

AttributeList::AttributeList()
	: head(nullptr), tail(nullptr), size(0)
{
}

AttributeList::~AttributeList()
{
	Attribute* attribute = head;
	while (attribute != nullptr) {
		Attribute* nextAttribute = attribute->prev;
		delete attribute;
		attribute = nextAttribute;
	}
}

Attribute* AttributeList::find(const String& s)
{
	Attribute* attribute = head;
	while (attribute != nullptr) {
		if (attribute->name == s) {
			return attribute;
		}
		attribute = attribute->prev;
	}

	return nullptr;
}

void AttributeList::add(Attribute* attribute)
{
	size++;

	if (head == nullptr) {
		head = attribute;
		tail = attribute;
		return;
	}

	tail->prev = attribute;
	attribute->next = tail;
	tail = attribute;
}

void AttributeList::remove(Attribute* attribute) 
{
	size--;

	if (head == attribute) {
		if (tail == attribute) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			head = attribute->prev;
		}
	}
	else if (tail == attribute) {
		tail = attribute->next;
	}
	else {
		Attribute* prevAttribute = attribute->prev;
		Attribute* nextAttribute = attribute->next;

		nextAttribute->prev = prevAttribute;
		prevAttribute->next = nextAttribute;

		delete attribute;
		attribute = nullptr;
	}
}
