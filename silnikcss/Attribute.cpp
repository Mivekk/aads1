#include "Attribute.h"

Attribute::Attribute()
	: name(""), value(""), next(nullptr), prev(nullptr)
{
}

Attribute::Attribute(const String& name, const String& value)
	: name(name), value(value), next(nullptr), prev(nullptr)
{
}

Attribute::Attribute(String&& name, String&& value)
	: name((String&&)name), value((String&&)value), next(nullptr), prev(nullptr)
{
}

Attribute::~Attribute()
{
}
