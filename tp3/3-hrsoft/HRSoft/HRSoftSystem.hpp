#pragma once

#include "Department.hpp"

#include <list>
#include <string>
#include <iostream>

class HRSoftSystem
{
public:
    Department& add_department(const std::string& name)
    {
        return _departments.emplace_back(name);
    }

    void print_all_departments() const {
        for(const auto& d: _departments) {
            std::cout << d.getName() << std::endl;
        }
    }

    void print_all_employees() const {
        for(const auto& d: _departments) {
            d.print_employees();
        }
    }

    void remove_employee(Employee& employee_name) {
        for(const auto& dep: _departments) {
            auto& employees = dep.get_employee();
            for(auto& it = employees.begin(); it != employees.end(); ++it) {
                if(it->getName() == &employee_name.getName()) {
                    employees._subordinates.pop_back();
                }
            }
        }
    }

private:
    std::list<Department> _departments;
};
