#include "Selector.h"

Selector::Selector()
	: name(""), next(nullptr), prev(nullptr)
{
}

Selector::Selector(const String& name)
	: name(name), next(nullptr), prev(nullptr)
{
}

Selector::Selector(String&& name) noexcept
	: name((String&&)name), next(nullptr), prev(nullptr)
{
}

Selector::~Selector()
{
}
