//  Exercise 1 - 3: Use an std::array to store three Employee instances from Exercise 1 - 2
//  with different data.Subsequently, use a range - based for loop to print out the employees in
//  the array.

#include <iostream>
#include <format>
#include <array>

namespace HR
{
    struct Employee
	{
        enum class title_t
        {
            Manager = 0,
            SeniorEngineer,
            Engineer
        };

        char firstInitial;
        char lastInitial;
        int employeeNumber;
        int salary;
        title_t title;
    };
}

std::string GetTitleText(const HR::Employee&);

int main()
{
    const std::array<HR::Employee, 3> employees = {
        HR::Employee{
            .firstInitial = 'J',
            .lastInitial = 'D',
            .employeeNumber = 42,
            .salary = 100000,
            .title = HR::Employee::title_t::Manager
        },
        HR::Employee{
            .firstInitial = 'A',
            .lastInitial = 'B',
            .employeeNumber = 43,
            .salary = 80000,
            .title = HR::Employee::title_t::SeniorEngineer
        },
        HR::Employee{
            .firstInitial = 'O',
            .lastInitial = 'J',
            .employeeNumber = 45,
            .salary = 60000,
            .title = HR::Employee::title_t::Engineer
        }
    };

    for (const auto& employee : employees)
    {
        std::cout << std::format("Employee: {}{}", employee.firstInitial, employee.lastInitial) << std::endl;
        std::cout << std::format("Number: {}", employee.employeeNumber) << std::endl;
        std::cout << std::format("Salary: ${}", employee.salary) << std::endl;
        std::cout << format("Title: {}", GetTitleText(employee)) << std::endl;
    }

    return 0;
}

std::string GetTitleText(const HR::Employee& employee)
{
    switch (employee.title)
    {
	    case HR::Employee::title_t::Manager:
	    {
	        return "Manager";
	    }
	    case HR::Employee::title_t::SeniorEngineer:
	    {
	        return "Senior Engineer";
	    }
	    case HR::Employee::title_t::Engineer:
	    {
	        return "Engineer";
	    }
	    default:
	    {
	        return "Unknown";
	    }
    }
}
