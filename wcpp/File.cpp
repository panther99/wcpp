#include <filesystem>

#include "File.h"

std::string File::name() const
{
	return _path.substr(_path.find_last_of("/\\") + 1);
}

bool File::exists(const std::string& path)
{
	return std::filesystem::exists(path);
}

unsigned int File::bytes_count() const
{
	return std::filesystem::file_size(_path);
}
