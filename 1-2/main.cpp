//  Exercise 1 - 2: Build further on the result of Exercise 1 - 1 and add an enumeration data member
//  title to Employee to specify whether a certain employee is a Manager, Senior Engineer,
//  or Engineer.Which kind of enumeration type will you use and why ? Whatever you need to
//  add, add it to the HR namespace.Test your new Employee data member in the main() function.
//  Use a switch statement to print out a human - readable string for the title.

#include <iostream>
#include <format>

namespace HR
{
    struct Employee {
        char firstInitial;
        char lastInitial;
        int employeeNumber;
        int salary;
        enum
        {
            Manager = 0,
            SeniorEngineer,
            Engineer
        } title;
    };
}

using namespace std;

std::string GetTitleText(const HR::Employee&);

int main()
{
    HR::Employee anEmployee {
        .firstInitial = 'J',
            .lastInitial = 'D',
            .employeeNumber = 42,
            .salary = 80000,
            .title = HR::Employee::Manager
    };

    cout << format("Employee: {}{}", anEmployee.firstInitial, anEmployee.lastInitial) << endl;
    cout << format("Number: {}", anEmployee.employeeNumber) << endl;
    cout << format("Salary: ${}", anEmployee.salary) << endl;
    cout << format("Title: {}", GetTitleText(anEmployee)) << endl;

    return 0;
}

std::string GetTitleText(const HR::Employee& employee)
{
    switch (employee.title)
    {
    case HR::Employee::Manager:
    {
        return "Manager";
    }
    case HR::Employee::SeniorEngineer:
    {
        return "Senior Engineer";
    }
    case HR::Employee::Engineer:
    {
        return "Engineer";
    }
    default:
    {
        return "Unknown";
    }
    }
}
