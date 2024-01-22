#include <iostream>
#include <string>
#include "Person.hpp"

int main () {
    Person person;
    person.first_name = "Palluche";
    person.surname = "La Faluche";
    std::cout << "La personne s'appelle " << person.first_name << " " << person.surname << std::endl;
    return 0;
}