#include <iomanip>
#include <iostream>

int main()
{
    std::cout << "Entre ton nom: ";

    char name[20] = ""; // Si on lui passe au moins 20 caractères ou plus, 
    // il récupère les 20 caractères et rejette le reste car la mémoire ne peut stocker plus de 20 caractères
    std::cin >> std::setw(20) >> name;
    std::cout << "Bonjour " << name << " !" << std::endl;

    return 0;
}
