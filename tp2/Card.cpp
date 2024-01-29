#include "Card.hpp"

Card::Card(CardValue value, CardColor color) : _value(value), _color(color) {}

bool Card::operator==(const Card& other) const {
    return _value == other._value;
}

bool Card::operator<(const Card& other) const {
    return static_cast<int>(_value) < static_cast<int>(other._value);
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
    const char* values[] = {"As", "Deux", "Trois", "Quatre", "Cinq", "Six", "Sept", "Huit", "Neuf", "Dix", "Valet", "Dame", "Roi"};
    const char* colors[] = {"Pique", "Coeur", "Carreau", "Trefle"};

    os << values[static_cast<int>(card._value)] << " de " << colors[static_cast<int>(card._color)];
    return os;
}

void Card::print() const {
    std::cout << *this;
}