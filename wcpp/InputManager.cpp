#include <string>
#include <optional>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <cwctype>
#include <iostream>

#include "InputManager.h"

unsigned int InputManager::words_count() const
{
	unsigned int word_counter = 0;

	for (std::string line; std::getline(*_istream, line); )
	{
		const char* current_char = line.c_str();

		bool insideWhitespaces = true;

		while (*current_char != '\0')
		{
			if (std::iswspace(*current_char))
			{
				insideWhitespaces = true;
			}
			else if (insideWhitespaces)
			{
				word_counter++;
				insideWhitespaces = false;
			}

			++current_char;
		}
	}

	_istream->clear();
	_istream->seekg(0);

	return word_counter;
}

unsigned int InputManager::lines_count() const
{
	unsigned int line_counter = 0;

	for (std::string line; std::getline(*_istream, line); )
	{
		line_counter++;
	}

	_istream->clear();
	_istream->seekg(0);

	return line_counter;
}

unsigned int InputManager::chars_count() const
{
	unsigned int char_counter = 0;

	for (std::string line; std::getline(*_istream, line); )
	{
		char_counter += line.length();
	}

	_istream->clear();
	_istream->seekg(0);

	return char_counter;
}
