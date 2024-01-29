#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Card.hpp"

class Player {
private:
    std::string _name;
    std::vector<Card> _cards;
    unsigned int _score{0};

public:
    Player(const std::string& name);
    static void deal_all_cards(Player& p1, Player& p2);
    const Card& operator[](size_t index) const;
    static int turn_number;
    static bool play(Player& p1, Player& p2);
    unsigned int getScore() const;
};

#endif 