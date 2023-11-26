//	Exercise 2 - 1: Write a program that asks the user for two strings and then prints them out
//	in alphabetical order, using the three - way comparison operator. To ask the user for a string,
//	you can use the std::cin stream, briefly introduced in Chapter 1. Chapter 13, "Demystifying
//	C++ I / O, " explains input and output in detail, but for now, here is how to read in a string
//	from the console.To terminate the line, just press Enter.
//	
//	std::string s;
//	getline(cin, s1);

#include <iostream>
#include <string>


int main(int argc, char** argv)
{
	std::string s1, s2;

	std::cout << "String A: ";
	std::getline(std::cin, s1);
	std::cout << "String B: ";
	std::getline(std::cin, s2);

	auto result = s1 <=> s2;

	std::cout << "Alphabetical ordering:" << std::endl;

	if (std::is_lt(result))
	{
		std::cout << s1 << std::endl << s2 << std::endl;
	}
	else
	{
		std::cout << s2 << std::endl << s1 << std::endl;
	}

	return 0;
}
