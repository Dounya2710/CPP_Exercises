#include "Person.hpp"

Person::Person() : first_name(""), surname("") {}

std::string Person::getFirstName() const
{
    return first_name;
}

std::string Person::getSurname() const
{
    return surname;
}