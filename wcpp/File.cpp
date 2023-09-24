#include <string>
#include <optional>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <cwctype>

#include "File.h"

File::File(const std::string& path) : _path(path) {}

std::string File::name() const
{
	return _path.substr(_path.find_last_of("/\\") + 1);
}

FileProperties File::properties() const
{
	return _properties;
}

void File::calculate_bytes()
{
	_properties.bytes = std::filesystem::file_size(_path);
}

void File::calculate_words()
{
	unsigned int word_counter = 0;

	std::ifstream input_file(_path);

	for (std::string line; std::getline(input_file, line); )
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

	_properties.words = word_counter;
}

void File::calculate_lines()
{
	unsigned int line_counter = 0;

	std::ifstream input_file(_path);

	for (std::string line; std::getline(input_file, line); )
	{
		line_counter++;
	}

	_properties.lines = line_counter;
}

void File::calculate_chars()
{
	unsigned int char_counter = 0;

	std::ifstream input_file(_path);

	for (std::string line; std::getline(input_file, line); )
	{
		char_counter += line.length();
	}

	_properties.chars = char_counter;
}
