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
	std::map<Flag, unsigned int> sums = {
		{ Flag::Bytes, 0 },
		{ Flag::Chars, 0 },
		{ Flag::Lines, 0 },
		{ Flag::Words, 0 }
	};

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
				{
					auto count = f.bytes_count();
					output.append(std::format("{}\t", count));
					sums[Flag::Bytes] += count;
					break;
				}
				case Flag::Chars:
				{
					auto count = f.chars_count();
					output.append(std::format("{}\t", count));
					sums[Flag::Chars] += count;
					break;
				}
				case Flag::Lines:
				{
					auto count = f.lines_count();
					output.append(std::format("{}\t", count));
					sums[Flag::Lines] += count;
					break;
				}
				case Flag::Words:
				{
					auto count = f.words_count();
					output.append(std::format("{}\t", count));
					sums[Flag::Words] += count;
					break;
				}
				}
			}

			output.append(std::format("{}\n", f.name()));
		}
	}

	output.append("\t");

	for (Flag passed_flag : passed_flags)
	{
		output.append(std::format("{}\t", sums[passed_flag]));
	}

	output.append("total");

	std::cout << output << std::endl;

	return 0;
}
