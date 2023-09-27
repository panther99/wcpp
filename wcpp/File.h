#pragma once

#include <string>
#include <optional>
#include <fstream>
#include <istream>

#include "InputManager.h"

class File : public InputManager
{
private:
	std::string _path;

public:
	File(const std::string& path) :
		_path(path),
		InputManager(new std::ifstream(path)) {};

	std::string name() const;
	static bool exists(const std::string& path);
	unsigned int bytes_count() const;
};
