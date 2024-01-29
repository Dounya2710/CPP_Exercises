#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>

class Card {
private:
    int _value;
    std::string _color;

public:
    Card(int value, const std::string& color);
    bool operator==(const Card& other) const;
    bool operator<(const Card& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
};

#endif