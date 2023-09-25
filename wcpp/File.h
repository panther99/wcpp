#pragma once

#include <string>
#include <optional>

class File
{
private:
	std::string _path;

public:
	File(const std::string& path);

	std::string name() const;
	static bool exists(const std::string& path);

	unsigned int bytes_count();
	unsigned int words_count();
	unsigned int lines_count();
	unsigned int chars_count();
};
