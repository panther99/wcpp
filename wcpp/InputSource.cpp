#include <iostream>
#include <string>

#include "InputSource.h"

unsigned int InputSource::bytes_count() const
{
	std::string line;
	std::getline(*_istream, line);
	_istream->clear();
	_istream->seekg(0);
	return line.length();
}

bool InputSource::empty() const
{
	std::string line;
	std::getline(*_istream, line);
	_istream->clear();
	_istream->seekg(0);
	return line.empty();
}
