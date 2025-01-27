#pragma once

#include "Employee.hpp"

#include <list>
#include <string>
#include <iostream>

class Department
{
public:
    Department(const std::string& name)
        : _name { name }
    {}

    Employee& add_employee(const std::string& name, unsigned int salary, Employee* manager)
    {
        auto& employee = _employees.emplace_back(name, salary);

        if (manager != nullptr)
        {
            manager->add_subordinate(employee);
        }

        return employee;
    }

    void print_employees() const {
        for(const auto& e: _employees) {
            std::cout << e << std::endl;
        }
    }

    std::list<Employee> get_employee() const {
        return _employees;
    }

    std::string getName() const {
        return _name;
    }


private:
    std::string _name;
    std::list<Employee> _employees;
};
