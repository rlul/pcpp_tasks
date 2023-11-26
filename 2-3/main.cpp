//	Exercise 2 - 3: Modify the program from Exercise 2 - 2 and use std::string_view on as many
//	places as you can.

#include <iostream>
#include <string>

std::string replace_needles(std::string_view haystack, std::string_view needle, std::string_view replacement)
{
	std::string result{haystack};
	size_t pos = 0;

	while (pos != std::string::npos)
	{
		result.replace(pos, needle.length(), replacement);
		pos = result.find(needle, pos + needle.size());
	}

	return result;
}

int main(int argc, char** argv)
{
	std::string haystack, needle, replacement;

	std::cout << "Haystack: ";
	std::getline(std::cin, haystack);
	std::cout << "Needle: ";
	std::getline(std::cin, needle);
	std::cout << "Replacement: ";
	std::getline(std::cin, replacement);

	std::cout << "Result: " << replace_needles(haystack, needle, replacement);

	return 0;
}
