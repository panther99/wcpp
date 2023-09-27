#include <iostream>
#include <sstream>
#include <string>
#include <format>
#include <map>

#include "args.h"
#include "InputSource.h"
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
			passed_flags.push_back((Flag)flags[i]);
		}
	}

	if (parser.args.size() == 0)
	{
		std::stringstream i;
		i << std::cin.rdbuf();
		i.seekg(0);

		InputSource std_input(i);

		for (Flag passed_flag : passed_flags)
		{
			switch (passed_flag)
			{
			case Flag::Bytes:
			{
				auto count = std_input.bytes_count();
				sums[Flag::Bytes] += count;
				break;
			}
			case Flag::Chars:
			{
				auto count = std_input.chars_count();
				sums[Flag::Chars] += count;
				break;
			}
			case Flag::Lines:
			{
				auto count = std_input.lines_count();
				sums[Flag::Lines] += count;
				break;
			}
			case Flag::Words:
			{
				auto count = std_input.words_count();
				sums[Flag::Words] += count;
				break;
			}
			}
		}
	}
	else
	{
		for (std::string arg : parser.args)
		{
			if (File::exists(arg))
			{
				output.append("\t");

				File file(arg);

				for (Flag passed_flag : passed_flags)
				{
					switch (passed_flag)
					{
					case Flag::Bytes:
					{
						auto count = file.bytes_count();
						output.append(std::format("{}\t", count));
						sums[Flag::Bytes] += count;
						break;
					}
					case Flag::Chars:
					{
						auto count = file.chars_count();
						output.append(std::format("{}\t", count));
						sums[Flag::Chars] += count;
						break;
					}
					case Flag::Lines:
					{
						auto count = file.lines_count();
						output.append(std::format("{}\t", count));
						sums[Flag::Lines] += count;
						break;
					}
					case Flag::Words:
					{
						auto count = file.words_count();
						output.append(std::format("{}\t", count));
						sums[Flag::Words] += count;
						break;
					}
					}
				}

				output.append(std::format("{}\n", file.name()));
			}
		}
	}

	output.append("\t");

	for (Flag passed_flag : passed_flags)
	{
		output.append(std::format("{}\t", sums[passed_flag]));
	}

	if (parser.args.size() > 0)
	{
		output.append("total");
	}

	std::cout << output << std::endl;
}
