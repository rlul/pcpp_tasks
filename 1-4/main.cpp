//  Exercise 1 - 4: Do the same as Exercise 1 - 3, but use an std::vector instead of an array, and
//  use push_back() to insert elements into the vector.

#include <iostream>
#include <format>
#include <vector>

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
    vector<HR::Employee> employees;

    employees.push_back(HR::Employee{
        .firstInitial = 'J',
            .lastInitial = 'D',
            .employeeNumber = 42,
            .salary = 100000,
            .title = HR::Employee::Manager
    });
    employees.push_back(HR::Employee{
        .firstInitial = 'A',
            .lastInitial = 'B',
            .employeeNumber = 43,
            .salary = 80000,
            .title = HR::Employee::SeniorEngineer
    });
    employees.push_back(HR::Employee{
        .firstInitial = 'O',
            .lastInitial = 'J',
            .employeeNumber = 45,
            .salary = 60000,
            .title = HR::Employee::Engineer
    });

    for (const auto& employee : employees)
    {
        cout << format("Employee: {}{}", employee.firstInitial, employee.lastInitial) << endl;
        cout << format("Number: {}", employee.employeeNumber) << endl;
        cout << format("Salary: ${}", employee.salary) << endl;
        cout << format("Title: {}", GetTitleText(employee)) << endl;
    }

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
