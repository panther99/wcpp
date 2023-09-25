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

bool File::exists(const std::string& path)
{
	return std::filesystem::exists(path);
}

unsigned int File::bytes_count()
{
	return std::filesystem::file_size(_path);
}

unsigned int File::words_count()
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

	return word_counter;
}

unsigned int File::lines_count()
{
	unsigned int line_counter = 0;

	std::ifstream input_file(_path);

	for (std::string line; std::getline(input_file, line); )
	{
		line_counter++;
	}

	return line_counter;
}

unsigned int File::chars_count()
{
	unsigned int char_counter = 0;

	std::ifstream input_file(_path);

	for (std::string line; std::getline(input_file, line); )
	{
		char_counter += line.length();
	}

	return char_counter;
}
