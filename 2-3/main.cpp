//	Exercise 2 - 3: Modify the program from Exercise 2 - 2 and use std::string_view on as many
//	places as you can.

#include <iostream>
#include <string>
#include <sstream>
#include <format>

#define REPLACE_TEST(h, n, r, e)	\
	{	\
		std::string result = replace_needles(h, n, r);	\
		std::cout << std::format("{:s}: \"{}\" == \"{}\"", result == (e), result, e) << std::endl; \
	}	\

std::string replace_needles(std::string_view haystack, std::string_view needle, std::string_view replacement)
{
	std::stringstream result;
	size_t pos = 0;

	if (needle.empty())
	{
		return haystack.data();
	}

	while (pos < haystack.length()) {
		const size_t new_pos = haystack.find(needle, pos);

		if (new_pos == std::string::npos)
		{
			result << haystack.substr(pos);
			break;
		}

		result << haystack.substr(pos, new_pos - pos) << replacement;
		pos = new_pos + needle.length();
	}

	return result.str();
}

int main(int argc, char** argv)
{
	REPLACE_TEST("123 aa123 123aa", "123", "bbb", "bbb aabbb bbbaa");
	REPLACE_TEST("aaa123 123 aa123", "123", "bbb", "aaabbb bbb aabbb");

	REPLACE_TEST("123 aa123 123aa", "12", "bbb", "bbb3 aabbb3 bbb3aa");
	REPLACE_TEST("123 aa123 123aa", "123", "bb", "bb aabb bbaa");

	REPLACE_TEST("aaa123 123 aa123", "12", "bbb", "aaabbb3 bbb3 aabbb3");
	REPLACE_TEST("aaa123 123 aa123", "123", "bb", "aaabb bb aabb");

	REPLACE_TEST("123 aaa123 123123", "123", "bb", "bb aaabb bbbb");
	REPLACE_TEST("123 aaa123 123123", "12", "bbb", "bbb3 aaabbb3 bbb3bbb3");

	REPLACE_TEST("", "123", "bbb", "");
	REPLACE_TEST("123 aaa123 123123", "", "bbb", "123 aaa123 123123");
	REPLACE_TEST("123 aaa123 123123", "123", "", " aaa ");
	REPLACE_TEST("123 aaa123 123123", "123", "123", "123 aaa123 123123");

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
