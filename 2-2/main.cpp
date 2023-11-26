//	Exercise 2 - 2: Write a program that asks the user for a source string(= haystack), a string
//	to find(= needle) in the source string, and a replacement string.Write a function with
//	three parameters-the haystack, needle, and replacement string-that returns a copy of the
//	haystack with all needles replaced with the replacement string.Use only std::string, no
//	string_view.What kind of parameter types will you use and why ? Call this function from
//	main() and print out all the strings for verification.

#include <iostream>
#include <string>

std::string replace_needles(const std::string& haystack, const std::string& needle, const std::string& replacement)
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
