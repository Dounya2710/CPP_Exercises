#include "Player.hpp"
#include <algorithm>
#include <random>

Player::Player(const std::string& name) : _name(name) {}

void Player::deal_all_cards(Player& p1, Player& p2) {
    std::vector<Card> all_cards;

    for (int value = 0; value < 13; ++value) {
        for (int color = 0; color < 4; ++color) {
            all_cards.emplace_back(static_cast<CardValue>(value), static_cast<CardColor>(color));
        }
    }

    std::random_device rd;
    std::shuffle(all_cards.begin(), all_cards.end(), std::default_random_engine(rd()));
    size_t half_size = all_cards.size() / 2;
    p1._cards.insert(p1._cards.end(), all_cards.begin(), all_cards.begin() + half_size);
    p2._cards.insert(p2._cards.end(), all_cards.begin() + half_size, all_cards.end());
}

const Card& Player::operator[](size_t index) const {
    if (index < _cards.size()) {
        return _cards[index];
    } else {
        throw std::out_of_range("Index out of bounds");
    }
}