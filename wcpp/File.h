#pragma once

#include <string>
#include <optional>

struct FileProperties
{
	std::optional<unsigned int> bytes;
	std::optional<unsigned int> words;
	std::optional<unsigned int> lines;
	std::optional<unsigned int> chars;
};

class File
{
private:
	std::string _path;
	FileProperties _properties;

public:
	File(const std::string& path);

	std::string name() const;
	FileProperties properties() const;

	void calculate_bytes();
	void calculate_words();
	void calculate_lines();
	void calculate_chars();
};
