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

void Person::setFirstName(const std::string& firstName)
{
    first_name = firstName;
}

void Person::setSurname(const std::string& surName)
{
    surname = surName;
}