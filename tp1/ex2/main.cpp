#include <iostream>
#include <string>
#include "Person.hpp"

int main () {
    //Person person;
    /*person.first_name = "Palluche";
    person.surname = "La Faluche";
    std::cout << "La personne s'appelle " << person.first_name << " " << person.surname << std::endl;*/

    /*person.setFirstName("Palluche");
    person.setSurname("La Faluche");

    std::cout << "La personne s'appelle " << person.getFirstName() << " " << person.getSurname() << std::endl;*/

    std::cout << "Nombre de personnes: ";
    int numberOfPeople;
    std::cin >> numberOfPeople;

    Person* peopleArray = new Person[numberOfPeople];

    for (int i = 0; i < numberOfPeople; ++i)
    {
        std::cout << "Prenom: ";
        std::string firstName;
        std::cin >> firstName;
        peopleArray[i].setFirstName(firstName);

        std::cout << "Nom: ";
        std::string surName;
        std::cin >> surName;
        peopleArray[i].setSurname(surName);
    }

    std::cout << "Les personnes sont ";
    for (int i = 0; i < numberOfPeople; ++i)
    {
        std::cout << peopleArray[i].getFirstName() << " " << peopleArray[i].getSurname();
        if (i < numberOfPeople - 1)
            std::cout << ", ";
    }
    std::cout << "." << std::endl;

    delete[] peopleArray;

    return 0;
}

/* Compilation avec:
g++ -c Person.cpp
g++ main.cpp Person.o -o person

Exécution avec ./person
*/