#pragma once

#include <istream>

class InputManager
{
protected:
	std::istream* _istream;

public:
	InputManager(std::istream* istream) : _istream(istream) {}

	virtual unsigned int bytes_count() const = 0;
	unsigned int words_count() const;
	unsigned int lines_count() const;
	unsigned int chars_count() const;
};
