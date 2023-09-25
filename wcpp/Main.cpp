#include <iostream>
#include <string>
#include <format>
#include <map>

#include "args.h"
#include "File.h"
#include "Flag.h"

int main(int argc, char* argv[])
{
	args::ArgParser parser("Usage: wcpp [-clmw] [file ...]", "1.0");

	std::string output;
	char flags[] = { 'c', 'l', 'w', 'm' };
	std::vector<Flag> passed_flags;

	parser.flag("c");
	parser.flag("l");
	parser.flag("w");
	parser.flag("m");

	parser.parse(argc, argv);

	for (int i = 0; i < sizeof(flags); i++)
	{
		if (parser.found(std::format("{}", flags[i])))
		{
			passed_flags.push_back((Flag) flags[i]);
		}
	}

	for (std::string arg : parser.args)
	{
		if (File::exists(arg))
		{
			File f(arg);
			output.append("\t");

			for (Flag passed_flag : passed_flags)
			{
				switch (passed_flag)
				{
				case Flag::Bytes:
					output.append(std::format("{}\t", f.bytes_count()));
					break;
				case Flag::Chars:
					output.append(std::format("{}\t", f.chars_count()));
					break;
				case Flag::Lines:
					output.append(std::format("{}\t", f.lines_count()));
					break;
				case Flag::Words:
					output.append(std::format("{}\t", f.words_count()));
					break;
				}
			}

			output.append(std::format("{}\n", f.name()));
		}
	}

	std::cout << output << std::endl;

	return 0;
}
