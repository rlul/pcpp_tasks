//	Exercise 2 - 4: Write a program that asks the user to enter an unknown number of floatingpoint
//	numbers and stores all numbers in a vector.Each number should be typed followed by
//	Enter.Stop asking for more numbers when the user inputs the number 0. To read a floatingpoint
//	number from the console, use cin in the same way it was used in Chapter 1 to input
//	integer values.Format all numbers in a table with a couple of columns where each column
//	formats a number in a different way.Each row in the table corresponds to one of the inputted
//	numbers.

#include <format>
#include <iostream>
#include <vector>


int main(int argc, char** argv)
{
	std::vector<float> numbers;

	while (true)
	{
		float number;

		std::cin >> number;
		if (number == 0.f)
		{
			break;
		}
		numbers.push_back(number);
	}

	for (auto number : numbers)
	{
		std::cout << std::format("{0:6}|{0:<10}|{0:_^10}|{0:#020A}", number) << std::endl;
	}

	return 0;
}
