#include <iostream>
#include <string>
#include <vector>
#include "Person.hpp"

int main () {
    //Person person;
    /*person.first_name = "Palluche";
    person.surname = "La Faluche";
    std::cout << "La personne s'appelle " << person.first_name << " " << person.surname << std::endl;*/

    /*person.setFirstName("Palluche");
    person.setSurname("La Faluche");

    std::cout << "La personne s'appelle " << person.getFirstName() << " " << person.getSurname() << std::endl;*/

    std::cout << "Nombre de personnes : ";
    int numPeople;
    std::cin >> numPeople;

    std::vector<Person> peopleArray;

    for (int i = 0; i < numPeople; ++i)
    {
        std::string firstName, surName;
        std::cout << "Prenom : ";
        std::cin >> firstName;

        std::cout << "Nom : ";
        std::cin >> surName;

        peopleArray.push_back({firstName, surName});
    }

    std::cout << "Les personnes sont ";
    for (const auto& person : peopleArray)
    {
        std::cout << person.getFirstName() << " " << person.getSurname();

        if (&person != &peopleArray.back())
            std::cout << ", ";
    }
    std::cout << "." << std::endl;

    return 0;
}

/* Compilation avec:
g++ -c Person.cpp
g++ main.cpp Person.o -o person

Exécution avec ./person
*/