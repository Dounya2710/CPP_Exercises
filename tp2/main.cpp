#include "Card.hpp"

int main() {
    // Test print
    Card c1 { 8, "Pique" };
    std::cout << c1 << std::endl; // Should print "8 de Pique"

    // Test const print
    const Card c2 { 8, "Carreau" };
    std::cout << c2 << std::endl; // Should print "8 de Carreau"

    // Test equality operator
    Card c3 { 10, "Carreau" };
    std::cout << (c2 == c1) << std::endl; // Should print 1
    std::cout << (c2 == c3) << std::endl; // Should print 0

    // Test less than operator
    std::cout << (c1 < c2) << std::endl; // Should print 0
    std::cout << (c1 < c3) << std::endl; // Should print 1
    std::cout << (c3 < c1) << std::endl; // Should print 0

    return 0;
}