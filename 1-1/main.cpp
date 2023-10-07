//  Exercise 1 - 1: Modify the Employee structure from the beginning of this chapter by putting it
//  in a namespace called HR.What modifications do you have to make to the code in main() to
//  work with this new implementation ? Additionally, modify the code to use C++20 designated
//  initializers.

#include <iostream>
#include <format>

namespace HR
{
    struct Employee
	{
        char firstInitial;
        char lastInitial;
        int employeeNumber;
        int salary;
    };
}

int main()
{
    HR::Employee anEmployee {
    	.firstInitial = 'J',
    	.lastInitial = 'D',
    	.employeeNumber = 42,
    	.salary = 80000
    };

    std::cout << std::format("Employee: {}{}", anEmployee.firstInitial, anEmployee.lastInitial) << std::endl;
    std::cout << std::format("Number: {}", anEmployee.employeeNumber) << std::endl;
    std::cout << std::format("Salary: ${}", anEmployee.salary) << std::endl;

    return 0;
}
