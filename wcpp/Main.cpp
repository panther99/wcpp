#include <iostream>

#include "args.h"

int main(int argc, char* argv[])
{
	args::ArgParser parser("Usage: wcpp [-clmw] [file ...]", "1.0");

	std::string output;
	std::string flags[] = { "c", "l", "w", "m" };

	parser.flag("c");
	parser.flag("l");
	parser.flag("w");
	parser.flag("m");

	parser.parse(argc, argv);

	for (std::string flag : flags)
	{
		if (parser.found(flag))
		{
			std::cout << "Found option " << flag << "." << std::endl;
		}
	}
	
	return 0;
}
