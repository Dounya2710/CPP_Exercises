#include "Card.hpp"

Card::Card(int value, const std::string& color) : _value(value >= 0 ? value : 0), _color(color) {}

bool Card::operator==(const Card& other) const {
    return _value == other._value;
}

bool Card::operator<(const Card& other) const {
    return _value < other._value;
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
    const char* values[] = {"As", nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, "Valet", "Dame", "Roi"};
    
    os << (values[card._value] ? values[card._value] : std::to_string(card._value)) << " de " << card._color;
    return os;
}