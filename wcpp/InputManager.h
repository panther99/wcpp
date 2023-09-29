#pragma once

#include <istream>

class InputManager
{
protected:
	std::istream* _istream;
	bool _is_file;

public:
	InputManager(std::ifstream* ifstream) : _istream((std::istream*) ifstream), _is_file(true) {}

	InputManager(std::istream* istream) : _istream(istream), _is_file(false) {}

	~InputManager()
	{
		if (_is_file)
			delete _istream;
	}

	virtual unsigned int bytes_count() const = 0;
	unsigned int words_count() const;
	unsigned int lines_count() const;
	unsigned int chars_count() const;
};
