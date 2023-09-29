#pragma once

#include <istream>

class InputManager
{
private:
	const bool _is_file;

protected:
	std::istream* _istream;

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
