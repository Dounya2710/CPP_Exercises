#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>

enum class CardValue { As, Deux, Trois, Quatre, Cinq, Six, Sept, Huit, Neuf, Dix, Valet, Dame, Roi };
enum class CardColor { Pique, Coeur, Carreau, Trefle };

class Card {
private:
    CardValue _value;
    CardColor _color;

public:
    Card(CardValue value, CardColor color);
    bool operator==(const Card& other) const;
    bool operator<(const Card& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
    void print() const;
};

#endif