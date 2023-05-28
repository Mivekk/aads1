#define _CRT_SECURE_NO_WARNINGS
#include "String.h"

String::String()
	: m_string(new char[1]{0}), m_size(0)
{
}

String::String(const char* string)
{
	m_size = strlen(string);

	m_string = new char[m_size + 1];
	strcpy_s(m_string, m_size + 1, string);
	m_string[m_size] = '\0';
}

String::String(const String& other)
{
	m_size = other.m_size;

	char* tmp = new char[m_size + 1];
	strcpy(tmp, other.m_string);

	m_string = tmp;
}

String::String(String&& other) noexcept
{
	m_string = other.m_string;
	m_size = other.m_size;

	other.m_string = nullptr;
	other.m_size = 0;
}

String::~String()
{
	delete[] m_string;
}

std::size_t String::length() const
{
	return m_size;
}

int String::toInt() const
{
	return atoi(m_string);
}

String& String::trim()
{
	if (m_size == 0) {
		return *this;
	}

	// trim selector
	int lChar = 0, rChar = 0;
	// find atmost left char
	for (int i = 0; i < m_size; i++) {
		if (!isspace(m_string[i])) {
			lChar = i;
			break;
		}
	}
	// find atmost right char
	for (int i = m_size - 1; i >= 0; i--) {
		if (!isspace(m_string[i])) {
			rChar = i;
			break;
		}
	}
	// trim string
	String trimmed = "";
	for (int i = lChar; i <= rChar; i++) {
		trimmed += m_string[i];
	}

	m_size = trimmed.m_size;

	char* tmp = new char[m_size + 1];
	strcpy(tmp, trimmed.m_string);

	// swap elements
	auto el = tmp;
	tmp = m_string;
	m_string = el;

	delete[] tmp;

	return *this;
}

char& String::operator[](int idx)
{
	return m_string[idx];
}

char String::operator[](int idx) const
{
	return m_string[idx];
}

String& String::operator+=(String& other)
{
	m_size += other.m_size;
	char* tmp = new char[m_size + 1];

	strcpy(tmp, m_string);
	strcat(tmp, other.m_string);
		
	delete[] m_string;

	m_string = tmp;

	return *this;
}

String& String::operator+=(const char& other)
{
	m_size++;
	char* tmp = new char[m_size + 1];

	strcpy(tmp, m_string);
	tmp[m_size - 1] = other;
	tmp[m_size] = '\0';

	delete[] m_string;

	m_string = tmp;

	return *this;
}

String& String::operator=(const String& other)
{
	if (this != &other) {
		m_size = other.m_size;

		char* tmp = new char[m_size + 1];
		strcpy(tmp, other.m_string);

		// swap elements
		auto el = tmp;
		tmp = m_string;
		m_string = el;

		delete[] tmp;
	}

	return *this;
}

String& String::operator=(String&& other) noexcept
{
	if (this != &other) {
		delete[] m_string;

		m_string = other.m_string;
		m_size = other.m_size;

		other.m_string = nullptr;
		other.m_size = 0;
	}

	return *this;
}

bool String::operator==(const String& other) const
{
	if (m_string == nullptr) {
		return false;
	}

	return !strcmp(m_string, other.m_string);
}

bool String::operator==(const char* other) const
{
	if (m_string == nullptr) {
		return false;
	}

	return !strcmp(m_string, other);
}

std::ostream& operator<<(std::ostream& out, const String& string)
{
	// if exception is thrown out here probably you are trying
	// to access non-existent (String) object

	out << string.m_string;
	return out;
}

std::istream& operator>>(std::istream& in, String& string)
{
	char buffer[1024];
	in >> buffer;

	string = buffer;

	return in;
}
