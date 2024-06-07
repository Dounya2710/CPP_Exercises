#include "Stack.hpp"
#include <iostream>

int main() {
    Stack<int> intStack;

    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    // Tester le retrait d'éléments de la pile
    std::cout << "Top element is: " << intStack.pop() << std::endl; // Devrait afficher 3
    std::cout << "Top element is: " << intStack.pop() << std::endl; // Devrait afficher 2
    std::cout << "Top element is: " << intStack.pop() << std::endl; // Devrait afficher 1

    // Tester la vérification si la pile est vide
    if (intStack.isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
    }

    // Tester une pile de chaînes de caractères
    Stack<std::string> stringStack;
    stringStack.push("hello");
    stringStack.push("world");

    std::cout << "Top element is: " << stringStack.pop() << std::endl; // Devrait afficher "world"
    std::cout << "Top element is: " << stringStack.pop() << std::endl; // Devrait afficher "hello"

    return 0;
}